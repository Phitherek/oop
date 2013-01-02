// oblicznie w czasie kompilacji
//
// Napisz szablony takie aby mozliwe byly nastepujace oblicznie w czasie kompilacji
// suma pierwszych N liczb naturalnuch
// suma od N do M
// potega o wykladniku i podstawie naturalnej
//
// -Wall -g i nie zmieniamy tego pliku. Wynikowy program nazywac sie ma ct

#include <iostream>
#include "Comp.H"

int main () {
  
  std::cout << pow<2,2>::value << std::endl; // potega (prosty przyklad)
  std::cout << pow<3,3>::value << std::endl; // potega (prosty przyklad)
  std::cout << pow<3,24>::value << std::endl; // potega (duzo obliczen)

  std::cout << sum_to<5>::value << std::endl; // suma liczb od 1 do 5
  std::cout << sum_from_to<5,9>::value  << std::endl; // suma liczb od 5 do 9


}
/* wynik
4
27
3256662241
15
35
 */
