/*
 * LPFTests.h
 *
 *  Created on: Jul 5, 2017
 *      Author: tasos
 */

#include <extensions/HelperMacros.h>
#include "LPF.h"

#ifndef LPFTESTS_H_
#define LPFTESTS_H_

class LPFTests : public CppUnit::TestCase {
public:
	LPFTests();
	virtual ~LPFTests();
	void returnsTrueIfGammaFunctionReturnsCorrectResult();
	void returnsTrueIfCombinationReturnsCorrectResult();
private:
	LPF lpf;
	CPPUNIT_TEST_SUITE(LPFTests);
	CPPUNIT_TEST(returnsTrueIfGammaFunctionReturnsCorrectResult);
	CPPUNIT_TEST(returnsTrueIfCombinationReturnsCorrectResult);
	CPPUNIT_TEST_SUITE_END();
};

#endif /* LPFTESTS_H_ */
