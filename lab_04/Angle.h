#ifndef ANGLE_H
#define ANGLE_H
/// \file Angle.h
/// \brief An implementation of the angle.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1
#include <iostream>

/// \class Angle
/// \brief A class representing an angle.
class Angle {
private:
float _val;
Angle();
public:
	friend std::ostream& operator<<(std::ostream& o, const Angle& a);
static Angle fromRadians(float rad); ///< \brief A named constructor, that creates an angle with value in radians.
///< \param rad A value of an angle in radians.
static Angle fromDegrees(int deg); ///< \brief A named constructor, that created an angle with value in degrees.
///< \param deg A value of an angle in degrees.
Angle add(Angle a); ///< \brief A function, that adds an angle to the existing angle.
///< \param a An angle to be added.
///< \return A modified Angle object.
static Angle distance(Angle a1, Angle a2); ///< \brief A function calculating the difference between angles.
///< \param a1 First angle.
///< \param a2 Second angle.
///< \return An Angle object that represents the difference between angles.
float toDeg(); ///< \brief A function converting radians to degrees.
///< \return Value of the angle in degrees.
operator double() const; ///< \brief A converting operator double(), that converts angle value to double.
};
std::ostream& operator<<(std::ostream& o, const Angle& a); ///< \brief A operator<< which can be used to print out the angle value to cout.
///< \param a An angle to be printed out.
///< \param o An output stream.
///< \return An reference to std::ostream.
#endif
