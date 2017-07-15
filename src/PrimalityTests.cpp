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
	std::string str("2425967623052370772757633156976982469681");
	NTL::ZZ number(NTL::INIT_VAL, str.c_str());
	AKS aks(number);
	struct timeval start, end;
	gettimeofday(&start, NULL);
	bool aksv3 = aks.AKSAlgorithm_Bernstein();
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	gettimeofday(&start, NULL);
	bool aksBern = aks.AKSAlgorithm_Bernstein_OMP();
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	CPPUNIT_ASSERT(aksv3);
	CPPUNIT_ASSERT(aksBern);
//	CPPUNIT_ASSERT(aksv3 == aksBern);
}
