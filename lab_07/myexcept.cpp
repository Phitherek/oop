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
try {
throw;	
}
catch(calculation_exception& ce) {
cout << "plik: " << ce._file << " linia: " << ce._line << " kontekst: (" << context << ") calculation_exception: " << ce.what() << endl;	
}
catch(numerical_exception& ne) {
cout << "plik: " << ne._file << " linia: " << ne._line << " kontekst: (" << context << ") numerical_exception: " << ne.what() << endl;	
}
catch(runtime_error& re) {
cout << "kontekst: (" << context << ") runtime_error: " << re.what() << endl;	
}
}
