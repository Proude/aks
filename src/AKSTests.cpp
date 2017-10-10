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

void AKSTests::testRandomPrimeNumbers()
{

}

// 2-digit prime test
void AKSTests::returnTrueIf13IsPrime()
{
	std::string str("13");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 2-digit composite test
void AKSTests::returnFalseIf34IsComposite()
{
	std::string str("34");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 3-digit prime test
void AKSTests::returnTrueIf991IsPrime()
{
	std::string str("991");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 3-digit composite test
void AKSTests::returnFalseIf169IsComposite()
{
	std::string str("169");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 4-digit prime test
void AKSTests::returnTrueIf3793IsPrime()
{
	std::string str("3793");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 4-digit prime test
void AKSTests::returnTrueIf7621IsPrime()
{
	std::string str("7621");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 5-digit prime test
void AKSTests::returnTrueIf11621IsPrime()
{
	std::string str("11621");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 5-digit composite test
void AKSTests::returnFalseIf10036IsComposite()
{
	std::string str("10036");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// very slow
// 10-digit prime test
void AKSTests::returnTrueIf5915587277IsPrime()
{
	std::string str("5915587277");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 10-digit composite test
void AKSTests::returnFalseIf2860486317IsComposite()
{
	std::string str("2860486317");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// very slow
// 20-digit prime test
void AKSTests::returnTrueIf29497513910652490397IsPrime()
{
	std::string str("29497513910652490397");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 20-digit composite test
void AKSTests::returnFalseIf12764787846258441471IsComposite()
{
	std::string str("12764787846258441471");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 30-digit composite test
void AKSTests::returnFalseIf280829369862134719390036617061IsComposite()
{
	std::string str("280829369862134719390036617061");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 40-digit composite test
void AKSTests::returnFalseIf2425967623052370772757633156976982469682IsComposite()
{
	std::string str("2425967623052370772757633156976982469682");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 50-digit composite test
void AKSTests::returnFalseIf54987541231012456465487987654132654568741532457817IsComposite()
{
	std::string str("54987541231012456465487987654132654568741532457817");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}
