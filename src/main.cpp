//============================================================================
// Name        : AKS.cpp
// Author      : Nathanael Browne
// Version     :
// Copyright   : University of Bath
// Description : AKS algorithm in C++
//============================================================================

#include <iostream>
#include "extensions/TestFactoryRegistry.h"
#include "extensions/HelperMacros.h"
#include "ui/text/TestRunner.h"
#include "TestSuite.h"
#include "PerfectPowerTests.h"
#include "UtilitiesTests.h"
#include "LPFTests.h"
//#include "AKSTests.h"
#include "PrimalityTests.h"
#include <fstream>

using namespace std;
using namespace CppUnit;

CPPUNIT_TEST_SUITE_REGISTRATION(PerfectPowerTests);
CPPUNIT_TEST_SUITE_REGISTRATION(UtilitiesTests);
CPPUNIT_TEST_SUITE_REGISTRATION(LPFTests);
//CPPUNIT_TEST_SUITE_REGISTRATION(AKSTests);
CPPUNIT_TEST_SUITE_REGISTRATION(PrimalityTests);

//int main() {
//	CppUnit::TextUi::TestRunner runner;
//	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
//	runner.addTest(registry.makeTest());
//	runner.run();
//	return 0;
//}

int main() {
	std::string str("100003");
	NTL::ZZ number(NTL::INIT_VAL, str.c_str());
	AKS aks(number);
	struct timeval start, end;
	gettimeofday(&start, NULL);
	bool aksv3 = aks.AKSAlgorithm();
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	gettimeofday(&start, NULL);
	bool aksv3Bern = aks.AKSAlgorithm_Bernstein();
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	gettimeofday(&start, NULL);
	bool aksBern = aks.AKSAlgorithm_Bernstein_OMP();
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
//	gettimeofday(&start, NULL);
//	bool aksBern_omp = aks.AKSAlgorithm_Bernstein_OMP();
//	gettimeofday(&end, NULL);
//	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	if (aksBern && aksv3 && aksv3Bern)
		std::cout << "True" << std::endl;
	else
		exit(0);
}
