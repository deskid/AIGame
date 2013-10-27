#ifndef ID_OBJECT_HPP
#define ID_OBJECT_HPP

#include "type_difinition.hpp"
#include <type_traits>

class id_object;

namespace AIGame {

/**
 * mpl part. Forget it
 */
template <typename T>
struct is_id_object : public std::is_base_of<id_object, T> {};

template <>
struct is_id_object<id_object> : public std::true_type {};

class id_object {
public:
	id_object() {}
	id_object(id_type id) :id(id) {}
	virtual ~id_object() {}
public:
	void setId(id_type id_) {id = id_;}
	id_type getId() const { return id; }
private:
	id_type id;
};

} // AIGame

#endif // ID_OBJECT