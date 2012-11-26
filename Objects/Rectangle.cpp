#include <iostream>
#include <cstdlib>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() {
_x = 0;
_y = 0;
}

Rectangle::Rectangle(int x, int y) {
if(x < 0 || y < 0) {
_x = 0;
_y = 0;
cerr << "Bad size of a rectangle!" << endl;
} else {
_x = x;
_y = y;
}
}

Rectangle::~Rectangle() {
_x = 0;
_y = 0;
}

Rectangle& Rectangle::setSize(int x, int y) {
if(x < 0 || y < 0) {
_x = 0;
_y = 0;
cerr << "Bad size of a rectangle!" << endl;
} else {
_x = x;
_y = y;
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
