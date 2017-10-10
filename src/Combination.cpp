/*
 * LPF.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: Anastasios Gemtos
 */

#include "Combination.h"

/*
 * Constructor
 */
Comb::Comb()
{
	tools = Utilities();
}

/*
 * Combination(a, b) using multiplication
 * Note: Currently not used
 */
NTL::ZZ Comb::combination(long a, long b)
{
	NTL::ZZ temp1(1), temp2(1);
	for (long i = a; i >= a - b + 1; i--)
		temp1 *= i;
	for (long i = b; i >= 1; i--)
		temp2 *= i;
	return temp1/temp2;
}

/*
 * Combination(a, b) using gamma function
 */
NTL::RR Comb::combination(double a, double b)
{
	if ((a - b + 1) == -1 || ((a - b + 1) == 0))
		return NTL::RR(0);
	NTL::RR x(gammaFunction(a + 1));
	NTL::RR y(gammaFunction(b + 1) * gammaFunction(a - b + 1));
	return x / y;
}

/*
 * Gamma function with Lanczos approximation
 */
NTL::RR Comb::gammaFunction(double x)
{
	NTL::RR sum(lanczos_coef[0]);
	int g = 7;
	if (x < 0.5)
		return M_PI / (NTL::sin(NTL::RR(M_PI * x)) * gammaFunction(1 - x));
	x -= 1;
	long double t = x + g + 0.5;
	for (int i = 1; i < 9; i++)
	{
		sum += lanczos_coef[i] / (x + i);
	}
	sum = NTL::sqrt(NTL::RR(2 * M_PI)) * tools.power(t, x + 0.5) * NTL::exp(NTL::RR(-t)) * sum;
	return sum;
}
