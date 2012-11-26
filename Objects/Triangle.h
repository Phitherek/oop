#pragma once
#include "Object.h"
/// \file Triangle.h
/// \brief An implementation of a triangle, inheriting from Object.
/// \author Phitherek_
/// \date 2012
/// \version 0.1

/// \class Triangle
/// \brief A class representing a triangle that inherits from Object.
class Triangle: public Object {
private:
	int _a;
	int _h;
public:
Triangle(); ///< A constructor.
Triangle(int a, int h); ///< \brief A constructor with parameters.
///< \param a A size of the bottom line.
///< \param h The height from that line.
~Triangle(); ///< A destructor.
Triangle& setSize(int a, int h); ///< \brief A function that sets size of the triangle.
///< \param a A size of the bottom line.
///< \param h The height from that line.
///< \return A reference to changed Triangle object.
int getA(); ///< \brief A function that returns size of the bottom line.
///< \return Size of the bottom line.
int getH(); ///< \brief A function that returns height.
///< \return Height.
void draw(); ///< A function, that outputs some information about triangle.
};
