/*
 * PerfectPower.h
 *
 *  Created on: Jun 13, 2017
 *      Author: tasos
 */

#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <NTL/tools.h>

#ifndef PERFECTPOWER_H_
#define PERFECTPOWER_H_

class PerfectPower {
public:
    bool AlgorithmX(NTL::ZZ number);
    inline double log2(NTL::ZZ number) { return NTL::conv<double>(NTL::log(number) / log(2)); }
    inline double log2(NTL::RR number) { return NTL::conv<double>(NTL::log(number) / log(2)); }
    inline double log2(int number) {return log(number) / log(2);}
private:
    double AlgorithmB(int b, NTL::RR y, int k);
    double AlgorithmN(int b, NTL::RR y, int k);
    NTL::RR AlgorithmK(NTL::ZZ number, long k, NTL::RR y);
};

#endif /* PERFECTPOWER_H_ */
