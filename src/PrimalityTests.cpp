/*
 * PrimalityTests.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: tasos
 */

#include "PrimalityTests.h"

PrimalityTests::PrimalityTests() {
	// TODO Auto-generated constructor stub

}

PrimalityTests::~PrimalityTests() {
	// TODO Auto-generated destructor stub
}

void PrimalityTests::setUp()
{
	primes.SetLength(3);
	primes[0] = 3079;
	primes[1] = 10691;
	primes[2] = 102593;
}

void PrimalityTests::CheckPrimeNumbers()
{
	for (auto i : primes)
	{
		AKS aks(i);
		CPPUNIT_ASSERT(aks.AKSAlgorithm());
		CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	}
}

//void PrimalityTests::CompareAlgorithms()
//{
//	for (NTL::ZZ i(100); i < 100000; i ++)
//	{
//		AKS aks(i);
//		std::cout << i << std::endl;
//		std::cout << "In v3" << std::endl;
//		bool aksv3 = aks.AKSAlgorithm();
//		std::cout << "In Bernstein" << std::endl;
//		bool aksBern = aks.AKSAlgorithm_Bernstein();
//		CPPUNIT_ASSERT(aksv3 == aksBern);
//	}
//}

void PrimalityTests::returnTrueIfTheNumberIsPrime()
{
	std::string str("6075380529345458860144577398704761614649");
	NTL::ZZ number(NTL::INIT_VAL, str.c_str());
	AKS aks(number);
	clock_t begin = clock();
//	bool aksv3 = aks.AKSAlgorithm();
	clock_t end = clock();
	std::cout << (double)(end - begin) / CLOCKS_PER_SEC << std::endl;
	begin = clock();
	bool aksBern = aks.AKSAlgorithm_Bernstein();
	end = clock();
	std::cout << (double)(end - begin) / CLOCKS_PER_SEC << std::endl;
//	CPPUNIT_ASSERT(aksv3);
	CPPUNIT_ASSERT(aksBern);
//	CPPUNIT_ASSERT(aksv3 == aksBern);
}
