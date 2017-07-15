/*
 * AKS.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: tasos
 */

#include "AKS.h"
#include <fstream>

AKS::AKS(NTL::ZZ number)
{
	this->number = number;
	pp = PerfectPower();
	tools = Utilities();
	lpf = LPF();
}

bool AKS::AKSAlgorithm()
{
	if (pp.AlgorithmX(number))
		return false;

	int r = findRMultiplicativeOrder();
	std::cout << r << std::endl;

	for (NTL::ZZ i(2); i < number; i++)
		if (NTL::GCD(i, number) != 1)
			return false;

	if (r >= number)
		return true;

	int temp = floor(phi(r) * tools.log2(number));
	NTL::ZZ_p::init(number);
	NTL::ZZ_pX f(r, 1);
	f = f - 1;
	const NTL::ZZ_pXModulus pf(f);
	NTL::ZZ_pX rhs(number % r, 1);
	NTL::ZZ_pX lhs(1,1);
	for (int a = 1; a <= temp; a++)
	{
		if (!congruence(a, rhs, lhs, pf))
			return false;
	}
	return true;
}

bool AKS::AKSAlgorithm_Bernstein()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	if (pp.AlgorithmX(number))
	{
		gettimeofday(&end, NULL);
		std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
		return false;
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	//long r = findRMultiplicativeOrder();
	gettimeofday(&start, NULL);
	int r = primitiveModulo();
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find r) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
//	std::ofstream file;
//	file.open("test.txt",std::ios::app);
//	file << "The primitive root modulo of " << number << " is " << r << std::endl;
//	file.close();
//	std::cout << "r_temp = " << r_temp << std::endl;
//	r = r_temp;
	int phiR = phi(NTL::ZZ(r));
	const double d = 0.5 * phiR;
	const double i = 0.475 * phiR;
	const double j = 0.475 * phiR;
	//long s = findS(r, d, i, j);
	gettimeofday(&start, NULL);
	long s = findSB(r, d, i, j);
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find s) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	gettimeofday(&start, NULL);
	for (NTL::ZZ i(2); i <= s + 1; i++)
	{
		if ((i % number != 0) && (NTL::PowerMod(i % number, number - 1, number) != 1))
			return false;
//		if ((i != number) && NTL::GCD(number, i) != 1)
//			return false;
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

	NTL::ZZ_p::init(number);
	NTL::ZZ_pX f(r, 1);
	f = f - 1;
	const NTL::ZZ_pXModulus pf(f);
	NTL::ZZ_pX rhs(number % r, 1);
	NTL::ZZ_pX lhs(1,1);
	gettimeofday(&start, NULL);
	for (int a = 1; a <= s + 1; a++)
	{
		if (!congruence(a, rhs, lhs, pf))
			return false;
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (congruence) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	return true;
}

bool AKS::AKSAlgorithm_Bernstein_OMP()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	if (pp.AlgorithmX(number))
	{
		gettimeofday(&end, NULL);
		std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
		return false;
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	//long r = findRMultiplicativeOrder();
	gettimeofday(&start, NULL);
	int r = primitiveModulo();
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find r) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
//	std::ofstream file;
//	file.open("test.txt",std::ios::app);
//	file << "The primitive root modulo of " << number << " is " << r << std::endl;
//	file.close();
//	std::cout << "r_temp = " << r_temp << std::endl;
//	r = r_temp;
	int phiR = phi(NTL::ZZ(r));
	const double d = 0.5 * phiR;
	const double i = 0.475 * phiR;
	const double j = 0.475 * phiR;
	//long s = findS(r, d, i, j);
	gettimeofday(&start, NULL);
	long s = findSB(r, d, i, j);
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find s) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	bool result = true;
	gettimeofday(&start, NULL);
	#pragma omp parallel for reduction(&:result)
	for (int i = 2; i <= s + 1; i++)
	{
		NTL::ZZ iZZ(i);
		if ((iZZ % number != 0) && (NTL::PowerMod(iZZ % number, number - 1, number) != 1))
			result &= false;
//		if ((i != number) && NTL::GCD(number, i) != 1)
//			return false;
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
//	for (int i = 1; i <= s + 1; i++)
//		results[i - 1] = true;
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

int AKS::primitiveModulo()
{
//	std::ofstream file;
	const double r0 = 0.01 * tools.log2(number) * tools.log2(number);
	NTL::PrimeSeq q;
	long r = q.next();
	if (number == 2)
		return 1;
	r = q.next();

	while(r < number)
	{
//		file.open("test.txt", std::ios::app);
//		file << "phi(" << r << ") = " << phi(r) << std::endl;
//		file.close();
		if (order(number, NTL::ZZ(r)) == phi(r))
			if (r > r0)
				return r;
		r = q.next();
	}
	return 0;
}

bool AKS::isPrimitiveModulo(long r)
{
	int s = phi(r);
	std::list<long> k = lpf.primeFactors(s);
	for (auto i = k.begin(); i != k.end(); i++)
	{
		if (NTL::PowerMod(number, NTL::ZZ(s / (*i)), NTL::ZZ(r)) == 1)
			return false;
	}
	return true;
}

int AKS::phi(NTL::ZZ r)
{
	int temp = 1;
	for (int i = 2; i < r; i++)
		if (NTL::GCD(r, NTL::conv<NTL::ZZ>(i)) == 1)
			temp++;
	return temp;
}

int AKS::phi(int r)
{
	int temp = 1;
	for (int i = 2; i < r; i++)
		if (NTL::GCD(r, i) == 1)
			temp++;
	return temp;
}

long AKS::findS(const long r, double d, double i, double j)
{
	NTL::RR rhs(NTL::conv<NTL::RR>(NTL::power(number, NTL::conv<long>(NTL::ceil(NTL::sqrt(NTL::RR(phi(NTL::ZZ(r))) / 3))))));
	NTL::RR comb2(lpf.combination(d, i));
	NTL::RR comb4(lpf.combination(phi(NTL::conv<NTL::ZZ>(r)) - 1 - d, j));
	for (int s = 2; true; s++)
	{
		if (lpf.combination(2 * s, i) * comb2 * lpf.combination(2 * s - 1, j) * comb4 >= rhs)
			return s;
	}
}

long AKS::findSB(const long r, double d, double i, double j)
{
	int s;
	NTL::RR rhs(NTL::conv<NTL::RR>(NTL::power(number, NTL::conv<long>(NTL::ceil(NTL::sqrt(NTL::RR(phi(NTL::ZZ(r))) / 3))))));
	NTL::RR comb2(lpf.combination(d, i));
	NTL::RR comb4(lpf.combination(phi(NTL::conv<NTL::ZZ>(r)) - 1 - d, j));
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

bool AKS::congruence(int a, NTL::ZZ_pX rhs, NTL::ZZ_pX lhs, NTL::ZZ_pXModulus pf)
{
	lhs += a;
	lhs = NTL::PowerMod(lhs, number, pf);
	lhs -= a;
	if (lhs != rhs)
		return false;
	return true;
}

//int AKS::findRBernstein()
//{
//	NTL::PrimeSeq p;
//	PerfectPower pp;
//	int r = 2;
//	long j = p.next();
//	while (r < number)
//	{
//		if (NTL::GCD(number, conv<ZZ>(r)) != 1)
//			return false;
//		if (r == j)
//		{
//			LPF lpf(r - 1);
//			long q=lpf.largest_prime_factor();
//			if(NTL::power(number, (r - 1) / q) % r == 1){r++;continue;}
//			double cm=2*floor(sqrt(r))*pp.log2(number),c=0;
//			for(int s=1;s<q && c<cm;s++) c+=pp.log2(q+s-1)-pp.log2(s);
//			if(c>=cm)break;
////			LPF lpf(r - 1);
////			long q = lpf.largest_prime_factor();
////			std::cout << "r = " << r << " and q = " << q << std::endl;
////			std::cout << "The combination = " << lpf.combination(2 * q - 1, q) << std::endl;
////			std::cout << " sqrt(r) = " << std::sqrt(r) << std::endl;
////			std::cout << " sqrt(r) * log2(n) = " << std::sqrt(r) * pp.log2(number) << std::endl;
////			std::cout << " Floor = " << NTL::floor(NTL::conv<NTL::RR>(std::sqrt(r) * pp.log2(number))) << std::endl;
////			std::cout << " 2^(2*sqrt(r)log(n) = " << NTL::power(NTL::ZZ(2), NTL::conv<long>(2 * NTL::floor(NTL::conv<NTL::RR>(std::sqrt(r) * pp.log2(number))))) << std::endl;
////			std::cout << " n^((r - 1) / q) mod r == 0, 1 is " << NTL::power(number, (r-1) / q) % r << std::endl;
////			if (lpf.combination(2 * q - 1, q) >= NTL::power(NTL::ZZ(2), NTL::conv<long>(2 * NTL::floor(NTL::conv<NTL::RR>(std::sqrt(r)) * pp.log2(number)))) && NTL::power(number, (r-1) / q) % r > 1)
////				break;
//			j = p.next();
//		}
//
//		r++;
//	}
//	return r;
//}

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
