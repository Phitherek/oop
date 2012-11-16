// Tablica asocjacyjna
//
// To taka tablica, ktorej indeksy sa nieograniczone do kolejnych liczb calkowitych
//  0...N a nawet nie musza byc liczbami. 
// W zadaniu nalezy napisac tablice asocjacyjna gdzie indeksem jest napis 
// (wybiegamy w przyszlosc, prosze uzyc klasy string).
// a wartosci sa dwojakiego typu albo int albo short.
//
// Aby taka pozyteczna funkcjonalnosc jak tablica asocjacyjna moc uzywac pozniej
// tablica zaimplementowana ma byc z uzyciem ogolnych typow map_key_value (indeks)
// i map_value_type(wartosci).
// Przed "zainkludowaniem" naglowka trzeba zdefiniowac jakie to sa typy. 
// Tu string i short|int.
// 
// Aby pokazac jakie kozysci mozna wyciagnac z takiego uogolnienia
// skompilujemy program wymieniajac typ zmiennych map_value_type
// Najprosciej mozna to zrobic tak:
// W makefile dodac zmienna: OPT=Nic
// i zdefiniowac CXXFLAGS=-Wall -g -D$(OPT)   
// Wtedy kompilacja poleceniem:
//            make OPT=INT_VAL
// powoduje ustawienie zmiennej preprocesora INT_VAL i nasz program powinien 
// sie skompilowac z typem "int" (na podstawie ponizszej kompilacji warunkowej)
// a gdy napiszemy 
//       make
// program powinien sie skompilowac z typem short 
// i wtedy duze liczby podane w programie zostana obciete.
//
// Implementacja wnetrza moze byc prosta tablica rozszerzana podczas kazdej 
// operacji insert() (badz podczas odwolania sie za pomoca []) 
// Prosze przemyslec struktore klasy troche. 
//
// Prosze nie zmieniac nazwy tego pliku.
// Prosze koniecznie kompilowac z opcja -Wall. 
//

#include <iostream>
#include <string>

typedef std::string map_key_type;

#ifdef INT_VAL 
typedef int map_value_type;
#else
typedef short map_value_type;
#endif

#include "Map.h"


int main() {
  using namespace std;
  Map m;
  m.insert("hello", 400909990 ); // w przypadku gdyby warosci byly typu short 
  m.insert("hello2", 509099900 ); // to wtedy te duze liczby zostana uciete
  m.print(".. przed nadpisaniem");
  m["hello3"] = 7887;
  m["hello2"] = 7;
  m.print(".. po nadpisaniu");

  const Map& cm = m;  
  cout << "Co tam pod hello2 " << cm["hello2"] << endl;
  cout << "Czy jest hello4 " << cm.contains("hello4") << endl;
  cout << "Czy jest hello3 " << cm.contains("hello3") << endl;

}

/* wyniki przy kompilacji BEZ opcji OPT=INT_VAL (poprostu make)
.. przed nadpisaniem k: hello v: 26278
.. przed nadpisaniem k: hello2 v: 16252
.. po nadpisaniu k: hello v: 26278
.. po nadpisaniu k: hello2 v: 7
.. po nadpisaniu k: hello3 v: 7887
Co tam pod hello2 7
Czy jest hello4 0
Czy jest hello3 1

-- wyniki kompilacji z opcja OPT=INT_VAL  (make OPT=INT_VAL) 
.. przed nadpisaniem k: hello v: 400909990
.. przed nadpisaniem k: hello2 v: 509099900
.. po nadpisaniu k: hello v: 400909990
.. po nadpisaniu k: hello2 v: 7
.. po nadpisaniu k: hello3 v: 7887
Co tam pod hello2 7
Czy jest hello4 0
Czy jest hello3 1

 
 */
