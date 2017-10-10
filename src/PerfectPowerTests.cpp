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

void PerfectPowerTests::setUp()
{
	// supports 65 digit numbers
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

// Check if the perfect powers from array are true
void PerfectPowerTests::ReturnTrueIfAllArePerfectPowers()
{
	for (auto i = perfectPowers.begin(); i != perfectPowers.end(); i++)
	{
		CPPUNIT_ASSERT(pp.AlgorithmX(NTL::ZZ(*i)));
	}
}

//Check if the non perfect power number from the array are false
void PerfectPowerTests::ReturnTrueIfAllAreNotPerfectPowers()
{
	for (auto i = notPerfectPowers.begin(); i != notPerfectPowers.end(); i++)
	{
		CPPUNIT_ASSERT(!pp.AlgorithmX(NTL::ZZ(*i)));
	}
}

// Check if the perfect powers from array are true
void PerfectPowerTests::ReturnTrueIfAllBigNumsArePerfectPowers()
{
	for (auto i : bignumPerfectPowers)
	{
		CPPUNIT_ASSERT(pp.AlgorithmX(i));
	}
}

//Check if the non perfect power number from the array are false
void PerfectPowerTests::ReturnFalseIfAllBigNumsAreNotPerfectPowers()
{
	for (auto i : bignumNotPerfectPowers)
	{
		CPPUNIT_ASSERT(!pp.AlgorithmX(i));
	}
}
