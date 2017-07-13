/*
 * LPF.h
 *
 *  Created on: Jun 13, 2017
 *      Author: tasos
 */

#include <list>
#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <vector>
#include <tgmath.h>
#include "PerfectPower.h"
#include "Utilities.h"

#ifndef LPF_H_
#define LPF_H_

class LPF {
public:
	LPF();
	long largest_prime_factor(int n);
	NTL::ZZ combination(long a, long b);
	std::list<long> primeFactors(int s);
	NTL::RR combination(double a, double b);
	NTL::RR gammaFunction(double n);
private:
	Utilities tools;
	double lanczos_coef[9] =
	{ 0.99999999999980993, 676.5203681218851, -1259.1392167224028,
	  771.32342877765313, -176.61502916214059, 12.507343278686905,
	-0.13857109526572012, 9.9843695780195716e-6, 1.5056327351493116e-7 };
	double log_sqrt_two_pi = 0.91893853320467274178;
};

#endif /* LPF_H_ */
