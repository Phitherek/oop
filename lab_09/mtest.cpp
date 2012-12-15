// Szablon tablicy asocjacyjnej
//
//
// W zadaniu nalezy napisac szablon klasy tablicy asocjacyjnej gdzie 
// typ klucza i typ wartosci sa argumentami szablonu.
//
//
// Implementacja wnetrza moze byc prosta np. lista lub tablica rozszerzana podczas kazdej 
// operacji insert() (badz podczas odwolania sie za pomoca [])
// Moze wewnatrz przydala by sie jakas struktora pomocnicza? 
//
// Prosze nie zmieniac nazwy tego pliku bo zmienia sie numer linii.
// Prosze koniecznie kompilowac z opcja -Wall -g. 
//

#include <iostream>
#include <string>
#include <stdexcept>
#define CONTEXT "file:"<<__FILE__<<" line:"<<__LINE__<< ": "

#include "Map.h"


int main() {
  using namespace std;
  Map<std::string, int> m;
  m.insert("hello", 400909990 ); 
  m.insert("hello2", 509099900 ); 
  m.print(".. przed nadpisaniem");
  m["hello3"] = 7887; // inny sposob dodania
  m["hello2"] = 7;
  m.print(".. po nadpisaniu");

  const Map<std::string, int>& cm = m;  
  cout << CONTEXT << "Co tam pod hello2 " << cm["hello2"] << endl;
  cout << CONTEXT << "Czy jest hello4 " << cm.contains("hello4") << endl;
  cout << CONTEXT << "Czy jest hello3 " << cm.contains("hello3") << endl;
  m["niema"];// proba wyciagniecia elementu ze Map
  try {

    cm["niema_znowu"]; // proba wyciagniecia nieistniejacego elementu z const Map skutkuje wyjatkiem
  }catch (const std::invalid_argument& e) {
    cout << CONTEXT << e.what() << endl;
  }

  Map<int, std::string> inv;
  inv[0] = "pod zerem";
  inv[2] = "pod dwokja";
  inv.print("odwrotna mapa");
}

/* wyniki
.. przed nadpisaniem k: hello v: 400909990
.. przed nadpisaniem k: hello2 v: 509099900
.. po nadpisaniu k: hello v: 400909990
.. po nadpisaniu k: hello2 v: 7
.. po nadpisaniu k: hello3 v: 7887
file:mtest.C line:35: Co tam pod hello2 7
file:mtest.C line:36: Czy jest hello4 0
file:mtest.C line:37: Czy jest hello3 1
file:mtest.C line:43: Klucz nieodpowiedni
odwrotna mapa k: 0 v: pod zerem
odwrotna mapa k: 2 v: pod dwokja

 */
