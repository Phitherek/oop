// klasa Charges powinna symulowac zestaw ladunkow
// ladunki dodajemy do obiektu klasy C metoda add(), ktorej argumentami sa pol x, y i wartosc ladunku
// klasa pozwala na globalna zmiane stalej dielektrycznej (epsilon)
// sile (force) liczymy z nastepujacego wzoru (dla skladowej x)
// r = hypot( x -x_i, y - y_i ) // przekatna, funkcja z <cmath>
// f_x = sum[ charge charge_i (x - x_i)/(epsilon_zero*epsilon*4*PI* r^3 )]
// identycznie skladowa y
// wartosc epsilon_zero == 1.;
// program ma sie kompilowac do pliku "ctest"

#include <iostream>
using namespace std;

#include "Charges.h"
#include "Charges.h"

int main() {
  Charges c;
  c.add(0,0, +2).add(1,0, -1).add(-1,0, -1);
  
  cout << "ilosc ladunkow: " << c.n() << endl;  
  cout << "sila w punkcie 3,3: " << c.force(3,3, +1).x << " " << c.force(3,3, +1).y <<    endl;
  Charges::epsilon() = 80;
  cout << "po zwiekszeniu stalej epsilon " << c.force(3,3, +1).x << " " << c.force(3,3, +1).y <<    endl;
}
/* wynik 
ilosc ladunkow: 3
sila w punkcie 3,3: 0.000310207 -0.000750929
po zwiekszeniu stalej epsilon 3.57086e-05 1.44866e-05
 */
