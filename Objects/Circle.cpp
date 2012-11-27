#include <iostream>
#include <cstdlib>
#include "Circle.h"
#include "BadSizeException.h"
using namespace std;

Circle::Circle() {
_r = 0;	
}

Circle::Circle(int r) {
try {
if(r >= 0) {
_r = r;
} else {
BadSizeException e("radius", "circle");
throw(e);
}
}
catch(BadSizeException& e) {
_r = 0;
cerr << "Bad " << e.getSize() << " of a " << e.getObject() << "!" << endl;
}
}

Circle::~Circle() {
_r = 0;	
}

Circle& Circle::setR(int r) {
try {
	if(r >= 0) {
_r = r;
} else {
BadSizeException e;
e.getSize() = "radius";
e.getObject() = "circle";
throw(e);
}
return *this;
}
catch(BadSizeException& e) {
_r = 0;
cerr << "Bad " << e.getSize() << " of a " << e.getObject() << "!" << endl;
}
}

int Circle::getR() {
return _r;	
}

void Circle::draw() {
cout << "Circle::draw():" << endl << "desc: " << _desc << endl << "r: " << _r << endl;	
}
