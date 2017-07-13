/*
 * Congruence.h
 *
 *  Created on: Jun 27, 2017
 *      Author: tasos
 */

#include "NTL/vector.h"
#include "NTL/ZZ.h"
#include <vector>

#ifndef CONGRUENCE_H_
#define CONGRUENCE_H_

class Congruence {
public:
	Congruence(NTL::ZZ number, long r, long a);
	virtual ~Congruence();
private:
	std::vector<NTL::ZZ> lhs_coeff;
	std::vector<NTL::ZZ> lhs_exponent;
	std::vector<NTL::ZZ> rhs_coeff;
	std::vector<NTL::ZZ> rhs_exponent;
};

#endif /* CONGRUENCE_H_ */
