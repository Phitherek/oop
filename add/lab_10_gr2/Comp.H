#ifndef _COMP_H
#define _COMP_H
/// \file Comp.H
/// \brief Implementations of computing templates.
/// \author Piotr Żurek
/// \date 2012

/// \class pow
/// \brief A template class parametrized by two integer values - base and power - that computes power of the integer.
template<int x, int y> class pow {
public:
static unsigned int value; ///< A result of the computation.
};

/// \class sum_to
/// \brief A template class parametrized by an integer value that computes sum of the integer values from 1 to the parameter.
template<int x> class sum_to {
public:
static int value; ///< A result of the computation.
};

/// \class sum_to
/// \brief A template class parametrized by two integer values - bottom and top of the range - that computes sum of the integer values from the bottom parameter to the top parameter.
template<int x, int y> class sum_from_to {
public:
static int value; ///< A result of the computation.
};

///< \fn pow_fun
///< \brief A function, that returns power of an integer.
///< \param x Base of the power.
///< \param y Value of the power.
///< \return Result of the computation.
unsigned int pow_fun(int x, int y) {
unsigned int value = x;
for(int i = 1; i < y; i++) {
value *= x;	
}
return value;
}

template<int x, int y> unsigned int pow<x, y>::value = pow_fun(x, y);

///< \fn sum_to_fun
///< \brief A function that computes sum of integer values from 1 to parameter x.
///< \param x A integer.
///< \return Result of the computation.
int sum_to_fun(int x) {
int value = 0;
for(int i = 1; i <= x; i++) {
value += i;
}
return value;
}

template<int x> int sum_to<x>::value = sum_to_fun(x);

///< \fn sum_from_to_fun
///< \brief A function that computes sum of integer values from parameter x to parameter y.
///< \param x Bottom integer value.
///< \param y Top integer value.
///< \return Result of the computation.
int sum_from_to_fun(int x, int y) {
int value = 0;
for(int i = x; i <= y; i++) {
value += i;	
}
return value;
}

template<int x, int y> int sum_from_to<x, y>::value = sum_from_to_fun(x, y);
#endif
