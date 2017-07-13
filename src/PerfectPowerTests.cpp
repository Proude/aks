/*
 * PerfectPowerTests.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: tasos
 */

#include "PerfectPowerTests.h"

PerfectPowerTests::PerfectPowerTests() {
	// TODO Auto-generated constructor stub
	pp = PerfectPower();
}

PerfectPowerTests::~PerfectPowerTests() {
	// TODO Auto-generated destructor stub
}

// supports 65 digit numbers
void PerfectPowerTests::setUp()
{
	NTL::ZZ x(100000000000000000);
	NTL::ZZ y = x;
	y++;
	bignumPerfectPowers.SetLength(47);
	bignumNotPerfectPowers.SetLength(47);
	for (auto i = 0; i < 47; i++)
	{
		bignumPerfectPowers[i] = x;
		bignumNotPerfectPowers[i] = y;
		x *= 10;
		y = x;
		y++;
	}
}

void PerfectPowerTests::ReturnTrueIfAllArePerfectPowers()
{
	for (auto i = perfectPowers.begin(); i != perfectPowers.end(); i++)
	{
		CPPUNIT_ASSERT(pp.AlgorithmX(NTL::ZZ(*i)));
	}
}

void PerfectPowerTests::ReturnTrueIfAllAreNotPerfectPowers()
{
	for (auto i = notPerfectPowers.begin(); i != notPerfectPowers.end(); i++)
	{
		CPPUNIT_ASSERT(!pp.AlgorithmX(NTL::ZZ(*i)));
	}
}

void PerfectPowerTests::ReturnTrueIfAllBigNumsArePerfectPowers()
{
	for (auto i : bignumPerfectPowers)
	{
		CPPUNIT_ASSERT(pp.AlgorithmX(i));
	}
}

void PerfectPowerTests::ReturnFalseIfAllBigNumsAreNotPerfectPowers()
{
	for (auto i : bignumNotPerfectPowers)
	{
		CPPUNIT_ASSERT(!pp.AlgorithmX(i));
	}
}
