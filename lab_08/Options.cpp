#include "Options.h"
#include <typeinfo>
using namespace std;

Options::Options() {
_container = NULL;
_size = 0;
}

Options::~Options() {
	if(_container != NULL) {
	for(int i = 0; i < _size; i++) {
		if(static_cast<std::string>(typeid(*_container[i]).name()) == "15ShortOptWithArg") {
		delete dynamic_cast<ShortOptWithArg*>(_container[i]);
		} else {
		delete _container[i];	
		}
	}
	delete[] _container;	
	}
	_container = NULL;
	_size = 0;
}

void Options::add(ShortOpt* object) {
int newSize = _size+1;
ShortOpt** newContainer = NULL;
newContainer = new ShortOpt*[newSize];
for(int i = 0; i < _size; i++) {
newContainer[i] = _container[i];	
}
newContainer[_size] = object;
delete[] _container;
_container = newContainer;
_size = newSize;
}

std::string Options::operator[](int idx) {
	std::string s = "";
	if(idx < _size) {
	s += _container[idx] -> key();
	if(_container[idx] -> present()) {
	s += " obecna ";	
	} else {
	s += " brak ";	
	}
	if(static_cast<std::string>(typeid(*_container[idx]).name()) == "15ShortOptWithArg") {
	s += static_cast<std::string>(dynamic_cast<ShortOptWithArg*>(_container[idx]) -> arg());
	}
	return s;
	} else {
	return "";	
	}
}

void Options::parse(const char** argv, int argc) {
	for(int j = 1; j < argc; j++) {
	int optPosInContainer = -1;
	for(int i = 0; i < _size; i++) {
	if(argv[j][0] == '-') {
			if (argv[j][1] != '-') {
				if(argv[j][1] == (_container[i] -> key())[0]) {
					optPosInContainer = i;
					break;
				}
			}
	} else {
	optPosInContainer = -2;
	}
	}
	if(optPosInContainer > -1) {
	int optPos = _container[optPosInContainer] -> check(argv, argc);
	optPos = _container[optPosInContainer] -> check(argv, argc);
	} else if(optPosInContainer != -2) {
		throw opt::unknown_option(argv[j]);
	}
	}
}
