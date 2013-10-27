#ifndef EQUIPMENT_POOL_HPP
#define EQUIPMENT_POOL_HPP

#include "type_difinition.hpp"
#include <memory>
#include <list>
#include <algorithm>
#include <iterator>

namespace AIGame {

namespace Pool {
namespace detail {
	/**
	 * @see @link {http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Type_Generator} 
	 * for detail
	 */
	// the container type
	template <typename T>
	struct container {
		typedef std::list<T> type;
	};
	// the resource type
	template <typename T>
	struct rc_type {
		typedef std::unique_ptr<T> type;
	};
} // detail
}

using Pool::detail::rc_type;
using Pool::detail::container;

/**
 * this class provides an iterator for ItemPool.
 * this class makes iterator acts like container<T>::iterator
 */
template <typename T>
class Iterator : public 
	std::iterator<std::input_iterator_tag, typename rc_type<T>::type> {
// forward typedef
private:
	typedef typename rc_type<T>::type rc_type;
	typedef typename container<typename rc_type>::type container;
public:
	Iterator(const typename container::iterator& rhs) {
		iter = rhs;
	}

	Iterator& operator = (const typename container::iterator& rhs) {
		iter = rhs;
		return *this;
	}

	const T* operator->() {
		return iter->get();
	}

	Iterator& operator++() {
		++iter;
		return *this;
	}

	bool operator ==(const Iterator<T>& rhs) {
		return iter == rhs.iter;
	}

	bool operator !=(const Iterator<T>& rhs) {
		return iter != rhs.iter;
	}

	const T& operator*() {
		return *iter;
	}
private:
	typename container::iterator iter;
};
/**
 * Equipment resource holder, database keeper.
 * This class holds resource using unique_ptr,
 * and provides pointer based interface to outter user
 * Create, Delete, Update, Query
 */
template <typename T>
class ItemPool {

// forward typedef
private:
	typedef typename rc_type<T>::type rc_type;
	typedef typename container<typename rc_type>::type container;
public:
	ItemPool() {}
	// use default copy-ctor
	// use default copy-assign
	
	/**
	 * Insert an equipment to equipment pool
	 * 
	 * @param item
	 *		item to insert
	 */
	void insert(const T& item) {
		equips.push_back( rc_type(new T(item)) );
	}

	void remove(const T* item) {
		std::remove_if(equips.begin(), equips.end(), [](const rc_type<T>::type& t) {
			if (t == item) return true;
		});
	}

	bool find(const T* item) {
		return std::find_if(equipes.begin(), equips.end(), [&](const rc_type& t) {
			if (t == item) return true;
		}) != equips.last();
	}

	Iterator<T> begin() {
		return Iterator<T>(equips.begin());
	}

	Iterator<T> end() {
		return Iterator<T>(equips.end());
	}

private:
	typename container equips;
};

}

#endif // EQUIPMENT_POOL_HPP