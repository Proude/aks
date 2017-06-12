#include "AKS.h"

//bool AKS::isPerfectPower()
//{
//	NTL::ZZ a, x;
//
//	for (NTL::ZZ i(2); i < log2(number); i++)
//	{
//		NTL::PrimeSeq p;
//		long j = p.next();
//		while(j < log2(number))
//		{
//			std::cout << "i = " << i << " and j = " << j << std::endl;
//			if (NTL::power(i, j) == number)
//				return true;
//			j = p.next();
//		}
//	}
//	return false;
//}

AKS::AKS(NTL::ZZ number)
{
    this->number = number;
}

bool AKS::AlgorithmX()
{
    NTL::ZZ f, nroot_b;
    NTL::RR y;

    f = NTL::conv<NTL::ZZ>(NTL::floor(NTL::RR(log2(2 * number))));
    nroot_b = NTL::conv<NTL::ZZ>(3 + NTL::ceil(NTL::conv<NTL::RR>(f) / 2));

    if (nroot_b <= NTL::CeilToZZ(NTL::conv<NTL::RR>(log2(NTL::ZZ(8)))))
        y = AlgorithmB(nroot_b, NTL::conv<NTL::RR>(number), NTL::ZZ(1));
    else
        y = AlgorithmN(nroot_b, NTL::conv<NTL::RR>(number), NTL::ZZ(1));

    NTL::PrimeSeq p;
    long i = p.next();
    while(i < f)
    {
    	NTL::RR x = AlgorithmK(number, NTL::conv<NTL::ZZ>(i), y);
    	if (x > 0)
    		return true;
    	i = p.next();
    }
    return false;
}

NTL::RR AKS::AlgorithmB(NTL::ZZ b, NTL::RR y, NTL::ZZ k)
{
	long g = 0;
	long gn = -1;
	while(true)
	{
		if (NTL::conv<NTL::RR>(NTL::power(NTL::RR(2), g - 1)) < y && NTL::conv<NTL::RR>(NTL::power(NTL::RR(2), g)) >= y)
			break;
		if (NTL::conv<NTL::RR>(NTL::power(NTL::RR(2), gn - 1)) < y && NTL::conv<NTL::RR>(NTL::power(NTL::RR(2), gn)) >= y)
		{
			g = gn;
			break;
		}
		g++;
		gn--;
	}
	NTL::ZZ b_capital = NTL::conv<NTL::ZZ>(NTL::ceil(NTL::conv<NTL::RR>(log2(66 * (2 * k + 1)))));
	NTL::ZZ a = NTL::conv<NTL::ZZ>(NTL::floor(NTL::conv<NTL::RR>(NTL::ZZ(-g) / k)));

	NTL::RR z = NTL::conv<NTL::RR>(NTL::power(NTL::RR(2), NTL::conv<long>(a)) + NTL::power(NTL::RR(2), NTL::conv<long>(a - 1)));
	NTL::ZZ j(1);

	do {
		if (j == b)
			return z;
		NTL::RR r = NTL::power(z, NTL::conv<long>(k)) * NTL::conv<NTL::RR>(y);

		if (r <= 0.9697265625)
			z = z + NTL::power(NTL::RR(2), NTL::conv<long>(a-j-1));
		if (r > 1)
			z = z - NTL::power(NTL::RR(2), NTL::conv<long>(a-j-1));
		j++;
	} while (true);
}

//NTL::RR AKS::AlgorithmP(NTL::RR r, NTL::ZZ k, NTL::ZZ b)
//{
//	if (k == 1)
//		return NTL::TruncPrec(r, NTL::conv<long>(b));
//	if (k % 2 == 0)
//	{
//		return NTL::TruncPrec(AKS::AlgorithmP(r, k/2, b) ^ 2, NTL::conv<long>(b));
//	}
//}

NTL::RR AKS::AlgorithmN(NTL::ZZ b, NTL::RR y, NTL::ZZ k)
{
	NTL::ZZ b_prime = NTL::CeilToZZ(NTL::RR(log2(2 * k))) + NTL::CeilToZZ(NTL::conv<NTL::RR>(b - (NTL::CeilToZZ(NTL::RR(log2(2 * k))))) / 2);
	NTL::ZZ b_capital = 2 * b_prime + 4 - NTL::CeilToZZ(NTL::RR(log2(k)));

	NTL::RR z;

	if (b_prime <= NTL::CeilToZZ(NTL::RR(log2(8 * k))))
		z = AKS::AlgorithmB(b_prime, y, k);
	else
		z = AKS::AlgorithmN(b_prime, y, k);

	NTL::RR r2 = z * NTL::conv<NTL::RR>(k + 1);
	NTL::RR r3 = NTL::power(z, NTL::conv<long>(k + 1)) * y;
	NTL::RR r4 = (r2 - r3) / NTL::conv<NTL::RR>(k);

	return r4;
}

NTL::RR AKS::AlgorithmK(NTL::ZZ number, NTL::ZZ k, NTL::RR y)
{
	NTL::ZZ f = NTL::conv<NTL::ZZ>(NTL::floor(NTL::RR(log2(2 * number))));
	NTL::ZZ b = 3 + NTL::conv<NTL::ZZ>(NTL::ceil(NTL::conv<NTL::RR>(f) / NTL::conv<NTL::RR>(k)));

	NTL::RR r;

	if (b <= NTL::CeilToZZ(NTL::conv<NTL::RR>(log2(8 * k))))
		r = AKS::AlgorithmB(b, y, k);
	else
		r = AKS::AlgorithmN(b, y, k);

	NTL::RR x(0);
	while(true)
	{
		if (NTL::abs(r - x) <= NTL::RR(0.625))
			break;
		x++;
	}

	if (x == 0.0 || NTL::abs(r - x) >= NTL::RR(0.25))
		return NTL::RR(0);

	if (NTL::conv<NTL::RR>(number) == NTL::power(x, NTL::conv<long>(k)))
		return x;
	return NTL::RR(0);
}
