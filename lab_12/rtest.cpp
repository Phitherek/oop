// Srednia biegnaca
// 
// Napisac klase modelujaca srednia biegnaca (obliczana z ostanich N elementow)
// W implementacji nalezy uzyc odpowiedniego kontenera STL. Uzasadnic wybor.
//
// Do obliczania odpowiednich parametrow uzyc algorytmow STL.
// obecnosc petli for/while bedzie skutkowac obnizeniem ilosci punktow.
// Nie uzycie zadnego algorytmu STL skutkuje 0 punktow.
// Mozna korzystac z dokumentacji: http://www.sgi.com/tech/stl/table_of_contents.html
//
// Kompilowac do pliku rtest z opcami -Wall -g
//

#include <iostream>

#include "RAverage.h"

using namespace std;
int main(int argc, char** argv) {  
  RAverage<int, 4> ra1;
  ra1 << 1;
  cout << "srednia: " << ra1 << endl;
  ra1 << 1 << 2 << 2 << 4;
  cout << "srednia: " << ra1 << endl;
  ra1 <<  4 << 2 << 2;
  cout << "srednia: " << ra1 << endl;

  RAverage<double, 5> ra2;
  ra2 << 1. << 2. << 2. << 4. << +6.56 << -5.45 << 7;
  cout << "srednia: " << ra2 << " zawartosc: " << ra2.dump() << endl;
  cout << "N powyzej sredniej: " << ra2.n_below(ra2) <<  " ponizej sredniej: " << ra2.n_above(ra2) << endl; 
  cout << "N powyzej 0: " << ra2.n_below(0.) <<  " ponizej 0: " << ra2.n_above(0.) << endl; 
}
/* wynik
srednia: 1
srednia: 2.25
srednia: 3
srednia: 2.822 zawartosc: 7, -5.45, 6.56, 4, 2, 
N powyzej sredniej: 3 ponizej sredniej: 2
N powyzej 0: 4 ponizej 0: 1
*/
