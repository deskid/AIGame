#ifndef EQUIPMENT_POOL_HPP
#define EQUIPMENT_POOL_HPP

#include "type_difinition.hpp"
#include "Equipment.hpp"
#include <memory>
#include <list>
#include <algorithm>
#include <iterator>

class Instrument;

namespace AIGame {

namespace Pool {
namespace detail {
	template <typename T>
	using container = std::list;

	template <typename T>
	using rc_type = std::unique_ptr ;
} // detail
}

template <typename T>
class Iterator : public std::iterator<std::input_iterator_tag, rc_type<T>> {
public:
	Iterator(const container<rc_type<T>>::iterator& rhs);
	const T& operator->() {
	}
private:
	container<rc_type<T>>::iterator iter;
};
/**
 * Equipment resource holder, database keeper.
 * This class holds resource using unique_ptr,
 * and provides pointer based interface to outter user
 * Create, Delete, Update, Query
 */
template <typename T>
class ItemPool {
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
		std::remove_if(equips.begin(), equips.end(), [](const rc_type& t) {
			if (t == item) return true;
		});
	}

	bool find(const T* item) {
		return std::find_if(equipes.begin(), equips.end(), [&](const rc_type& t) {
			if (t == item) return true;
		}) != equips.last();
	}

	
private:
	container<rc_type<T>> equips;
};

using InstrumentPool = ItemPool<Instrument>;
}

#endif // EQUIPMENT_POOL_HPP