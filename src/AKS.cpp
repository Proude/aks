/*
 * AKS.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: Anastasios Gemtos
 */

#include "AKS.h"
#include <fstream>

/*
 * Constructor when NTL::ZZ integer is given
 * Note: Currently not used
 */
AKS::AKS(NTL::ZZ number)
{
	this->number = number;
	pp = PerfectPower();
	tools = Utilities();
	lpf = Comb();
}

/*
 * Constructor when a number is given as an std::string
 */
AKS::AKS(std::string number)
{
	// initialize an array of integers in case CUDA version is used
	for (int i = 0, j = 0; i < N; i++)
	{
		if (N - number.length() <= i)
		{
			num_arr[i] = number[j] - '0';
			j++;
		}
		else
			num_arr[i] = 0;
	}
	this->number = NTL::ZZ(NTL::INIT_VAL, number.c_str());
	pp = PerfectPower();
	tools = Utilities();
	lpf = Comb();
}

/*
 * AKS version 6
 * Checks if the number is prime or not
 */
bool AKS::AKSAlgorithm()
{
	struct timeval start, end;
	// checking if number is perfect power
	gettimeofday(&start, NULL);
	if (pp.AlgorithmX(number))
	{
		gettimeofday(&end, NULL);
		std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
		return false;
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	// find r so that o_r(n) > log(n)^2
	gettimeofday(&start, NULL);
	int r = findRMultiplicativeOrder();
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find r) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	// if r > n, n is prime
	if (r >= number)
		return true;

	// some GCD checking
	gettimeofday(&start, NULL);
	for (int i = 2; i < r; i++)
		if (NTL::GCD(NTL::ZZ(i), number) != 1)
			return false;
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (gcd) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	int temp = floor(phi(r) * tools.log2(number));

	// (X + a)^n equivalent X^{n} + a mod (X^{r} - 1, n)
	gettimeofday(&start, NULL);
	NTL::ZZ_p::init(number);
	NTL::ZZ_pX f(r, 1);
	f = f - 1;
	const NTL::ZZ_pXModulus pf(f);
	NTL::ZZ_pX rhs(number % r, 1);
	NTL::ZZ_pX lhs(1,1);
	for (int a = 1; a <= temp; a++)
	{
		// if the congruence is false for an a, number n is composite
		if (!congruence(a, rhs, lhs, pf))
		{
			gettimeofday(&end, NULL);
			std::cout << "Elapsed time (congruence) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
			return false;
		}
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (congruence) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	// Test passed. Number n is prime
	return true;
}

/*
 * AKS version 6 with OpenMP support
 */
bool AKS::AKSAlgorithm_OMP()
{
	struct timeval start, end;
	// checking if number is perfect power
	gettimeofday(&start, NULL);
	if (pp.AlgorithmX(number))
	{
		gettimeofday(&end, NULL);
		std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
		return false;
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	// find r so that o_r(n) > log(n)^2
	gettimeofday(&start, NULL);
	int r = findRMultiplicativeOrder();
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find r) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	// if r > n, n is prime
	if (r >= number)
		return true;

	// some GCD checking
	gettimeofday(&start, NULL);
	for (int i = 2; i < r; i++)
		if (NTL::GCD(NTL::ZZ(i), number) != 1)
			return false;
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (gcd) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	bool results = true;
	int temp = floor(phi(r) * tools.log2(number));

	// (X + a)^n equivalent X^{n} + a mod (X^{r} - 1, n)
	gettimeofday(&start, NULL);
	NTL::ZZ_p::init(number);
	NTL::ZZ_pX f(r, 1);
	f = f - 1;
	const NTL::ZZ_pXModulus pf(f);
	NTL::ZZ_pX lhs(1, 1);
	NTL::ZZ_pX rhs(number % r, 1);
	#pragma omp parallel for reduction(&:results) private(lhs) num_threads(8) schedule(dynamic)
	for (int a = 1; a <= temp; a++)
	{
		NTL::ZZ_p::init(number);
		lhs = NTL::ZZ_pX(1, 1);
		lhs += a;
		lhs = NTL::PowerMod(lhs, number, pf);
		lhs -= a;
		if (lhs != rhs)
		{
			// if lhs != rhs, results becomes false, hence, n is not prime
			results &= false;
		}
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (congruence) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	return results;
}

/*
 * AKS by Bernstein (2003)
 */
bool AKS::AKSAlgorithm_Bernstein()
{
	struct timeval start, end;

	// Checking if number is perfect power
	gettimeofday(&start, NULL);
	if (pp.AlgorithmX(number))
	{
		gettimeofday(&end, NULL);
		std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
		return false;
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	// Find r so that n is a primitive modulo r
	gettimeofday(&start, NULL);
	int r = primitiveModulo();
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find r) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	int phiR = r - 1;
	const double d = 0.5 * phiR;
	const double i = 0.475 * phiR;
	const double j = 0.475 * phiR;

	// Find upper bound s
	gettimeofday(&start, NULL);
	long s = findSB(r, d, i, j);
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find s) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	// Checking the GCD based on Theorem 4.1
	gettimeofday(&start, NULL);
	for (NTL::ZZ i(2); i <= s + 1; i++)
	{
		if ((i % number != 0) && (NTL::PowerMod(i % number, number - 1, number) != 1))
			return false;
		for (NTL::ZZ j(2); j <= s + 1; j++)
		{
			if ((i * j > 1) && ((i * j) - 1 != number) && (i * j - 1 < number) && (NTL::GCD(number, (i * j) - 1) != 1))
				return false;
			if ((i - j > 0) && (i-j != number) && (i-j < number) && (NTL::GCD(number, i - j) != 1))
				return false;
		}
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (gcd) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	// Calculating the congruence
	gettimeofday(&start, NULL);
	NTL::ZZ_p::init(number);
	NTL::ZZ_pX f(r, 1);
	f = f - 1;
	const NTL::ZZ_pXModulus pf(f);
	NTL::ZZ_pX rhs(number % r, 1);
	NTL::ZZ_pX lhs(1,1);
	for (int a = 1; a <= s + 1; a++)
	{
		if (!congruence(a, rhs, lhs, pf))
			return false;
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (congruence) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	return true;
}

/*
 * AKS by Bernstein (2003) with OpenMP support
 */
bool AKS::AKSAlgorithm_Bernstein_OMP()
{
	struct timeval start, end;

	// Checking if number is perfect power
	gettimeofday(&start, NULL);
	if (pp.AlgorithmX(number))
	{
		gettimeofday(&end, NULL);
		std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
		return false;
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	// Find r so that n is a primitive modulo r
	gettimeofday(&start, NULL);
	int r = primitiveModulo();
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find r) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	int phiR = phi(NTL::ZZ(r));
	const double d = 0.5 * phiR;
	const double i = 0.475 * phiR;
	const double j = 0.475 * phiR;

	// Find upper bound s
	gettimeofday(&start, NULL);
	long s = findSB(r, d, i, j);
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find s) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	bool result = true;

	// Checking the GCD based on Theorem 4.1
	gettimeofday(&start, NULL);
	#pragma omp parallel for reduction(&:result)
	for (int i = 2; i <= s + 1; i++)
	{
		NTL::ZZ iZZ(i);
		if ((iZZ % number != 0) && (NTL::PowerMod(iZZ % number, number - 1, number) != 1))
			result &= false;
		for (int j = 2; j <= s + 1; j++)
		{
			NTL::ZZ jZZ(j);
			if ((iZZ * jZZ > 1) && ((iZZ * jZZ) - 1 != number) && (iZZ * jZZ - 1 < number) && (NTL::GCD(number, (iZZ * jZZ) - 1) != 1))
				result &= false;
			if ((iZZ - jZZ > 0) && (iZZ-jZZ != number) && (iZZ-jZZ < number) && (NTL::GCD(number, iZZ - jZZ) != 1))
				result &= false;
		}
	}

	gettimeofday(&end, NULL);
	if (result == false)
		return false;
	std::cout << "Elapsed time (gcd) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	bool results = true;

	// Calculating the congruence
	NTL::ZZ_p::init(number);
	NTL::ZZ_pX f(r, 1);
	f = f - 1;
	const NTL::ZZ_pXModulus pf(f);
	NTL::ZZ_pX lhs(1, 1);
	NTL::ZZ_pX rhs(number % r, 1);
	gettimeofday(&start, NULL);
	#pragma omp parallel for reduction(&:results) private(lhs) num_threads(8) schedule(dynamic)
	for (int a = 1; a <= s + 1; a++)
	{
		NTL::ZZ_p::init(number);
		lhs = NTL::ZZ_pX(1, 1);
		lhs += a;
		lhs = NTL::PowerMod(lhs, number, pf);
		lhs -= a;
		if (lhs != rhs)
		{
			results &= false;
		}
	}
//	for (int a = 1; a <= s + 1; a++)
//		if (results[a - 1] == false)
//			return false;
//	return true;
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (congruence) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
//	for (int a = 1; a <= s + 1; a++)
//		if (results[a -1] == false)
//			return false;

	if (results == false)
		return false;
	return true;
}

/*
 * Primitive root modulo n function
 * Tries to find a prime number r so that r is primitive root modulo n
 */
int AKS::primitiveModulo()
{
	// r must be > r0
	const double r0 = 0.01 * tools.log2(number) * tools.log2(number);
	NTL::PrimeSeq q;
	long r = q.next();
	if (number == 2)
		return 1;
	// r must be >= 3
	r = q.next();

	while(r < number)
	{
		if (order(number, NTL::ZZ(r)) == phi(r))
			if (r > r0)
				return r;
		r = q.next();
	}
	return 0;
}


//bool AKS::isPrimitiveModulo(long r)
//{
//	int s = phi(r);
//	std::list<long> k = lpf.primeFactors(s);
//	for (auto i = k.begin(); i != k.end(); i++)
//	{
//		if (NTL::PowerMod(number, NTL::ZZ(s / (*i)), NTL::ZZ(r)) == 1)
//			return false;
//	}
//	return true;
//}

/*
 * Euler's phi function
 * Calculate Euler's phi of an NTL::ZZ integer
 * Note: Currently not used
 */
int AKS::phi(NTL::ZZ r)
{
	int temp = 1;
	for (int i = 2; i < r; i++)
		if (NTL::GCD(r, NTL::conv<NTL::ZZ>(i)) == 1)
			temp++;
	return temp;
}

/*
 * Euler's phi function
 * Calculate Euler's phi of an integer
 */
int AKS::phi(int r)
{
	int temp = 1;
	for (int i = 2; i < r; i++)
		if (NTL::GCD(r, i) == 1)
			temp++;
	return temp;
}

/*
 * Find upper bound s
 * Find s using linear search
 * Note: Currently not used
 */
long AKS::findS(const long r, double d, double i, double j)
{
	//fixed values
	NTL::RR rhs(NTL::conv<NTL::RR>(NTL::power(number, NTL::conv<long>(NTL::ceil(NTL::sqrt(NTL::RR(phi(NTL::ZZ(r))) / 3))))));
	NTL::RR comb2(lpf.combination(d, i));
	NTL::RR comb4(lpf.combination(phi(NTL::conv<NTL::ZZ>(r)) - 1 - d, j));

	//Find s
	for (int s = 2; true; s++)
	{
		if (lpf.combination(2 * s, i) * comb2 * lpf.combination(2 * s - 1, j) * comb4 >= rhs)
			return s;
	}
}

/*
 * Find upper bound s
 * Find s using binary search between (2, INT_MAX/2)
 */
long AKS::findSB(const long r, double d, double i, double j)
{
	int s;
	//fixed values
	NTL::RR rhs(NTL::conv<NTL::RR>(NTL::power(number, NTL::conv<long>(NTL::ceil(NTL::sqrt(NTL::RR(phi(NTL::ZZ(r))) / 3))))));
	NTL::RR comb2(lpf.combination(d, i));
	NTL::RR comb4(lpf.combination(phi(NTL::conv<NTL::ZZ>(r)) - 1 - d, j));

	//Binary search from (2, INT_MAX/2)
	int start = 2;
	int end = INT_MAX / 2;
	while (start < end)
	{
		s = start + (end - start)/2;
		if (lpf.combination(2 * s, i) * comb2 * lpf.combination(2 * s - 1, j) * comb4 >= rhs)
			end = s;
		else
			start = s + 1;
	}
	return end;
}

/*
 * Congruence
 * Check if lhs == rhs, after build the polynomial
 */
bool AKS::congruence(int a, NTL::ZZ_pX rhs, NTL::ZZ_pX lhs, NTL::ZZ_pXModulus pf)
{
	lhs += a;
	lhs = NTL::PowerMod(lhs, number, pf);
	lhs -= a;
	if (lhs != rhs)
		return false;
	return true;
}

/*
 * Multiplicative Order
 * find smallest r so that o_r(n) > log(n)^2
 */
int AKS::findRMultiplicativeOrder()
{
	int r = 2;
	NTL::RR rhs = NTL::power(NTL::RR(tools.log2(number)), 2);
	while (true)
	{
		int temp = order(r);
		if (temp > rhs)
			return r;
		r++;
	}
	return r;
}

/*
 * Order r modulo n
 * calculates the o_r(n) for r small
 */
int AKS::order(int r)
{
	if (NTL::GCD(number, NTL::conv<NTL::ZZ>(r)) > 1)
		return 0;
	else
	{
		int k = 1;
		NTL::ZZ exp = number;
		while (exp != 1)
		{
			k++;
			exp = (exp * number) % r;
		}
		return k;
	}
}

/*
 * Order r modulo n
 * calculates the o_r(n) for r with arbitrary precision
 * Note: Currently not used
 */
int AKS::order(NTL::ZZ number, NTL::ZZ r)
{
	if (NTL::GCD(number, NTL::conv<NTL::ZZ>(r)) > 1)
		return 0;
	else
	{
		int k = 1;
		NTL::ZZ exp = number;
		while (exp % r != 1)
		{
			k++;
			exp = exp * number;
		}
		return k;
	}
}
