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
_type = "calculation_exception";
}

calculation_exception::calculation_exception(string msg) {
_msg = msg;
_file = "";
_line = -1;
_type = "calculation_exception";
}

calculation_exception::calculation_exception(string msg, string file, int line) {
_msg = msg;
_file = file;
_line = line;
_type = "calculation_exception";
}

calculation_exception::~calculation_exception() throw() {
_msg = "";
_file = "";
_line = -1;
_type = "calculation_exception";
}

const char* calculation_exception::what() const throw() {
return _msg.c_str();
}
