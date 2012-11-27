#include <string>
/// \file BadChoiceException.h
/// \brief An implementation of a Bad Choice exception
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class BadChoiceException
/// \brief An exception, when bad choice of object or option has been made.
class BadChoiceException {
private:
	std::string _msg;
public:
	BadChoiceException(); ///< A constructor.
	BadChoiceException(std::string msg); ///< \brief A constructor with string parameter.
	///< \param msg Error message to set.
	std::string what(); ///< \brief Function returning error message.
	///< \return Error message
	void setMsg(std::string msg); ///< \brief Function setting error message.
	///< \param msg Error message to set.
};
