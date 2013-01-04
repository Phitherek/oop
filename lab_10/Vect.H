#ifndef _VECT_H
#define _VECT_H
#include <cstring>
/// \file Vect.H
/// \brief A vector with optimized swap.
/// \author Piotr Żurek
/// \date 2013
/// \version 0.1

/// \struct is_pod
/// \brief A helper class that stores an information about pod or non-pod type.
template<typename T> struct is_pod {
	const static bool value = false;	
};

/// \struct helper
/// \brief A helper for swap function in version for pod and non-pod types.
template<typename T, bool pod> 
struct helper { 
static void swap(T& a, T& b); ///< \brief A swap function for pod and non-pod types.
///< \param a First object to swap.
///< \param b Second object to swap.
};

template<typename T>
struct helper<T, true> {
static void swap(T& a, T& b) {
		T tmp;
		memcpy(&tmp, &a, sizeof(T));
		memcpy(&a, &b, sizeof(T));
		memcpy(&b, &tmp, sizeof(T));	
		}
};
		
template<typename T> 
struct helper<T, false> {
static void swap(T& a, T& b) {
		T tmp;
		tmp = a;
		a = b;
		b = tmp;	
}
};

/// \class Vect
/// \brief A vector with optimized swap.
template<typename T> class Vect {
private:
	T* _container;
	unsigned int _size;
public:
	T& operator[](int idx); ///< \brief An operator[] that can be used to access values in vector.
	///< \param idx Index in container.
	///< \return A reference to an object of template parametrized type.
	
	void buble_sort(bool (*comp)(const T&, const T&)); ///< \brief A bubble sort with comparison function as parameter.
	///< \param comp A pointer to a comparison function returning bool and taking two const T& parameters.

	Vect(int size); ///< \brief A constructor with parameter.
	///< \param size Size of the container.
	
	~Vect(); ///< A destructor.
	
	unsigned int size(); ///< \brief A function returning size of the container.
	///< \return Size of the container.
};

template<typename T> Vect<T>::Vect(int size) {
	if(size > 0) {
		_container = new T[size];
		_size = size;	
	} else {
		_container = NULL;
		_size = 0;	
	}
}

template<typename T> Vect<T>::~Vect() {
	if(_container != NULL) {
		delete[] _container;
		_container = NULL;	
	}
	_size = 0;
}

template<typename T> T& Vect<T>::operator[](int idx) {
		return _container[idx];	
}

template<typename T> void Vect<T>::buble_sort(bool (*comp)(const T&, const T&)) {
	for(unsigned int i = 0; i < _size; i++) {
		for(unsigned int j = i+1; j < _size; j++) {
			if(comp(_container[i], _container[j])) {
					helper<T, is_pod<T>::value>::swap(_container[i], _container[j]);
			}
		}
	}
}

template<typename T> unsigned int Vect<T>::size() {
return _size;	
}

#endif
