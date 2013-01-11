#ifndef _STATICARRAY_H
#define _STATICARRAY_H
/// \file StaticArray.h
/// \brief A simple structure gathering size and data.
/// \author Piotr Żurek
/// \date 2013
/// \version 0.1

template<typename T, unsigned int tsize> struct static_array {
	T* data; ///< An array, that stores data.
	unsigned int size; ///< Size of the array.
	static_array(); ///< A constructor.
	~static_array(); ///< A destructor.
};

template<typename T, unsigned int tsize> static_array<T, tsize>::static_array() {
	data = new T[tsize];
	size = tsize;
}

template<typename T, unsigned int tsize> static_array<T, tsize>::~static_array() {
	delete[] data;
	size = 0;	
}

#endif
