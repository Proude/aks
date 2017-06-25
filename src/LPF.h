/*
 * LPF.h
 *
 *  Created on: Jun 13, 2017
 *      Author: tasos
 */

#include <list>
#include <iostream>
#include <NTL/ZZ.h>

#ifndef LPF_H_
#define LPF_H_

class LPF {
public:
	LPF(long number);
	long largest_prime_factor();
	NTL::ZZ combination(long a, long b);
private:
	long n;
};

#endif /* LPF_H_ */
