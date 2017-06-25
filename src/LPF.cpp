/*
 * LPF.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: tasos
 */

#include "LPF.h"

LPF::LPF(long number)
{
	this->n = number;
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

long LPF::largest_prime_factor()
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
