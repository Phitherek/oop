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


int main(int argc, const char** argv) {
  Options opt;
  opt.add(new ShortOpt('h'));
  opt.add(new ShortOpt('e'));
  opt.add(new ShortOptWithArg('r', Arg("7"), new IsInt() ) );
  opt.add(new ShortOptWithArg('d', Arg("3.145"), new IsFloat() ) );

  try {
    opt.parse(argv, argc);
    cout << " " << static_cast<std::string>(opt[0]) << endl; 
    cout << " " << static_cast<std::string>(opt[1]) << endl; 
    cout << " " << static_cast<std::string>(opt[2]) << endl; 
    cout << " " << static_cast<std::string>(opt[3]) << endl; 
  } catch (const opt::invalid_argument&  e) {
    cout << "Blad w argumencie opcji " <<  e.what() << endl;
  } catch (const opt::unknown_option&  e) { 
    // tego przypadku nie trzeba implementowac, to znaczy nigdzie nie trzba go wyrzucac, no chyba ze komus starczy czasu
    cout << "Nieznana opcja " <<  e.what() << endl; 
  }
}

/* wynik dzialania z argumentami:  -h -d 5.67
 h obecna 
 e brak 
 r brak 7
 d obecna 5.67

 * wynik dzialania z argumentami -r 4.5 (tutaj mamy blednie podana opcje)

Blad w argumencie opcji r 4.5


 */


