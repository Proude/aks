/*
 * Utilities.h
 *
 *  Created on: Jul 5, 2017
 *      Author: tasos
 */

#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <cmath>

#ifndef UTILITIES_H_
#define UTILITIES_H_

class Utilities {
public:
	Utilities();
	virtual ~Utilities();
    double log2(NTL::ZZ number) { return NTL::conv<double>(NTL::log(number) / std::log(2)); }
    double log2(NTL::RR number) { return NTL::conv<double>(NTL::log(number) / std::log(2)); }
    double log2(int number) { return std::log(number) / std::log(2); }
    double ln(double number) { return std::log(number) / std::log(M_E); }
    NTL::RR power(double a, double b) { return NTL::exp(NTL::RR(b * ln(a))); }
};

#endif /* UTILITIES_H_ */
