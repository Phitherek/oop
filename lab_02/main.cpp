// struktora ulatwiajaca operacje na 2 wymiarowych tablicach
// w tym na inicializowaniu tablicy identycznymi wartosciami
// ustawianiu wartosci w zadanmym wierszu i kolumnie
// ustawianiu wartosci w zakresie tablicy
// wstrzykiwaniu jednej tablicy do drugiej
// tworzeniu nowej tablicy z fragmentu istniejacej
// listowaniu tablicy
// sprzataniu miejsca po tablicy
// program nalezy skompilowac do pliku wkonywalnego o nazwie tabtest

#include <iostream>
using namespace std;

#include "tab.h"
#include "tab.h"

int main() {
  Tab t;  
  init(&t, 7,7, 0.); // tablica 7 x 7 zainicjalizowana wartosciam 0.

  diag(&t, 3.);
  set(&t, 6, 6, 7.);
  TabRange r = {1,1, 3,3};  
  set_part(&t, r, 9.);
  print(&t);
  
  cout << "druga tablica ktora wstrzykniemy do pierwszej" << endl;
  Tab t2;
  init(&t2, 3, 3, 2.);
  set(&t2, 2, 2, 4.);
  print (&t2);
  TabRange bottom_left = {3,0, 6,3};  
  insert(&t2, &t, bottom_left);

  TabRange top_right = {0,3, 3,6};  
  insert(&t2, &t, top_right);

  cout << "po wstrzygnieciu" << endl;
  print(&t);


  cout << "wycinamy srodek (asymetrycznie) jako nowa tablice" << endl;
  TabRange center = {0,2, 6,4};  
  Tab* c = extract(&t, center);
  print(c);

  clean(c);
  clean(&t);
  clean(&t2);
  cout << "po operacji clean tablica jest pusta" << endl;
  print(&t);
}
/* Wynik
3 0 0 0 0 0 0 
0 9 9 0 0 0 0 
0 9 9 0 0 0 0 
0 0 0 3 0 0 0 
0 0 0 0 3 0 0 
0 0 0 0 0 3 0 
0 0 0 0 0 0 7 
druga tablica ktora wstrzykniemy do pierwszej
2 2 2 
2 2 2 
2 2 4 
po wstrzygnieciu
3 0 0 2 2 2 0 
0 9 9 2 2 2 0 
0 9 9 2 2 4 0 
2 2 2 3 0 0 0 
2 2 2 0 3 0 0 
2 2 4 0 0 3 0 
0 0 0 0 0 0 7 
wycinamy srodek (asymetrycznie) jako nowa tablice
0 9 9 2 2 4 
2 2 2 3 0 0 
po operacji clean tablica jest pusta

 */
