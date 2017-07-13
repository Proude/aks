/*
 * PerfectPower.h
 *
 *  Created on: Jun 13, 2017
 *      Author: tasos
 */

#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <NTL/tools.h>
#include "Utilities.h"

#ifndef PERFECTPOWER_H_
#define PERFECTPOWER_H_

class PerfectPower {
public:
	PerfectPower();
    bool AlgorithmX(NTL::ZZ number);
private:
    Utilities tools;
    double AlgorithmB(int b, NTL::RR y, int k);
    double AlgorithmN(int b, NTL::RR y, int k);
    NTL::RR AlgorithmK(NTL::ZZ number, long k, NTL::RR y);
};

#endif /* PERFECTPOWER_H_ */
