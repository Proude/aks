/*
 * UtilitiesTests.cpp
 *
 *  Created on: Jul 5, 2017
 *      Author: tasos
 */

#include "UtilitiesTests.h"

UtilitiesTests::UtilitiesTests() {
	// TODO Auto-generated constructor stub
	tools = Utilities();
}

UtilitiesTests::~UtilitiesTests() {
	// TODO Auto-generated destructor stub
}

void UtilitiesTests::returnsTrueIfPowerReturnsTheRightResult()
{
	CPPUNIT_ASSERT(NTL::abs(256 - tools.power(2, 8)) < 0.00000001);
}

