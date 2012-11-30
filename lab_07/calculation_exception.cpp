#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "calculation_exception.h"
using namespace std;

calculation_exception::calculation_exception() {
_msg = "";
_file = "";
_line = -1;
}

calculation_exception::calculation_exception(string msg) {
_msg = msg;
_file = "";
_line = -1;
}

calculation_exception::calculation_exception(string msg, string file, int line) {
_msg = msg;
_file = file;
_line = line;
}

calculation_exception::~calculation_exception() throw() {
_msg = "";
_file = "";
_line = -1;
}

const char* calculation_exception::what() const throw() {
return _msg.c_str();
}
