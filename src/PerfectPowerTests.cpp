/*
 * PerfectPowerTests.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: tasos
 */

#include "PerfectPowerTests.h"

PerfectPowerTests::PerfectPowerTests() {
	// TODO Auto-generated constructor stub

}

PerfectPowerTests::~PerfectPowerTests() {
	// TODO Auto-generated destructor stub
}

void PerfectPowerTests::ReturnTrueIfAllArePerfectPowers()
{
	PerfectPower pp;
	for (auto i = perfectPowers.begin(); i != perfectPowers.end(); i++)
	{
		CPPUNIT_ASSERT(pp.AlgorithmX(NTL::ZZ(*i)));
	}
}

void PerfectPowerTests::ReturnTrueIfAllAreNotPerfectPowers()
{
	PerfectPower pp;
	for (auto i = notPerfectPowers.begin(); i != notPerfectPowers.end(); i++)
	{
		CPPUNIT_ASSERT(!pp.AlgorithmX(NTL::ZZ(*i)));
	}
}
