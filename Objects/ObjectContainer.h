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
ObjectContainer(ObjectContainer& oc); ///< \brief A copy constructor.
/// \param oc A reference to an ObjectContainer to be copied.
~ObjectContainer(); ///< A destructor.
ObjectContainer& push(Object& o); ///< \brief A function, that adds an Object to the end of array.
///< \param o A pointer to an Object to be added.
///< \return A reference to changed ObjectContainer.
Object& pop(); ///< \brief A function that returns and erases an Object from the end of array.
///< \return A pointer to an Object from the end of array.
int size(); ///< \brief A function that returns array size.
///< \return Array size.
};
