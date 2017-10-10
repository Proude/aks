/*
 * AKSTests.h
 *
 *  Created on: Jul 6, 2017
 *      Author: Anastasios Gemtos
 */
#include <extensions/HelperMacros.h>
#include "AKS.h"
#include <gmp.h>

#ifndef AKSTESTS_H_
#define AKSTESTS_H_

class AKSTests : public CppUnit::TestCase{
public:
	AKSTests();
	virtual ~AKSTests();
	void testRandomPrimeNumbers();
	void returnTrueIf13IsPrime();
	void returnFalseIf34IsComposite();
	void returnTrueIf991IsPrime();
	void returnFalseIf169IsComposite();
	void returnTrueIf3793IsPrime();
	void returnTrueIf7621IsPrime();
	void returnTrueIf11621IsPrime();
	void returnFalseIf10036IsComposite();
	void returnTrueIf5915587277IsPrime();
	void returnFalseIf2860486317IsComposite();
	void returnTrueIf29497513910652490397IsPrime();
	void returnFalseIf12764787846258441471IsComposite();
	void returnFalseIf280829369862134719390036617061IsComposite();
	void returnFalseIf2425967623052370772757633156976982469682IsComposite();
	void returnFalseIf54987541231012456465487987654132654568741532457817IsComposite();
private:
	struct timeval start, end;
	CPPUNIT_TEST_SUITE(AKSTests);
	CPPUNIT_TEST(testRandomPrimeNumbers);
	CPPUNIT_TEST(returnTrueIf13IsPrime);
	CPPUNIT_TEST(returnFalseIf34IsComposite);
	CPPUNIT_TEST(returnTrueIf991IsPrime);
	CPPUNIT_TEST(returnFalseIf169IsComposite);
	CPPUNIT_TEST(returnTrueIf3793IsPrime);
	CPPUNIT_TEST(returnTrueIf7621IsPrime);
	CPPUNIT_TEST(returnTrueIf11621IsPrime);
	CPPUNIT_TEST(returnFalseIf10036IsComposite);
	// very slow. Uncomment if test is needed
	//CPPUNIT_TEST(returnTrueIf5915587277IsPrime);
	CPPUNIT_TEST(returnFalseIf2860486317IsComposite);
	//very slow. Uncomment if test is needed
	//CPPUNIT_TEST(returnTrueIf29497513910652490397IsPrime);
	CPPUNIT_TEST(returnFalseIf12764787846258441471IsComposite);
	CPPUNIT_TEST(returnFalseIf280829369862134719390036617061IsComposite);
	CPPUNIT_TEST(returnFalseIf2425967623052370772757633156976982469682IsComposite);
	CPPUNIT_TEST(returnFalseIf54987541231012456465487987654132654568741532457817IsComposite);
	CPPUNIT_TEST_SUITE_END();
};

class AKSOmpTests : public CppUnit::TestCase {
public:
	AKSOmpTests();
	virtual ~AKSOmpTests();
	void returnTrueIf13IsPrime();
	void returnFalseIf34IsComposite();
	void returnTrueIf991IsPrime();
	void returnFalseIf169IsComposite();
	void returnTrueIf3793IsPrime();
	void returnTrueIf7621IsPrime();
	void returnTrueIf11621IsPrime();
	void returnFalseIf10036IsComposite();
	void returnTrueIf5915587277IsPrime();
	void returnFalseIf2860486317IsComposite();
	void returnTrueIf29497513910652490397IsPrime();
	void returnFalseIf12764787846258441471IsComposite();
	void returnFalseIf280829369862134719390036617061IsComposite();
	void returnFalseIf2425967623052370772757633156976982469682IsComposite();
	void returnFalseIf54987541231012456465487987654132654568741532457817IsComposite();
private:
	struct timeval start, end;
	CPPUNIT_TEST_SUITE(AKSOmpTests);
	CPPUNIT_TEST(returnTrueIf13IsPrime);
	CPPUNIT_TEST(returnFalseIf34IsComposite);
	CPPUNIT_TEST(returnTrueIf991IsPrime);
	CPPUNIT_TEST(returnFalseIf169IsComposite);
	CPPUNIT_TEST(returnTrueIf3793IsPrime);
	CPPUNIT_TEST(returnTrueIf7621IsPrime);
	CPPUNIT_TEST(returnTrueIf11621IsPrime);
	CPPUNIT_TEST(returnFalseIf10036IsComposite);
	//very slow. Uncomment if test is needed
	//CPPUNIT_TEST(returnTrueIf5915587277IsPrime);
	CPPUNIT_TEST(returnFalseIf2860486317IsComposite);
	//very slow. Uncomment if test is needed
	//CPPUNIT_TEST(returnTrueIf29497513910652490397IsPrime);
	CPPUNIT_TEST(returnFalseIf12764787846258441471IsComposite);
	CPPUNIT_TEST(returnFalseIf280829369862134719390036617061IsComposite);
	CPPUNIT_TEST(returnFalseIf2425967623052370772757633156976982469682IsComposite);
	CPPUNIT_TEST(returnFalseIf54987541231012456465487987654132654568741532457817IsComposite);
	CPPUNIT_TEST_SUITE_END();
};

