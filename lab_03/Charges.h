#ifndef _Charges_h
#define _Charges_h
//! \file Charges.h
//! \brief An implementation of a class, that represents a set of charges.
//! \author Piotr Żurek
//! \date 2012

//! \def PI
//! \brief This defines a pi constant.
#define PI 3.14

//! \struct Charge
//! \brief A structure representing a single charge on the list.
struct Charge {
int x; //!< x position of the charge.
int y; //!< y position of the charge.
int val; //!< Value of the charge.
Charge *next; //!< A pointer to next charge on the list.
};
//! \class Charges
//! \brief A class representing a set of charges.
class Charges {
private:
Charge *_list; //!< A head of the list of charges.
float _epsilon; //!< A modifiable dielectrical constant of material.
const float _epsilon_zero = 1.; //!< Dielectrical constant of vacuum.
public:
	Charges(); //!< A constructor initialising the Charges class.
	~Charges(); //!< A destructor freeing the memory in the Charges class.
	void add(int x, int y, int val); //!< A function adding new charge to the list.
	int n(); //!< A function returning number of charges on the list.
	float force(int nx, int ny, int nval); //!< A function returning value of a force on a given charge.
	float& epsilon(); //!< A function allowing user to change dielectrical constant of material.
};
#endif
