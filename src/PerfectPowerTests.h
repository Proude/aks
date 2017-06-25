/*
 * PerfectPowerTests.h
 *
 *  Created on: Jun 18, 2017
 *      Author: tasos
 */

#include <extensions/HelperMacros.h>
#include "PerfectPower.h"
#include <vector>

#ifndef PERFECTPOWERTESTS_H_
#define PERFECTPOWERTESTS_H_

class PerfectPowerTests : public CppUnit::TestCase{
public:
	PerfectPowerTests();
	virtual ~PerfectPowerTests();
	void ReturnTrueIfAllArePerfectPowers();
	void ReturnTrueIfAllAreNotPerfectPowers();
private:
	std::vector<long int> perfectPowers = {4, 8, 9, 16, 25, 27, 36, 49, 64, 81, 100, 121, 125, 144, 169, 196, 216, //
			225, 243, 256, 289, 324, 343, 361, 400, 512, 625, 729, 1000, 1024, 1296, 1000000, 1000000000, 1000000000000};
	std::vector<long int> notPerfectPowers = {3, 7, 10, 11, 12, 13, 24, 28, 35, 44, 63, 80, 99, 120, 124, 140, 150, //
			182, 200, 201, 226, 247, 252, 290, 401, 500, 600, 700, 800, 905, 1001, 1002, 10000001, 10000000000001};
	CPPUNIT_TEST_SUITE(PerfectPowerTests);
	CPPUNIT_TEST(ReturnTrueIfAllArePerfectPowers);
	CPPUNIT_TEST(ReturnTrueIfAllAreNotPerfectPowers);
	CPPUNIT_TEST_SUITE_END();
};

#endif /* PERFECTPOWERTESTS_H_ */
