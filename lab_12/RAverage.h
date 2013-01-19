#ifndef _RAVERAGE_H
#define _RAVERAGE_H
/// \file RAverage.h
/// \brief A class computing the running average.
/// \author Piotr Żurek
/// \date 2013
/// \version 0.1

#include <deque> // Uzasadnienie: Ponieważ kontener ma mieć określoną wielkość i pierwszy element z dołu ma wypadać przy przepełnieniu, najlepsza byłaby kolejka FIFO, ale ponieważ po kontenerze queue nie da się iterować, to najlepszy będzie deque.
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>
#include <numeric>
#include <sstream>


///< \class RAverage
///< \brief A class computing running average.
template<typename T, int size> class RAverage {
private:
	std::deque<T> _cont;
	int _size;
	int _limit;
public:	
	RAverage(); ///< A constructor.
	~RAverage(); ///< A destructor.
	template<typename U, int newsize> friend std::ostream&
	operator<<(std::ostream& out, RAverage<U, newsize> ra); ///< \brief A friend function - operator<<, that sends computed average to output stream.
	///< \param out Output stream.
	///< \param ra RAverage object.
	///< \return Output stream.
	RAverage<T, size>& operator<<(T obj); ///< \brief An operator<<, that adds an object to the container.
	///< \param obj An object of template parameter type T.
	///< \return A reference to RAverage object,
	std::string dump(); ///< \brief A function dumping container content.
	///< \return Container content as std::string.
	int n_above(T obj); ///< \brief A function computing how many objects in the container are above certain value.
	///< \param obj An object for comparison.
	///< \return Number of objects above given value.
	int n_below(T obj); ///< \brief A function computing how many objects in the container are below certain value.
	///< \param obj An object for comparison.
	///< \return Number of objects below given value.
	operator double(); ///< Double conversion operator.
};

///< \class nacheck
///< \brief A helper predicate for n_above function.
template<typename T> class nacheck {
private:
	T _crit;
public:
	nacheck(T crit) {
	_crit = crit;	
	}
	~nacheck() {
	_crit = 0;	
	}
	bool operator()(T obj) {
		return obj > _crit;
	}
};

///< \class nbcheck
///< \brief A helper predicate for n_below function.
template<typename T> class nbcheck {
private:
	T _crit;
public:	
	nbcheck(T crit) {
	_crit = crit;	
	}
	~nbcheck() {
	_crit = 0;	
	}
	bool operator()(T obj) {
		return obj < _crit;
	}
};

template<typename T, int size> RAverage<T, size>::RAverage() {
	_size = 0;
	_limit = size;
	std::deque<T> tempcont(size, 0);
	_cont = tempcont;
}

template<typename T, int size> RAverage<T, size>::~RAverage() {
	_size = 0;
	_limit = 0;
	std::deque<T> tempcont(size, 0);
	_cont = tempcont;
}

template<typename T, int size> RAverage<T, size>& RAverage<T, size>::operator<<(T obj) {
	_cont.pop_front();
	_cont.push_back(obj);
	if(_size+1 <= _limit) {
	_size++;	
	}
	return *this;	
}

template<typename T, int size> std::string RAverage<T, size>::dump() {
	std::stringstream ss;
	typename std::deque<T>::iterator iter;
	for(iter=_cont.begin(); iter != _cont.end(); iter++) {
	ss << *iter << ", ";	
	}
	return ss.str();
}

template<typename T, int size> int RAverage<T, size>::n_above(T obj) {
	nacheck<T> checker(obj);
	int count;
	count = std::count_if(_cont.begin(), _cont.end(), checker);
	return count;	
}

template<typename T, int size> int RAverage<T, size>::n_below(T obj) {
	nbcheck<T> checker(obj);
	int count;
	count = std::count_if(_cont.begin(), _cont.end(), checker);
	return count;	
}

template<typename T, int size> RAverage<T, size>::operator double() {
	T sum = 0;
	sum = std::accumulate(_cont.begin(), _cont.end(), sum);
	return static_cast<double>(static_cast<double>(sum)/static_cast<double>(_size));
}

template<typename T, int size> std::ostream& operator<<(std::ostream& out, RAverage<T, size> ra) {
	T sum = 0;
	sum = std::accumulate(ra._cont.begin(), ra._cont.end(), sum);
	out << static_cast<double>(static_cast<double>(sum)/static_cast<double>(ra._size));
	return out;	
}
	
#endif
