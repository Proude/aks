/*
 * UtilitiesTests.h
 *
 *  Created on: Jul 5, 2017
 *      Author: tasos
 */

#include <extensions/HelperMacros.h>
#include "Utilities.h"

#ifndef UTILITIESTESTS_H_
#define UTILITIESTESTS_H_

class UtilitiesTests : public CppUnit::TestCase {
public:
	UtilitiesTests();
	virtual ~UtilitiesTests();
	void returnsTrueIfPowerReturnsTheRightResult();
private:
	Utilities tools;
	CPPUNIT_TEST_SUITE(UtilitiesTests);
	CPPUNIT_TEST(returnsTrueIfPowerReturnsTheRightResult);
	CPPUNIT_TEST_SUITE_END();
};

#endif /* UTILITIESTESTS_H_ */
