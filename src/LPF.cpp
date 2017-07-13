/*
 * LPF.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: tasos
 */

#include "LPF.h"

LPF::LPF()
{
	tools = Utilities();
}

NTL::ZZ LPF::combination(long a, long b)
{
	NTL::ZZ temp1(1), temp2(1);
	for (long i = a; i >= a - b + 1; i--)
		temp1 *= i;
	for (long i = b; i >= 1; i--)
		temp2 *= i;
	return temp1/temp2;
}

NTL::RR LPF::combination(double a, double b)
{
	if ((a - b + 1) == -1 || ((a - b + 1) == 0))
		return NTL::RR(0);
	NTL::RR x(gammaFunction(a + 1));
	NTL::RR y(gammaFunction(b + 1) * gammaFunction(a - b + 1));
	return x / y;
}

NTL::RR LPF::gammaFunction(double x)
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
//	std::cout << "n = " << n << std::endl;
//	NTL::RR sum(0);
//	int i;
//	for (i = 8; i >= 1; i--)
//		sum += lanczos_coef[i] / (n + (double)i);
//	sum += lanczos_coef[0];
//	std::cout << "sum = " << sum << std::endl;
//	sum = sum * NTL::sqrt(NTL::RR(2 * M_PI)) * NTL::power(NTL::RR(n + 9 - 0.5), n + 0.5) * NTL::exp(NTL::RR(-(n + 9 - 0.5)));
//	std::cout << "final sum = " << sum << std::endl;
//	return sum;
}

long LPF::largest_prime_factor(int n)
{
	std::list<int> result;
	int d = 2;

	if (n == 1)
		return 1;

	while (n > 1)
	{
		while (n % d == 0)
		{
			result.insert(result.end(), d);
			n /= d;
		}
		d++;
		if (d * d > n)
		{
			if (n > 1)
				result.insert(result.end(), n);
			break;
		}
	}
	long max = 0;
	for (auto i = result.begin(); i != result.end(); i++)
	{
		if (*i > 0)
			max = *i;
	}
	return max;
}

std::list<long> LPF::primeFactors(int s)
{
	std::list<long> result;
	int d = 2;

	if (s == 1)
		return {};

	while (s > 1)
	{
		while (s % d == 0)
		{
			result.insert(result.end(), d);
			s /= d;
		}
		d++;
		if (d * d > s)
		{
			if (s > 1)
				result.insert(result.end(), s);
			break;
		}
	}
	return result;
}