class AKSBernTests : public CppUnit::TestCase {
public:
	AKSBernTests();
	virtual ~AKSBernTests();
	void returnTrueIf13IsPrime();
	void returnFalseIf34IsComposite();
	void returnTrueIf991IsPrime();
	void returnFalseIf169IsComposite();
	void returnTrueIf3793IsPrime();
	void returnTrueIf7621IsPrime();
	void returnTrueIf11621IsPrime();
	void returnFalseIf10036IsComposite();
	void returnTrueIf5915587277IsPrime();
	void returnFalseIf2860486317IsComposite();
	void returnTrueIf29497513910652490397IsPrime();
	void returnFalseIf12764787846258441471IsComposite();
	void returnTrueIf590872612825179551336102196593IsPrime();
	void returnFalseIf280829369862134719390036617061IsComposite();
	void returnTrueIf2425967623052370772757633156976982469681IsPrime();
	void returnFalseIf2425967623052370772757633156976982469682IsComposite();
	void returnTrueIf29927402397991286489627837734179186385188296382227IsPrime();
	void returnFalseIf54987541231012456465487987654132654568741532457817IsComposite();
private:
	struct timeval start, end;
	CPPUNIT_TEST_SUITE(AKSBernTests);
	CPPUNIT_TEST(returnTrueIf13IsPrime);
	CPPUNIT_TEST(returnFalseIf34IsComposite);
	CPPUNIT_TEST(returnTrueIf991IsPrime);
	CPPUNIT_TEST(returnFalseIf169IsComposite);
	CPPUNIT_TEST(returnTrueIf3793IsPrime);
	CPPUNIT_TEST(returnTrueIf7621IsPrime);
	CPPUNIT_TEST(returnTrueIf11621IsPrime);
	CPPUNIT_TEST(returnFalseIf10036IsComposite);
	CPPUNIT_TEST(returnTrueIf5915587277IsPrime);
	CPPUNIT_TEST(returnFalseIf2860486317IsComposite);
	CPPUNIT_TEST(returnTrueIf29497513910652490397IsPrime);
	CPPUNIT_TEST(returnFalseIf12764787846258441471IsComposite);
	CPPUNIT_TEST(returnTrueIf590872612825179551336102196593IsPrime);
	CPPUNIT_TEST(returnFalseIf280829369862134719390036617061IsComposite);
	CPPUNIT_TEST(returnTrueIf2425967623052370772757633156976982469681IsPrime);
	CPPUNIT_TEST(returnFalseIf2425967623052370772757633156976982469682IsComposite);
	CPPUNIT_TEST(returnTrueIf29927402397991286489627837734179186385188296382227IsPrime);
	CPPUNIT_TEST(returnFalseIf54987541231012456465487987654132654568741532457817IsComposite);
	CPPUNIT_TEST_SUITE_END();
};

class AKSBernOmpTests : public CppUnit::TestCase {
public:
	AKSBernOmpTests();
	virtual ~AKSBernOmpTests();
	void returnTrueIf13IsPrime();
	void returnFalseIf34IsComposite();
	void returnTrueIf991IsPrime();
	void returnFalseIf169IsComposite();
	void returnTrueIf3793IsPrime();
	void returnTrueIf7621IsPrime();
	void returnTrueIf11621IsPrime();
	void returnFalseIf10036IsComposite();
	void returnTrueIf5915587277IsPrime();
	void returnFalseIf2860486317IsComposite();
	void returnTrueIf29497513910652490397IsPrime();
	void returnFalseIf12764787846258441471IsComposite();
	void returnTrueIf590872612825179551336102196593IsPrime();
	void returnFalseIf280829369862134719390036617061IsComposite();
	void returnTrueIf2425967623052370772757633156976982469681IsPrime();
	void returnFalseIf2425967623052370772757633156976982469682IsComposite();
	void returnTrueIf29927402397991286489627837734179186385188296382227IsPrime();
	void returnFalseIf54987541231012456465487987654132654568741532457817IsComposite();
private:
	struct timeval start, end;
	CPPUNIT_TEST_SUITE(AKSBernOmpTests);
	CPPUNIT_TEST(returnTrueIf13IsPrime);
	CPPUNIT_TEST(returnFalseIf34IsComposite);
	CPPUNIT_TEST(returnTrueIf991IsPrime);
	CPPUNIT_TEST(returnFalseIf169IsComposite);
	CPPUNIT_TEST(returnTrueIf3793IsPrime);
	CPPUNIT_TEST(returnTrueIf7621IsPrime);
	CPPUNIT_TEST(returnTrueIf11621IsPrime);
	CPPUNIT_TEST(returnFalseIf10036IsComposite);
	CPPUNIT_TEST(returnTrueIf5915587277IsPrime);
	CPPUNIT_TEST(returnFalseIf2860486317IsComposite);
	CPPUNIT_TEST(returnTrueIf29497513910652490397IsPrime);
	CPPUNIT_TEST(returnFalseIf12764787846258441471IsComposite);
	CPPUNIT_TEST(returnTrueIf590872612825179551336102196593IsPrime);
	CPPUNIT_TEST(returnFalseIf280829369862134719390036617061IsComposite);
	CPPUNIT_TEST(returnTrueIf2425967623052370772757633156976982469681IsPrime);
	CPPUNIT_TEST(returnFalseIf2425967623052370772757633156976982469682IsComposite);
	CPPUNIT_TEST(returnTrueIf29927402397991286489627837734179186385188296382227IsPrime);
	CPPUNIT_TEST(returnFalseIf54987541231012456465487987654132654568741532457817IsComposite);
	CPPUNIT_TEST_SUITE_END();
};

#endif /* AKSTESTS_H_ */
