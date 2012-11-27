#include <iostream>
#include <cstdlib>
#include "Rectangle.h"
#include "BadSizeException.h"
using namespace std;

Rectangle::Rectangle() {
_x = 0;
_y = 0;
}

Rectangle::Rectangle(int x, int y) {
try {
if(x < 0 || y < 0) {
BadSizeException e("size", "rectangle");
throw(e);
} else {
_x = x;
_y = y;
}
}
catch(BadSizeException& e) {
_x = 0;
_y = 0;
cerr << "Bad " << e.getSize() << " of a " << e.getObject() << "!" << endl;
}
}

Rectangle::~Rectangle() {
_x = 0;
_y = 0;
}

Rectangle& Rectangle::setSize(int x, int y) {
try {
if(x < 0 || y < 0) {
BadSizeException e;
e.getSize() = "size";
e.getObject() = "rectangle";
throw(e);
} else {
_x = x;
_y = y;
}
}
catch(BadSizeException& e) {
_x = 0;
_y = 0;
cerr << "Bad " << e.getSize() << " of a " << e.getObject() << "!" << endl;
}
}

int& Rectangle::getX() {
return _x;	
}

int& Rectangle::getY() {
return _y;	
}

void Rectangle::draw() {
cout << "Rectangle::draw():" << endl;
cout << "desc: " << _desc << endl;
cout << "x: " << _x << endl;
cout << "y: " << _y << endl;
}
