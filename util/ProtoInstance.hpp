#ifndef PROTO_INSTANCE_HPP
#define PROTO_INSTANCE_HPP

/*
 * wrap Prototype in this class to protect the type
 */
template <typename T>
class ProtoInstance {
public:
	const T& operator->() {  return *proto; }
public:
	ProtoInstance(const T* t) :proto(t) { }
private:
	const T* proto;
};

#endif // PROTO_INSTANCE_HPP
