/*
 * AKS.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: tasos
 */

#include "AKS.h"

using namespace NTL;

AKS::AKS(NTL::ZZ number)
{
	this->number = number;
}

bool AKS::AKSAlgorithm()
{
	PerfectPower pp;
	if (pp.AlgorithmX(number))
	{
		std::cout << "The number is perfect power. Hence, composite!" << std::endl;
		return false;
	}
	else
	{
		std::cout << "The number is not perfect power. Checking for primality!" << std::endl;
	}

	NTL::PrimeSeq p;
	int r = 2;
	long j = p.next();
	while (r < number)
	{
		if (NTL::GCD(number, conv<ZZ>(r)) != 1)
			return false;
		if (r == j)
		{
			LPF lpf(r - 1);
			long q = lpf.largest_prime_factor();
			std::cout << "r = " << r << " and q = " << q << std::endl;
			std::cout << "The combination = " << lpf.combination(2 * q - 1, q) << std::endl;
			std::cout << " sqrt(r) = " << std::sqrt(r) << std::endl;
			std::cout << " sqrt(r) * log2(n) = " << std::sqrt(r) * pp.log2(number) << std::endl;
			std::cout << " Floor = " << NTL::floor(NTL::conv<NTL::RR>(std::sqrt(r) * pp.log2(number))) << std::endl;
			std::cout << " 2^(2*sqrt(r)log(n) = " << NTL::power(NTL::ZZ(2), NTL::conv<long>(2 * NTL::floor(NTL::conv<NTL::RR>(std::sqrt(r) * pp.log2(number))))) << std::endl;
			std::cout << " n^((r - 1) / q) mod r == 0, 1 is " << NTL::power(number, (r-1) / q) % r << std::endl;
			if (lpf.combination(2 * q - 1, q) >= NTL::power(NTL::ZZ(2), NTL::conv<long>(2 * NTL::floor(NTL::conv<NTL::RR>(std::sqrt(r)) * pp.log2(number)))) && NTL::power(number, (r-1) / q) % r > 1)
				break;
			j = p.next();
		}

		r++;
	}

	std::cout << "r = " << r <<std::endl;

	int temp = NTL::conv<int>(NTL::floor(NTL::RR(r-1) * pp.log2(number)));
	for (int a = 1; a <= temp; a++)
	{
		if (!congruence(a, r))
			return false;
	}
	return true;
}

bool AKS::congruence(int a, long r)
{
	NTL::ZZ_p::init(number);
	NTL::ZZ_pX f(r, 1);
	f = f - 1;
	const ZZ_pXModulus pf(f);
	ZZ_pX rhs(number % r, 1);

	ZZ_pX lhs(1,1);
	lhs += a;
	NTL::PowerMod(lhs, lhs, number, pf);
	lhs -= a;
	if (lhs != rhs)
		return false;
	return true;
}
