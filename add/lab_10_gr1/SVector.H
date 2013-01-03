#ifndef _SVECTOR_H
#define _SVECTOR_H
#include <cstring>
/// \file SVector.H
/// \brief A Vector class with optimized = operator.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class SVector
/// \brief A vector class with optimized = operator.
template<typename T> class SVector {
private:
pod_type *_container; ///< A dynamic container of user typedef'd pod_type objects.
public:
typedef struct {
T val; ///< Value
bool pod = true; ///< Is pod?
} is_pod; ///< A typedef for pod types.
typedef struct {
T& val; ///< Value
bool pod = false; ///< Is pod?
} is_not_pod; ///< A typedef for not pod types.
SVector(); ///< A constructor.
~SVector(); ///< A destructor.
SVector(SVector& obj); ///< \brief A copy constructor.
///< \param obj An object to be copied.
SVector operator=(SVector& obj); ///< \brief A copy operator=.
///< \param obj An object to be copied.
///< \return Copied SVector object.
T& at(int idx); ///< \brief A function, that allows to change specific value.
///< \param idx Index of the value.
///< \return A reference to an object of template parameter type.
int size(); ///< \brief A function, that returns size of the vector.
///< \return Size of the vector.
};
#endif
