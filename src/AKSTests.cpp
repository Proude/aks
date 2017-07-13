/*
 * AKSTests.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: tasos
 */

#include "AKSTests.h"

AKSTests::AKSTests() {
	// TODO Auto-generated constructor stub

}

AKSTests::~AKSTests() {
	// TODO Auto-generated destructor stub
}

void AKSTests::returnTrueIfPhiIsCorrect()
{
	AKS aks(NTL::ZZ(10));
	CPPUNIT_ASSERT(2 == aks.phi(NTL::ZZ(6)));
	CPPUNIT_ASSERT(130 == aks.phi(NTL::ZZ(131)));
}

void AKSTests::returnTrueIfPrimitiveRootModuloFound()
{
	AKS aks(NTL::ZZ(761));
	std::cout << aks.primitiveModulo() << std::endl;
	CPPUNIT_ASSERT(6 == aks.primitiveModulo());
}
