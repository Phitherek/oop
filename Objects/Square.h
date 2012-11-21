#pragma once
#include "Rectangle.h"

/// \file Square.h
/// \brief An implementation of a square, inheriting from Rectangle, inheriting from Object.
/// \author Phitherek_
/// \date 2012
/// \version 0.1

/// \class Square
/// \brief A class representing a square that inherits from Rectangle.
class Square: public Rectangle {
public:
Square(); ///< A constructor.
Square(int x); ///< \brief A constructor with parameter.
///< \param x Size of a square.
~Square(); ///< A destructor.
Square& setSize(int x); ///< \brief A function that sets size of a square.
///< \param x Size of a square.
///< \return A reference to changed Square object.
int getSize(); ///< \brief A function that returns size of a square.
///< \return Size of a square.
};
