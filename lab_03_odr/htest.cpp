// Histogram
// Kazdy histogram charakteryzuje sie 3 parametrami
// iloscia binow, i zakresem (min i max).
// Do histogramu dodajemy odczyty poprzez metode fill
// w tej metodzie nalezy odnalezc odwiedni bin i do jego wartosc dodac 1
// histogramy mozna dodawac, odejmowac (metoda add) i dzielic (metoda divide).
// Dla kazdego histogramu mozemy obliczyc sume binow (integral)
// przeskalowac wartosc w binach o dowolna liczbe zmiennoprzecinkowa 
// a takze znormalizowac histogram do pewnej liczby (wtedy suma binow jest jej rowna). 

// program powinien skompilowac sie do pliku wykonywalnego 'htest'
// (odejmuje jeden punkt za kompilacje w przeciwnym przypadku)
// przy kompilacji musi byc uzyta flaga -Wall (odejmuje 1 punkt za jej brak)
// nie wolno zmieniac nazwy pliku htest.C na main.C/cpp itd. 
// (odejmuje 1 punkt za kompilacje w wypadku takiego posuniecia)

#include <iostream>
using namespace std;
#include "Hist.h"
#include "Hist.h"

int main() {

  Hist histogram1(6, 1., 7.);  // histogram do zliczania rzutow kostka
  Hist histogram2(6, 1., 7.);

  histogram1.fill(3).fill(3); // dwa zdazenia z wynikiem 3
  histogram1.fill(2).fill(3); // dwa zdazenia w 2 i 3
  Hist::print(histogram1);

  for ( int i = 0; i < 23; ++i ) {
    histogram2.fill( 1 + i%6 );
  }
  Hist::print(histogram2);
  
  const Hist h3 = Hist::add(histogram1, histogram2, 2, 3); // operacja na kazdym binie histogram1 * 2 + histogram2 *3
  Hist::print(h3);
  
  Hist h4 = Hist::add(h3, histogram1, 1, -1); // //operacja h3 - h1  na kazdym binie
  Hist::print(h4);
  
  cout << "suma binow " << h4.integral() << endl;
  h4.scale(0.5);
  cout << "suma binow po skalowaniu " << h4.integral() << endl;
  h4.normalize();
  cout << "suma binow po normalizacji do 1: " << h4.integral() << endl;
  h4.normalize(100.);
  cout << "suma binow po normalizacji do 100: " << h4.integral() << endl;

  cout << "wartosc w 2 binie: " << h4.binContent(2) << endl;
  Hist::print(h4);
}
/* wynik dzialania
Histogram of n-bins: 6 from-to: [1-7) bins content:0 1 3 0 0 0 
Histogram of n-bins: 6 from-to: [1-7) bins content:4 4 4 4 4 3 
Histogram of n-bins: 6 from-to: [1-7) bins content:12 14 18 12 12 9 
Histogram of n-bins: 6 from-to: [1-7) bins content:12 13 15 12 12 9 
suma binow 73
suma binow po skalowaniu 36.5
suma binow po normalizacji do 1: 1
suma binow po normalizacji do 100: 100
wartosc w 2 binie: 20.5479
Histogram of n-bins: 6 from-to: [1-7) bins content:16.4384 17.8082 20.5479 16.4384 16.4384 12.3288 
 */
