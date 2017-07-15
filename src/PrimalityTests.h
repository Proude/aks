/*
 * PrimalityTests.h
 *
 *  Created on: Jun 26, 2017
 *      Author: tasos
 */

#ifndef PRIMALITYTESTS_H_
#define PRIMALITYTESTS_H_

#include "NTL/ZZ.h"
#include "NTL/vector.h"
#include <extensions/HelperMacros.h>
#include "AKS.h"
#include <sys/time.h>

class PrimalityTests : public CppUnit::TestCase {
public:
	PrimalityTests();
	virtual ~PrimalityTests();
	void setUp();
	void CheckPrimeNumbers();
	void CompareAlgorithms();
	void returnTrueIfTheNumberIsPrime();
private:
	NTL::Vec<NTL::ZZ> primes;
	CPPUNIT_TEST_SUITE(PrimalityTests);
//	CPPUNIT_TEST(CheckPrimeNumbers);
	CPPUNIT_TEST(returnTrueIfTheNumberIsPrime);
//	CPPUNIT_TEST(CompareAlgorithms);
	CPPUNIT_TEST_SUITE_END();
};

#endif /* PRIMALITYTESTS_H_ */
