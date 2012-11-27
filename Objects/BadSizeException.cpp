#include <iostream>
#include <cstdlib>
#include "BadSizeException.h"
using namespace std;

BadSizeException::BadSizeException() {
	_size = "";
	_obj = "";
}

BadSizeException::BadSizeException(string size, string object) {
	_size = size;
	_obj = object;
}

string& BadSizeException::getSize() {
	return _size;
}

string& BadSizeException::getObject() {
	return _obj;
}
