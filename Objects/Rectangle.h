#pragma once
#include "Object.h"
/// \file Rectangle.h
/// \brief An implementation of a rectangle, inheriting from Object.
/// \author Phitherek_
/// \date 2012
/// \version 0.1

/// \class Rectangle
/// \brief A class that represents a rectangle and inherits from Object.
class Rectangle: public Object {
protected:
	int _x;
	int _y;
public:
	Rectangle(); ///< A constructor.
	Rectangle(int x, int y); ///< \brief A constructor with parameters
	///< \param x X size of a rectangle.
	///< \param y Y size of a rectangle.
	~Rectangle(); ///< A destructor.
	Rectangle& setSize(int x, int y); ///< \brief A function, that sets size of a rectangle.
	///< \param x X size of a rectangle.
	///< \param y Y size of a rectangle.
	///< \return A reference to changed Rectangle object.
	int& getX(); ///< \brief A function, that returns a reference to X size of a rectangle.
	///< \return A reference to X size of a rectangle.
	int& getY(); ///< \brief A function, that returns a reference to Y size of a rectangle.
	///< \return A reference to Y size of a rectangle.
	void draw(); /// A function, that draws a rectangle.
};
