/*
 * LPFTests.cpp
 *
 *  Created on: Jul 5, 2017
 *      Author: tasos
 */

#include "LPFTests.h"

LPFTests::LPFTests() {
	// TODO Auto-generated constructor stub
	lpf = LPF();
}

LPFTests::~LPFTests() {
	// TODO Auto-generated destructor stub
}

void LPFTests::returnsTrueIfGammaFunctionReturnsCorrectResult()
{
	std::cout << lpf.gammaFunction(2) << std::endl;
	CPPUNIT_ASSERT(NTL::abs(lpf.gammaFunction(2) - 1) < 0.000001);
}

void LPFTests::returnsTrueIfCombinationReturnsCorrectResult()
{
	CPPUNIT_ASSERT(NTL::abs(lpf.combination(3000.0, 3.0) - 4495501000.0) < 0.01);
}
