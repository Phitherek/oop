#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "numerical_exception.h"
using namespace std;

string numerical_exception::_msg;
string numerical_exception::_file;
int numerical_exception::_line;

numerical_exception::numerical_exception(): runtime_error("") {
_msg = "";
_file = "";
_line = -1;
}

numerical_exception::numerical_exception(string msg): runtime_error(msg.c_str()) {
_msg = msg;
_file = "";
_line = -1;
}

numerical_exception::numerical_exception(string msg, string file, int line): runtime_error(msg.c_str()) {
_msg = msg;
_file = file;
_line = line;
}

numerical_exception::~numerical_exception() throw() {
_msg = "";
_file = "";
_line = -1;
}

const char* numerical_exception::what() const throw() {
return _msg.c_str();
}
