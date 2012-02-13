/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOREFPTR_H
#define AOREFPTR_H
#include <iostream>
#include <cassert>

using namespace std;
namespace ao{
namespace core{
//Pointers, Refrences, and Handles
//
// Handle
// (class template)
// ----------
// + Handle():
// + Handle(TYPE*t):
// + Handle(const Handle& h):
// + ~Handle()
// + operator=(const Handle&): Handle&
// + operator bool() const: Handle&
// + operator *() const: TYPE&
// + operator ->() const: TYPE
// ----------
// - p:TYPE&
// ----------
//
template <class TYPE> class Handle{
public:
	Handle():p(0){};
	Handle(const Handle& s): p(0) {if (s.p) p =s.p->clone();}
	Handle& operator=(const Handle&);
	~Handle() {delete p;}

	Handle(TYPE* t):p(t){}

	operator bool() const {return p;}
	TYPE& operator*() const;
	TYPE* operator->() const;
private:
	TYPE& p;
};
//
// Ref_Handle
// (class template)
// ----------
// + Ref_Handle():
// + Ref_Handle(TYPE*t):
// + Ref_Handle(const Ref_Handle& h):
// + ~Ref_Handle()
// + operator=(const Ref_Handle&): Ref_Handle&
// + operator bool() const: Ref_Handle&
// + operator *() const: TYPE&
// + operator ->() const: TYPE
// ----------
// - p:TYPE&
// ----------
//
template <class TYPE> class Ref_Handle{
public:
	Ref_Handle(): refptr(new size_t(1)),p(0){}
	Ref_Handle(TYPE* t):refptr(new size_t(1)),p(t){}
	Ref_Handle(const Ref_Handle& h):refptr(h.refptr),p(h.p){	++*refptr;}

	Ref_Handle& operator=(const Ref_Handle&);
	~Ref_Handle();
	//
	operator bool() const { return p;}
	TYPE& operator*() const{
		if(p)
			return *p;
		throw std::runtime_error(*unbound Ref_Handle*);
	}
	TYPE* operator->() const{
		if(p)
			return p;
		throw std::runtime_error(*unbound Ref_Handle*);
	}
private:
	TYPE* p;
	size_t refptr;
};
//
// Ptr
// (class template)
// ----------
// + make_unique(): void
// + Ptr():
// + Ptr(TYPE*t):
// + Ptr(const Ptr& h):
// + ~Ptr()
// + operator=(constPtr&): Ptr&
// + operator bool() const: Ptr&
// + operator *() const: TYPE&
// + operator ->() const: TYPE
// ----------
//
// ----------
//
template <class TYPE> class Ptr{
public:
	void make_unique();
	//
	Ptr(): refptr(new size_t(1)),p(0){}
	Ptr(TYPE* t):refptr(new size_t(1)),p(t){}
	Ptr(const Ptr& h):refptr(h.refptr),p(h.p){	++*refptr;}

	Ptr& operator=(const Ptr&);
	~Ptr();
	operator bool() const {return p;}
	TYPE& operator*()const;
	TYPE*operator->() const;
	//
private:
	TYPE*p;
	size_t* refptr;
};

//Pointers, Refrences, and Handles
template <class T> Handle<T>& Handle<T>::operator=(const Handle& rhs){
	if (&rhs !=this){
		delete p;
		p=rhs.p ? rhs.p->clone():0;
	}
	return *this;
}
template <class T> T& Handle<T>::operator*() const{
	if(p)
		return *p;
	throw runtime_error("unbound Handle");
}
template <class T> T* Handle<T>::operator->() const{
	if(p)
		return *p;
	throw runtime_error("unbound Handle");
}
template <class T> Ref_Handle<T>& Ref_Handle<T>::operator=(const Ref_Handle& rhs) {
	++*rhs.reptr;
	if(--*refptr==0){
		delete refptr;
		delete p;
	}

	refptr=rhs.refptr;
	p=rhs.p;
	return *this;
}
template <class T> Ref_Handle<T>::~Ref_Handle(){
	if(--*refptr==0){
		delete refptr;
		delete p;
	}
}
template <class T> T* clone(const T* rhs){
	return rhs->clone();
}
template <class T> void Ptr<T>::make_unique(){
	if(*refptr!=1){
		--*refptr;
		refptr=new size_t(1);
		p=p? clone(p):0;
	}
}

}
}
#endif
