#include <iostream>
#include <cstdlib>
#include "BadChoiceException.h"
using namespace std;

BadChoiceException::BadChoiceException() {
_msg = "";	
}

BadChoiceException::BadChoiceException(string msg) {
_msg = msg;	
}

string BadChoiceException::what() {
return _msg;	
}

void BadChoiceException::setMsg(string msg) {
_msg = msg;	
}
