//============================================================================
// Name        : AKS.cpp
// Author      : Anastasios Gemtos
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
#include "AKS.h"

using namespace std;
using namespace CppUnit;

CPPUNIT_TEST_SUITE_REGISTRATION(PerfectPowerTests);

//int main() {
//	CppUnit::TextUi::TestRunner runner;
//	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
//	runner.addTest(registry.makeTest());
//	runner.run();
//	return 0;
//}

int main() {

	NTL::ZZ a;

    std::cout << "Give a number to test" << std::endl;
    std::cin >> a;

    AKS aks(a);
    if (aks.AKSAlgorithm())
    	std::cout << "Number " << a << " is prime" << std::endl;
    else
    	std::cout << "Number " << a << " is composite" << std::endl;

    return 0;
}
