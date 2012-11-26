#include <iostream>
#include <cstdlib>
#include "ObjectContainer.h"

ObjectContainer::ObjectContainer() {
_tab = NULL;
_size = 0;
}

ObjectContainer::ObjectContainer(ObjectContainer& oc) {
_size = oc._size;
if(_size == 0) {
_tab = NULL;
} else {
_tab = new Object*[_size];
for(int i = 0; i < _size; i++) {
	_tab[i] = oc._tab[i];
}
}
}

ObjectContainer::~ObjectContainer() {
if(_tab != NULL) {
delete []_tab;
_tab = NULL;
}
_size = 0;
}

ObjectContainer& ObjectContainer::push(Object& o) {
_size = _size+1;
Object** newTab;
newTab = new Object*[_size];
for(int i = 0; i < _size-1; i++) {
newTab[i] = _tab[i];	
}
newTab[_size-1] = &o;
Object** tnt = _tab;
_tab = newTab;
delete []tnt;
return *this;
}

Object& ObjectContainer::pop() {
_size = _size-1;
Object** newTab;
Object *save = _tab[_size];
newTab = new Object*[_size];
for(int i = 0; i < _size; i++) {
newTab[i] = _tab[i];	
}
Object** tnt = _tab;
_tab = newTab;
delete []tnt;
return *save;
}

int ObjectContainer::size() {
return _size;	
}
