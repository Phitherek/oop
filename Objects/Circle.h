#pragma once
#include "Object.h"
/// \file Object.h
/// \brief An implementation of a circle, inheriting from Object.
/// \author Phitherek_
/// \date 2012
/// \version 0.1

/// \class Circle
/// \brief A class representing a circle that inherits from Object.
class Circle: public Object {
private:
_r;
public:
Circle(); ///< A constructor.
Circle(int r); ///< \brief A constructor with parameter.
///< \param r Radius of the circle.
~Circle(); ///< A destructor.
Circle& setR(int r); ///< \brief A function, that sets radius of a circle.
///< \param r Radius of the circle.
///< \return A reference to a modified Circle object.
int getR(); ///< \brief A function, that returns radius of a circle.
///< \return A radius of the circle.
void draw(); ///< A function, that outputs some information about circle.
};
