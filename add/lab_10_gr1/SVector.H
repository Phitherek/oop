#ifndef _SVECTOR_H
#define _SVECTOR_H
#include <cstring>
/// \file SVector.H
/// \brief A Vector class with optimized = operator.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class SVector
/// \brief A vector class with optimized = operator.
template<typename T> class SVector {
private:
pod_type *_container;
int _size;
public:
typedef struct {
T val; ///< Value
bool pod = true; ///< Is pod?
} is_pod; ///< A typedef for pod types.
typedef struct {
T& val; ///< Value
bool pod = false; ///< Is pod?
} is_not_pod; ///< A typedef for not pod types.
SVector(); ///< A constructor.
~SVector(); ///< A destructor.
SVector(SVector& obj); ///< \brief A copy constructor.
///< \param obj An object to be copied.
SVector operator=(SVector& obj); ///< \brief A copy operator=.
///< \param obj An object to be copied.
///< \return Copied SVector object.
T& at(int idx); ///< \brief A function, that allows to change specific value.
///< \param idx Index of the value.
///< \return A reference to an object of template parameter type or NULL.
int size(); ///< \brief A function, that returns size of the vector.
///< \return Size of the vector.
};

template<typename T> SVector<T>::SVector() {
	_container = NULL;
	_size = 0;
}

template<typename T> SVector<T>::~SVector() {
if (_container != NULL) {
delete[] _container;
_container = NULL;
}
_size = 0;
}

template<typename T> SVector<T>::SVector(SVector<T>& obj) {
if(obj._container != NULL) {
if(obj._container[obj._size-1].pod == true) {
_container = new pod_type[obj._size];
for(int i = 0; i < obj._size; i++) {
_container[i] = obj._container[i];	
}
_size = obj._size;
} else {
_container = new pod_type[obj._size];
for(int i = 0; i < obj._size; i++) {
memcpy(_container[i], obj._container[i], sizeof(pod_type));	
}
_size = obj._size;
}
} else {
_container = NULL;
_size = 0;
}	
}

template<typename T> SVector<T> SVector<T>::operator=(SVector<T>& obj) {
if(obj._container != NULL) {
if(obj._container[obj._size-1].pod == true) {
_container = new pod_type[obj._size];
for(int i = 0; i < obj._size; i++) {
_container[i] = obj._container[i];	
}
_size = obj._size;
} else {
_container = new pod_type[obj._size];
for(int i = 0; i < obj._size; i++) {
memcpy(_container[i], obj._container[i], sizeof(pod_type));	
}
_size = obj._size;
}
} else {
_container = NULL;
_size = 0;
}
return *this;
}

template<typename T> T& SVector<T>::at(int idx) {
if(idx < 0) {
return NULL;
} else {
pod_type *newContainer;
if(idx >= _size) {
if(_container[_size-1].pod == true) {
newContainer = new pod_type[idx];
for(int i = 0; i < _size; i++) {
newContainer[i] = _container[i];	
}
_size = idx+1;
delete[] _container;
_container = newContainer;
} else {
newContainer = new pod_type[idx];
for(int i = 0; i < obj._size; i++) {
memcpy(newContainer[i], _container[i], sizeof(pod_type));	
}
_size = idx+1;
delete[] _container;
_container = newContainer;
}
}
return _container[idx].val;
}	
}

template<typename T> int SVector<T>::size() {
return _size;
}
#endif
