#include <string>
/// \file BadSizeException.h
/// \brief An implementation of a Bad Size exception
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class BadSizeException
/// \brief An exception, when bad size of an object has been entered.
class BadSizeException {
private:
	std::string _size;
	std::string _obj;
public:
	BadSizeException(); ///< A constructor.
	BadSizeException(std::string size, std::string object); ///< \brief A constructor with string parameters.
	///< \param size A type of size to set.
	///< \param object A type of object to set.
	std::string& getSize(); ///< \brief A function that returns and allows change of type of size.
	///< \return A reference to a type of size std::string.
	std::string& getObject(); ///< \brief A function that returns and allows change of type of object.
	///< \return A reference to a type of object std::string.
};
