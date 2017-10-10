/*
 * AKSBernTests.cpp
 *
 *  Created on: 14 Sep 2017
 *      Author: tasos
 */

#include "AKSTests.h"

AKSBernTests::AKSBernTests() {
	// TODO Auto-generated constructor stub

}

AKSBernTests::~AKSBernTests() {
	// TODO Auto-generated destructor stub
}

// 2-digit prime test
void AKSBernTests::returnTrueIf13IsPrime()
{
	std::string str("13");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	std::cout << "Hello" << std::endl;
}

// 2-digit composite test
void AKSBernTests::returnFalseIf34IsComposite()
{
	std::string str("34");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 3-digit prime test
void AKSBernTests::returnTrueIf991IsPrime()
{
	std::string str("991");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 3-digit composite test
void AKSBernTests::returnFalseIf169IsComposite()
{
	std::string str("169");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 4-digit prime test
void AKSBernTests::returnTrueIf3793IsPrime()
{
	std::string str("3793");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 4-digit prime test
void AKSBernTests::returnTrueIf7621IsPrime()
{
	std::string str("7621");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 5-digit prime test
void AKSBernTests::returnTrueIf11621IsPrime()
{
	std::string str("11621");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 5-digit composite test
void AKSBernTests::returnFalseIf10036IsComposite()
{
	std::string str("10036");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 10-digit prime test
void AKSBernTests::returnTrueIf5915587277IsPrime()
{
	std::string str("5915587277");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 10-digit composite test
void AKSBernTests::returnFalseIf2860486317IsComposite()
{
	std::string str("2860486317");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 20-digit prime test
void AKSBernTests::returnTrueIf29497513910652490397IsPrime()
{
	std::string str("29497513910652490397");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 20-digit composite test
void AKSBernTests::returnFalseIf12764787846258441471IsComposite()
{
	std::string str("12764787846258441471");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 30-digit prime test
void AKSBernTests::returnTrueIf590872612825179551336102196593IsPrime()
{
	std::string str("590872612825179551336102196593");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 30-digit composite test
void AKSBernTests::returnFalseIf280829369862134719390036617061IsComposite()
{
	std::string str("280829369862134719390036617061");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 40-digit prime test
void AKSBernTests::returnTrueIf2425967623052370772757633156976982469681IsPrime()
{
	std::string str("2425967623052370772757633156976982469681");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 40-digit composite test
void AKSBernTests::returnFalseIf2425967623052370772757633156976982469682IsComposite()
{
	std::string str("2425967623052370772757633156976982469682");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 50-digit prime test
void AKSBernTests::returnTrueIf29927402397991286489627837734179186385188296382227IsPrime()
{
	std::string str("29927402397991286489627837734179186385188296382227");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}

// 50-digit composite test
void AKSBernTests::returnFalseIf54987541231012456465487987654132654568741532457817IsComposite()
{
	std::string str("54987541231012456465487987654132654568741532457817");
	std::cout << "Testing number: " << str << std::endl;
	AKS aks(str);

	gettimeofday(&start, NULL);
	CPPUNIT_ASSERT(!aks.AKSAlgorithm_Bernstein());
	gettimeofday(&end, NULL);
	std::cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
}
