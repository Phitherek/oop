// program ma sie skompilowac do pliku wykonywalnego "lifot"
// w implemetacji nalezy uzyc listy polaczonej z dynamiczna alokacja pamieci z jez. C (bez new/delete)
#include <iostream>
using namespace std;
#include "lifo.h"

int main(int argc, char** argv) {

  Lifo* f = init();
  insert(f,"Ala");
  insert(f,"ma");
  insert(f,"kota");
  insert(f,".");

  const char * napis;  
  napis = get(f);
  cout << napis << endl;

  napis = get(f);
  cout << napis << endl;

  napis = get(f);
  cout << napis << endl;

  napis = get(f);
  cout << napis << endl;
  
  napis = get(f);
  cout << (napis == 0 ? "ok": "cos jest zle")  << endl; 
}

/* wynik
.
kota
ma
Ala
ok

 */

