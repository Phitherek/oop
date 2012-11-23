// Uzyteczne klasy do parsowania opcji
//
// Opcje programow (np ls) dzielimy na tzw. krotkie w formie -l
// opcje dlugie np: --help 
// opcje z argumentami "-o file"
//
// Pojedyncza opcja moze byc reprezentowana przez obiekt, kazdy typ opcji
// przez inna klase. Jednoczesnie obiekty te sa powiazane relacja "jest rodzajem"
// a to narzuca pewna hierarchie klas.
//
// Aby tej hierarchii nie rozbudowywac nadto argument opcji jest obslugiwane
// prze mala klase Arg z uzytecznymi operatorami konwersji. 
//
// Prosze kompilowac z opcja -Wall do pliku wykonywalnego otest i nie zmieniac nazwy tego pliku.
// Implementacja ma byc oczywiscie w wielu plikach z jednym naglowkiem ogolnym.
//

#include <iostream>
using namespace std;
#include "Options.h"


int main(int argc, char** argv) {
  Opt* options[9];
  
  ShortOpt help('h');  
  options[0] = &help;
  ShortOpt exporto('e');  
  options[1] = &exporto;
  ShortOpt forward('f');  
  options[2] = &forward;
  LongOpt run("run");
  options[3] = &run;
  LongOpt stop("stop");
  options[4] = &stop;
  LongOpt uname("username");
  options[5] = &uname; 
  
  ShortOptWithArg ro('r', Arg("7")); // default ustawiony na 7
  options[6] = &ro;
  ShortOptWithArg dopt('d', Arg("3.14")); // default ustawiony pi
  options[7] = &dopt;
  ShortOptWithArg lo('l', Arg("everything")); // default ustawiony
  options[8] = &lo;


  for ( int i = 0 ; i < 9; ++i ) {
    int position = options[i]->check(argv, argc);
    cout  << options[i]->key() << " " <<  options[i]->present() << " at position " << position << endl;
  }

  // help.arg() ma sie nie kompilowac oczywiscie
  
  int rarg = ro.arg();
  const std::string& larg = lo.arg();
  float  darg = dopt.arg();

  cout << "arguments " << rarg << endl;
  cout << "arguments " << larg << endl;
  cout << "arguments " << darg << endl;  

}

/* wynik dzialania z argumentami:  -h -e --run --stop --username -r 5 -d 7.28
h 1 at position 1
e 1 at position 2
f 0 at position -1
run 1 at position 3
stop 1 at position 4
username 1 at position 5
r 1 at position 6
d 1 at position 8
l 0 at position -1
arguments 5
arguments everything
arguments 7.28
 */
