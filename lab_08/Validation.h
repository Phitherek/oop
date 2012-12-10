#ifndef validation_h
#define validation_h
/**
 * @class Validation bazowa klasa do walidacji
 **/
struct Validation {
  /**
   * @brief Metoda sprawdzajaca poprawnosc
   * @return true jesli napis jest poprawny, false jesli napis nie jest
   **/
  virtual bool check(const std::string& s) = 0;
  virtual ~Validation(){}
};


/**
 * @class Weryfikuje czy napis moze bbyc reprezentacja l. calkowitej
 **/
struct IsInt : public Validation {
  bool check(const std::string& s) {
    for ( unsigned int i = 0; i < s.size(); ++i ) {
      if ( s[i] > '9' || s[i] < '0' ) // zakres ascii liczb
	return false;
    }
    return true;
  }
};


/**
 * @class Weryfikuje czy napis zawiera tylko liczby i kropke
 **/
struct IsFloat : public Validation { 
  virtual bool check(const std::string& s) {
    for ( unsigned int i = 0; i < s.size(); ++i ) {
      if ( s[i] > '9' || s[i] < '0' ) 
	if ( s[i] != '.' )  
	  return false;
    }
    return true;
  }
};

#endif
