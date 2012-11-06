#include <iostream>
#include <cstdlib>
#include <string>
#include "AssocArray.h"
using namespace std;

int main() {
cout << "Testing associative array..." << endl;
AssocArray tab;
tab.insert("first", 1);
tab.insert("second", 2);
tab.insert("third", 3);
tab.display();
tab.insert("third", 10); // Should show error message
tab.display(); // Should be unchanged
cout << tab["first"] << ", " << tab["second"] << ", " << tab["third"] << endl; // 1, 2, 3
tab["third"] = 30; // Should change the value
cout << tab["third"] << endl;
cout << tab["fourth"] << " <- The instruction, that should cause an error" << endl;
cout << tab.size() << endl;
tab.display();
tab.clean();
cout << "The array should now be empty..." << endl << "End of test!" << endl;
}
