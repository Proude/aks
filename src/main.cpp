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

int main() {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	runner.run();
	return 0;
}

//int main() {
//
//	NTL::ZZ a;
////	std::ofstream file;
//
//    std::cout << "Give a number to test" << std::endl;
//    std::cin >> a;
//    AKS aks(a);
//    double result = 0;
////    file.open("test.txt", std::ios::app);
////    for (NTL::ZZ i(a); true; i++)
////    {
////    	aks.setNumber(i);
////		clock_t begin = clock();
////		if (aks.AKSAlgorithm_Bernstein())
////			file << "Number " << i << " is prime" << std::endl;
////		else
////			file << "Number " << i << " is composite" << std::endl;
////		clock_t end = clock();
////		result = double(end - begin) / CLOCKS_PER_SEC;
////		std::cout << "AKS_v3 clock = " << result << std::endl;
////    }
////    file.close();
////    AKS aks(a);
////    if (aks.AKSAlgorithm())
////    	std::cout << "Number " << a << " is prime" << std::endl;
////    else
////    	std::cout << "Number " << a << " is composite" << std::endl;
////    begin = clock();
//    if (aks.AKSAlgorithm_Bernstein())
//    	std::cout << "Number " << a << " is prime" << std::endl;
//    else
//    	std::cout << "Number " << a << " is composite" << std::endl;
////    end = clock();
////    std::cout << "AKS_Bernstein clock = " << double(end - begin)/CLOCKS_PER_SEC << std::endl;
//
//    return 0;
//}
