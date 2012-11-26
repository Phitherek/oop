#pragma once
#include <string>
/// \file Object.h
/// \brief An implementation of the base class for objects.
/// \author Phitherek_
/// \date 2012
/// \version 0.1

/// \class Object
/// \brief A base class for objects

class Object {
protected:
	std::string _desc; ///< Description of the object,
public:
	Object(); ///< A constructor.
	~Object(); ///< A destructor.
	Object& setDesc(std::string desc); ///< \brief A function, that sets a desctription of an object.
	///< \param desc A description to be set.
	///< \return A reference to an Object object with changed description.
	std::string getDesc(); ///< \brief A function, that returns the description of an object.
	///< \return A description of an object.
	virtual void draw(); ///< A virtual draw function needed for inheriting classes.
};
