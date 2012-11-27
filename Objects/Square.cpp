#include <iostream>
#include <cstdlib>
#include "Square.h"
#include "BadSizeException.h"
using namespace std;

Square::Square() {
_x = 0;
_y = 0;
}

Square::Square(int x) {
try {
if(x >= 0) {
_x = x;
_y = x;
} else {
BadSizeException e("size", "square");
throw(e);
}	
}
catch(BadSizeException& e) {
_x = 0;
_y = 0;
cerr << "Bad " << e.getSize() << " of a " << e.getObject() << "!" << endl;;
}
}

Square::~Square() {
_x = 0;
_y = 0;
}

Square& Square::setSize(int x) {
try {
if(x >= 0) {
_x = x;
_y = x;
} else {
BadSizeException e;
e.getSize() = "size";
e.getObject() = "square";
throw(e);
}
return *this;
}
catch(BadSizeException& e) {
_x = 0;
_y = 0;
cerr << "Bad " << e.getSize() << " of a " << e.getObject() << "!" << endl;
}
}

int Square::getSize() {
return _x;	
}
