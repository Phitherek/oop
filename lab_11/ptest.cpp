// pardsowanie, uzyteczne obiekty
//
// Bardzo czesto musimy przetwarzac strumienie tekstu i sprawdzac czy tekst odpowiada zadanemu formatowi.
// Jednoczesnie z tego tekstu musimy wybierac jakies informacje. 
// 
// W zadaniu nalzy zaimplementowac zespol przydatnych obiektow, 
// ktore pomoga nam w sprawdzaniu formatu.
// Obiekty te wybieraja ze strumienia jedno slowo i w zanleznosci od tego czy format jest odpowiedni
// ustawiaja status strumienia na nieczytalny (badbit).
// Te obiekty to: Exact - wymagamy dokadnego dopasowania
// Contains - wyczytane slowo musi zawierac wzorzec
// StartsWith - wyczytane slowo ze strumienia zawiera szukane slowo na poczatku
// Anything - colkolwiek pasuje
//
// Kompilowac do pliku ptest z opcjami -Wall -g
//


#include <iostream>
#include <sstream>

#include "ParsingUtils.h"
#include "StaticArray.h" // prosta struktura zbierajaca w jednym miejscu rozmiar i dane
using namespace std;



int main() {

  static_array<std::string, 3> napisy;
  napisy.data[0] = "Ala ma 5 kotow w 2000 roku i 2 psy";
  napisy.data[1] = "Ala ma 2 koty w 2005 roku i 4 fretki";
  napisy.data[2] = "Ala miala 1 kota w 2007 roku i 7 rybek";
  
  int liczba_kotow;
  int liczba_innych;
  int rok;
  for ( unsigned n = 0; n < napisy.size ; ++n ) {
    istringstream ss(napisy.data[n]);
    if ( ss 
	 >> Exact("Ala") 
	 >> Exact("ma") 
	 >> liczba_kotow 
	 >> Contains("kot") 
	 >> Exact("w") 
	 >> rok 
	 >> Contains("rok") 
	 >> Exact("i") 
	 >> liczba_innych 
	 >> Anything() ) {
      cout << "Liczba kotow: " << liczba_kotow << " Rok: " << rok << endl;
    } else {
      cout << "Blad w formacie napisu: " << napisy.data[n] << endl;
    }
  }
}

