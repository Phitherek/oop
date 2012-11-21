#pragma once
#include "Object.h"

class ObjectContainer {
private:
Object* _tab;
int _size;
public:
ObjectContainer();
ObjectContainer(ObjectContainer& oc);
~ObjectContainer();
ObjectContainer& push(Object o);
Object pop();
};
