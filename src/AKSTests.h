/*
 * AKSTests.h
 *
 *  Created on: Jul 6, 2017
 *      Author: tasos
 */

#include <extensions/HelperMacros.h>
#include "AKS.h"

#ifndef AKSTESTS_H_
#define AKSTESTS_H_

class AKSTests : public CppUnit::TestCase{
public:
	AKSTests();
	virtual ~AKSTests();
	void returnTrueIfPhiIsCorrect();
	void returnTrueIfPrimitiveRootModuloFound();
private:
	CPPUNIT_TEST_SUITE(AKSTests);
	CPPUNIT_TEST(returnTrueIfPhiIsCorrect);
	CPPUNIT_TEST(returnTrueIfPrimitiveRootModuloFound);
	CPPUNIT_TEST_SUITE_END();
};

#endif /* AKSTESTS_H_ */
