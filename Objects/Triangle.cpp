#include <iostream>
#include <cstdlib>
#include "Triangle.h"
using namespace std;

Triangle::Triangle() {
_a = 0;
_h = 0;
}

Triangle::Triangle(int a, int h) {
if(a < 0 || h < 0) {
_a = 0;
_h = 0;
cerr << "Bad size of a triangle!" << endl;
} else {
_a = a;
_h = h;
}
}

Triangle::~Triangle() {
_a = 0;
_h = 0;
}

Triangle& Triangle::setSize(int a, int h) {
if(a < 0 || h < 0) {
_a = 0;
_h = 0;
cerr << "Bad size of a triangle!" << endl;
} else {
_a = a;
_h = h;
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
