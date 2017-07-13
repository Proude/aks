/*
 * Congruence.cpp
 *
 *  Created on: Jun 27, 2017
 *      Author: tasos
 */

#include "Congruence.h"

Congruence::Congruence(NTL::ZZ number, long r, long a) {
	// TODO Auto-generated constructor stub
	NTL::ZZ a_ZZ = NTL::conv<NTL::ZZ>(a);
	for (NTL::ZZ i(0), j(number); i != number; i++, j--)
	{
		i++;
	}
}

Congruence::~Congruence() {
	// TODO Auto-generated destructor stub
}

