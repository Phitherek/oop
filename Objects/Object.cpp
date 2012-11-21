#include <iostream>
#include <cstdlib>
#include <string>
#include "Object.h"
using namespace std;

Object::Object() {
_desc = "";
}

Object::~Object() {
_desc = "";
}

Object& Object::setDesc(string desc) {
_desc = desc;
return *this;
}

string Object::getDesc() {
return _desc;	
}

void Object::draw() {
cout << "Object::draw(): " << endl << "desc: " << _desc << endl;
}
