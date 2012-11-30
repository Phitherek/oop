#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "myexcept.h"
using namespace std;

myexcept::myexcept() {
_msg = "";
_file = "";
_line = -1;
}

myexcept::~myexcept() throw() {
_msg = "";
_file = "";
_line = -1;	
}

void myexcept::handler(string context) {
	string t;
	if(_file != "" && _line != -1) {
		cout << "Plik: " << _file << " Linia: " << _line << " ";
		t = _type;
	} else {
	t = "runtime_error";	
	}
	cout << "Kontekst: (" << context << ") " << t << ": ";
	if(t == "runtime_error") {
	//cout << runtime_error::what() << endl; Nie działa :(	
	} else {
	cout << _msg << endl;	
	}
}
