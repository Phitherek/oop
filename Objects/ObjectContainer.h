#pragma once
#include "Object.h"
/// \file ObjectContainer.h
/// \brief An implementation of the dynamic array for Object objects.
/// \author Phitherek_
/// \date 2012
/// \version 0.1

/// \class ObjectContainer
/// \brief A class representing a dynamic array of Object objects.
class ObjectContainer {
private:
Object* _tab;
int _size;
public:
ObjectContainer(); ///< A constructor.
ObjectContainer(ObjectContainer& oc); ///< A copy constructor.
~ObjectContainer(); ///< A destructor.
ObjectContainer& push(Object o); ///< A function, that adds an Object to the end of array.
Object pop(); ///< A function that returns and erases an Object from the end of array.
};
