#ifndef UNIQUE_CONTAINER_HPP
#define UNIQUE_CONTAINER_HPP

#include <memory>
#include <algorithm>
#include <iterator>

namespace util {

namespace detail {
    /**
     * @see @link {http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Type_Generator} 
     * for detail
     *
     * this is a workaround for type alias (using xxx = )
     */
    // the pointertype
    template <typename T>
    struct pointer_type {
        typedef std::unique_ptr<T> type;
    };

	template <typename T>
	struct alloc_type {
		typedef typename std::allocator<typename pointer_type<T>::type> type;
	};

	/**
	  * a wrapper to switch const_iterator and iterator
	  */
	template <bool flag, 
			  typename T,
			  template <typename X, typename XAlloc>
				  class TContainer,
			  typename Alloc = typename alloc_type<T>::type
			 >
	struct const_iterator_wrapper {
		
	};

	/** const_iterator version */
	template <typename T,
			  template <typename X, typename XAlloc>
				  class TContainer,
			  typename Alloc
			 >
	struct const_iterator_wrapper<true, T, TContainer, Alloc> {
		typedef typename TContainer<typename pointer_type<T>::type, Alloc>::const_iterator iterator_type;
	};

	/** iterator version */
	template <typename T,
			  template <typename X, typename XAlloc>
				  class TContainer,
			  typename Alloc
			 >
	struct const_iterator_wrapper<false, T, TContainer, Alloc> {
		typedef typename TContainer<typename pointer_type<T>::type, Alloc>::iterator iterator_type;
	};
	// partial speciallization to const true
} // detail

/**
 * this class provides an iterator for unique_container.
 * it takes two template parameters, the first one for T,
 * the second for container type, unique_list, etc
 * this class makes iterator acts like container<pointer_type<T>>::iterator
 */

template <typename T,
		  bool const_tag,
          template<typename X, typename XAlloc>
             class TContainer,
          typename Alloc = typename detail::alloc_type<T>::type
        >
class Iterator : public std::iterator<
                  std::input_iterator_tag, // tag
                  ptrdiff_t, // difference type
                  typename detail::pointer_type<T>::type // pointer type
                 >
{
// forward typedef
private:
	typedef typename 
		detail::const_iterator_wrapper<const_tag, T, TContainer, Alloc> wrapper;
    typedef typename  detail::pointer_type<T>::type   pointer_type;
    typedef TContainer<pointer_type, Alloc>           container;
    typedef Iterator<T, const_tag, TContainer, Alloc> type;
	typedef typename wrapper::iterator_type           iterator_type;
public:
    Iterator(const iterator_type& rhs) {
        iter = rhs;
    }

    Iterator& operator = (const iterator_type& rhs) {
        iter = rhs;
        return *this;
    }
    // this guy is too lazy to provide move-ctor && move assign
    /**
     * dereference
     */
    const T* operator->() const {
        return iter->get();
    }

    T* operator->() {
        return iter->get();
    }
    /**
     * dereference
     */
    const T& operator*() const {
        return *iter;
    }
      
    T& operator*() {
        return *iter->get();
    }
    /**
     * get raw iterator
     */
    const iterator_type& raw() const {
        return iter;
    }
   
    iterator_type& raw() {
        return iter;
    }

    /**
     * get ptr
     */
    const T* get() const {
        return iter->get();
    }

    T* get() {
        return iter->get();
    }
    /**
     * prefix inc
     */
    Iterator& operator++() {
        ++iter;
        return *this;
    }
    /**
     * suffix inc
     */
    Iterator& operator++(int) {
        Iterator tmp = *this;
        this.operator++();
        return tmp;
    }
    /**
     * compare, return underlying iterator compare result
     */
    bool operator == (const type& rhs) const {
        return iter == rhs.iter;
    }
    bool operator != (const type& rhs) const {
        return iter != rhs.iter;
    }
    /**
     * get distance
     */
    ptrdiff_t operator - (const type& rhs) const {
        return iter-rhs.iter;
    }
private:
    iterator_type iter;
};

/**
 * This class provides a container holding resource by unique_ptr,
 * and provides pointer based interface to outter user
 * Create, Delete, Update, Query (iterator)
 * the implementation promise not to copy/assign an object,
 * uses move-sementic as the only method to manage objects
 */
template <typename T,
          template <typename X, typename XAlloc>
              class TContainer,
          typename Alloc = typename detail::alloc_type<T>::type
        >
class unique_container {

// forward typedef
private:
    typedef typename detail::pointer_type<T>::type pointer_type;
    typedef TContainer<pointer_type, Alloc> container;
public:
    typedef unique_container<T, TContainer, Alloc>type;
    typedef Iterator<T, false, TContainer, Alloc> iterator;
    typedef Iterator<T, true, TContainer, Alloc>  const_iterator;
    typedef T                                     value_type;
    typedef value_type&                           reference;
    typedef const value_type&                     const_reference;
    typedef pointer_type                          pointer;
    typedef const pointer                         const_pointer;
    typedef size_t                                size_type;
public:
    unique_container() {}
    /**
     * move ctor
     */
    unique_container(unique_container&& rhs) {
        container_ = std::move(rhs.container_);
    }
    /**
     * move assign
     */
    unique_container& operator = (unique_container&& rhs) {
        if (*this == rhs) return *this;
        
        container_ = std::move(rhs.container_);
        
        return *this;
    }
    /**
     * compare. return underlying container comparation result
     */
    bool operator == (const unique_container& rhs) {
        return container_ == rhs.container_;
    }
    
    /**
     * Insert an item to item pool
     * 
     * @param item
     *        item to insert, the ownship of this item would be taken
     */
    void insert(T* item) {
        container_.push_back( pointer_type(item) );
    }

	/**
	  * insert by unique_ptr, this function will take ownship of ptr
	  */
	void insert(pointer&& ptr) {
		container_.push_back(std::move(ptr));
    }
    /**
     * remove item from pool
     */
    void remove(reference item) {
        std::remove_if(container_.begin(), container_.end(), [&](const pointer_type& t) {
            if (*t == item) return true;
        });
    }
    /**
     * erase iterator from pool
     */
    void erase(iterator iter) {
        container_.erase(iter.raw());
    }
    /**
     * return the beginning of iterator
     */
    const_iterator begin() const {
        return const_iterator(container_.begin());
    }
	iterator begin() {
		return iterator(container_.begin());
	}
    /**
	  * returns the end of iterator
	  */
    const_iterator end() const {
        return const_iterator(container_.end());
    }
	iterator end() {
		return iterator(container_.end());
	}
    

    /**
     * give ownship to another container, if item is not in container_
     * I dont know what will happen...
     */
    void giveOwnship(iterator item, type& receiver) {
        // item must by mime!
        receiver.insert(std::move(*item.raw()));
        erase(item);
    }
private:
    container container_;
};

} // util

#endif // UNIQUE_CONTAINER_HPP
