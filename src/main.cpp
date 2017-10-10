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
#include "CombinationTests.h"
#include "AKSTests.h"
#include <fstream>

using namespace std;
using namespace CppUnit;

CPPUNIT_TEST_SUITE_REGISTRATION(PerfectPowerTests);
CPPUNIT_TEST_SUITE_REGISTRATION(UtilitiesTests);
CPPUNIT_TEST_SUITE_REGISTRATION(LPFTests);
CPPUNIT_TEST_SUITE_REGISTRATION(AKSTests);
CPPUNIT_TEST_SUITE_REGISTRATION(AKSOmpTests);
CPPUNIT_TEST_SUITE_REGISTRATION(AKSBernTests);
CPPUNIT_TEST_SUITE_REGISTRATION(AKSBernOmpTests);

/*
 * A function that checks if a string is a number
 */
bool isNumber(std::string str)
{
	for (int i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

/**
 * Main function: The driver that helps user select a specific implementation
 */
int main() {

	struct timeval start, end;
	std::string str;
	std::string option;
	int choice;
	bool result;

	do {
		std::cout << "Do you want to run tests? [Y / N]: ";
		std::cin >> option;
	} while (option[0] != 'Y' && option[0] != 'y' && option[0] != 'N' && option[0] != 'n');

	if (option[0] == 'Y' || option[0] == 'y')
	{
		CppUnit::TextUi::TestRunner runner;
		CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
		runner.addTest(registry.makeTest());
		runner.run();
		return 0;
	}

	do {
		std::cout << "Please give a valid number to check its primality" << std::endl;
		std::cin >> str;
	} while(!isNumber(str));

	AKS aks(str);

	do {
		std::cout << "Please pick a method for primality test" << std::endl;
		std::cout << "[1] AKS version 6" << std::endl;
		std::cout << "[2] AKS Bernstein" << std::endl;
		std::cout << "[3] AKS version 6 with OpenMP support" << std::endl;
		std::cout << "[4] AKS Bernstein with OpenMP support" << std::endl;
		std::cout << "[5] AKS Bernstein with CUDA support" << std::endl;
		std::cout << "Type a number and press enter: ";
		std::cin >> choice;
	} while (choice > 5 && choice < 1);

	if (choice == 1)
	{
		gettimeofday(&start, NULL);
		result = aks.AKSAlgorithm();
		gettimeofday(&end, NULL);
		std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	} else if (choice == 2)
	{
		gettimeofday(&start, NULL);
		result = aks.AKSAlgorithm_Bernstein();
		gettimeofday(&end, NULL);
		std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	} else if (choice == 3)
	{
		gettimeofday(&start, NULL);
		result = aks.AKSAlgorithm_OMP();
		gettimeofday(&end, NULL);
		std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	} else if (choice == 4)
	{
		gettimeofday(&start, NULL);
		result = aks.AKSAlgorithm_Bernstein_OMP();
		gettimeofday(&end, NULL);
		std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	} else if (choice == 5)
	{
		gettimeofday(&start, NULL);
		bool aksBern = aks.AKSAlgorithm_Bernstein_CUDA();
		gettimeofday(&end, NULL);
		std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	}

	if (result)
		std::cout << "The number is prime number" << std::endl;
	else
		std::cout << "The number is composite" << std::endl;
}
