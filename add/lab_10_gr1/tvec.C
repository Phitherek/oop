// kontener typu wektor z optymalizowanym operatorem =
//
// Nalze napisac klase SWektor taka ktora ma dwie metody
// at(index) zwracajaca reference do i-tego  elemenu (mozemy ustawic jego wartosc dzieki temu
// size() zwracjaca rozmiar tego wektora
// i operator kopiujacy.
//
// Dwie klasy ktore bedziemy skladowac w tym kontenerze definuja typ wbudowany
// pod_type albo jako is_pod albo jako is_not_pad. W zlaznosci od tego jaki 
// jest ten typ konstruktor powinien kopiowac z uzyciem operacji przypisania albo z uzyciem
// memcpy (gdzie, skad, ilosc_bajtow); (#include <string.h>)
//
// -Wall -g nie zmieniamy tego pliku (nawet rozszezenia prosze nie zmieniac).
//

#include <iostream>
#include "SVector.H"

struct SimpleClass {
  typedef is_pod pod_type;

  SimpleClass() : data(0) {}

  SimpleClass& operator=(const SimpleClass& lhs) {
    std::cout  << " Dzialania tego operatora nie chcemy widziec " << std::endl;
    data = lhs.data;
    return *this;
  }
  int data;
};


struct TestClass {
  typedef is_not_pod pod_type;

  TestClass () : m_data(0) { }

  TestClass (const char* a) {
    m_data = new char[strlen(a)+1];
    strcpy(m_data, a);
  }
  
  operator const char*() {
    return m_data;
  }

  void operator= (const char* x) {
    delete m_data;
    m_data = new char[strlen(x)+1];
    strcpy(m_data, x);
  }

  TestClass& operator= (const TestClass& x) {
    m_data = new char[strlen(x.m_data)+1];
    strcpy(m_data, x.m_data);
    return *this;
  }

  ~TestClass() {
    delete m_data;
  }

  void capitalize() {
    for (unsigned int i = 0; i < strlen(m_data); ++i) {
      m_data[i] = toupper(m_data[i]);      
    }
  }
  char* m_data;
};

int main() {
  SVector<SimpleClass> a(7);
  for ( int i = 0; i < a.size(); ++i ) 
    a.at(i).data = i;
  SVector<SimpleClass> b(a);
  
  SVector<TestClass>  c(4);
  c.at(0) = "To";
  c.at(1) = " nie jest ";
  c.at(2) = " trudne  ";
  c.at(3) = " zadanie ";
  std::cout  << " robimy kopie " << std::endl;
  SVector<TestClass>  d(c); // konstruktor kopiujacy 
  c.at(1) = " jednak jest ";

  std::cout  << " wypisujemy kopie "  << d.size() << std::endl;
  for (int i = 0; i < d.size(); ++i)
    std::cout << d.at(i);
  std::cout << std::endl;





}
/* wynik
 robimy kopie 
 wypisujemy kopie 4
To nie jest  trudne   zadanie 

 */
