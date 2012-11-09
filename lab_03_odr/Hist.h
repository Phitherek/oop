#ifndef HIST_H
#define HIST_H
/// \file Hist.h
/// \brief An implementation of histogram.
/// \author Piotr Żurek
/// \date 08-11-2012
/// \version 0.1

/// \class Hist
/// \brief A class that represents a histogram.
class Hist {
private:
int _n;
float _min;
float _max;
float *_bins;
public:
Hist(int n, float min, float max); ///< \brief A constructor with parameters.
///< \param n Number of bins.
///< \param min Minimum of histogram range.
///< \param max Maximum of histogram range.
~Hist(); ///< \brief A destructor.
Hist(const Hist &h); ///< \brief A copying constructor to avoid memory errors.
Hist& fill(int n); ///< \brief A function, that adds events to histogram.
///< \param n Value of an event.
///< \return A modified Hist object.
static void print(Hist h); ///< \brief A function, that prints out histogram data.
///< \param h A Hist object to be printed.
static const Hist add(const Hist h1, const Hist h2, int mult1, int mult2); ///< \brief A function, that adds two histograms.
///< \param h1 First const Hist object to be added.
///< \param h2 Second const Hist object to be added.
///< \param mult1 First multiplicator.
///< \param mult2 Second multiplicator.
///< \return A new const Hist object, which contains the result of calculation.
float integral(); ///< \brief A function, that computes sum of histogram bins.
///< \return A sum of histogram bins, of type float.
Hist scale(float f); ///< \brief A function, that scales the histogram by float digit.
///< \param f A float digit, by which the histogram will be scaled.
///< \return A modified Hist object.
Hist normalize(float f); ///< \brief A function, that normalizes the histogram to a float digit.
///< \param f A float digit, to which the histogram will be normalized.
///< \return A modified Hist object.
Hist normalize(); ///< \brief A function, that normalizes the histogram to 1.
///< \return A modified Hist object.
float binContent(int i); ///< \brief A function, that prints out a value of a given bin.
///< \param i A number of bin to be printed.
///< \return A value of a given bin, of type float.
};
#endif
