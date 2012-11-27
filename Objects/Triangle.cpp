#include <iostream>
#include <cstdlib>
#include "Triangle.h"
#include "BadSizeException.h"
using namespace std;

Triangle::Triangle() {
_a = 0;
_h = 0;
}

Triangle::Triangle(int a, int h) {
try {
if(a < 0 || h < 0) {
BadSizeException e("size", "triangle");
throw(e);
} else {
_a = a;
_h = h;
}
}
catch(BadSizeException& e) {
_a = 0;
_h = 0;
cerr << "Bad " << e.getSize() << " of a " << e.getObject() << "!" << endl;
}
}

Triangle::~Triangle() {
_a = 0;
_h = 0;
}

Triangle& Triangle::setSize(int a, int h) {
try {
if(a < 0 || h < 0) {
BadSizeException e;
e.getSize() = "size";
e.getObject() = "triangle";
throw(e);
} else {
_a = a;
_h = h;
}
}
catch(BadSizeException& e) {
_a = 0;
_h = 0;
cerr << "Bad " << e.getSize() << " of a " << e.getObject() << "!" << endl;
}
}

int Triangle::getA() {
return _a;	
}

int Triangle::getH() {
return _h;	
}

void Triangle::draw() {
cout << "Triangle::draw():" << endl;
cout << "desc: " << _desc << endl;
cout << "a: " << _a << endl;
cout << "h: " << _h << endl;
}
