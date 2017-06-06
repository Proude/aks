#include "AKS.h"

AKS::AKS(NTL::ZZ number)
{
    this->number = number;
}

bool AKS::AlgorithmX(NTL::ZZ number)
{
    NTL::ZZ y, f, nroot_b;

    f = NTL::conv<NTL::ZZ>(NTL::floor(NTL::RR(NTL::log(2 * number))));

    std::cout << NTL::trunc_ZZ(NTL::ZZ(32), 5) << std::endl;

    nroot_b = NTL::conv<NTL::ZZ>(3 + NTL::ceil(NTL::conv<NTL::RR>(f / 2)));
    if (nroot_b > NTL::log(NTL::ZZ(8)))
        y = AlgorithmB(nroot_b, number, NTL::ZZ(1));
    else
        y = AlgorithmN(nroot_b, number, NTL::ZZ(1));

    NTL::PrimeSeq p;
    while(p.next() < f)
    {
    	NTL::ZZ x = AlgorithmK(number, p, y);
    	if (x > 0)
    		return false;
    }
    return true;
}

NTL::ZZ AKS::AlgorithmB(NTL::ZZ b, NTL::ZZ y, NTL::ZZ k)
{
	long g = 1;
	while(true)
	{
		if (NTL::power(NTL::ZZ(2), g - 1) < y && NTL::power(NTL::ZZ(2), g) > y)
			break;
		g++;
	}
	NTL::ZZ b_capital = NTL::conv<NTL::ZZ>(NTL::ceil(NTL::conv<NTL::RR>(NTL::log(66 * (2 * k + 1)))));
	NTL::ZZ a = NTL::conv<NTL::ZZ>(NTL::floor(NTL::conv<NTL::RR>(NTL::ZZ(-g) / k)));

	NTL::ZZ z = NTL::power(NTL::ZZ(2), NTL::conv<long>(a)) + NTL::power(NTL::ZZ(2), NTL::conv<long>(a - 1));
	NTL::ZZ j(1);

	do {
		if (j == b)
			return z;
		NTL::RR r = NTL::TruncPrec(NTL::power(), b)
	} while (true);
}

NTL::RR AKS::AlgorithmP(NTL::RR r, NTL::ZZ k, NTL::ZZ b)
{
	if (k == 1)
		return NTL::TruncPrec(r, NTL::conv<long>(b));
	if (k % 2 == 0)
	{
		return NTL::TruncPrec(AKS::AlgorithmP(r, k/2, b) ^ 2, NTL::conv<long>(b));
	}
}
//
//NTL::RR AKS::AlgorithmN(NTL::RR b, NTL::ZZ y, NTL::ZZ k)
//{
//	NTL::RR b_prime = NTL::ceil(NTL::RR(NTL::log(2 * k))) + NTL::ceil(NTL::RR((b - NTL::ceil(NTL::RR(NTL::log(2 * k)))) / 2));
//	NTL::RR b_capital = 2 * b_prime + 4 - NTL::ceil(NTL::RR(NTL::log(k)));
//
//	if (b_prime <= NTL::RR(NTL::ceil(NTL::RR(NTL::log(8 * k)))))
//	{
//		NTL::RR z = AKS::AlgorithmB(b_prime, y, k);
//	}
//	else
//	{
//		NTL::RR z = AKS::AlgorithmN(b_prime, y, k);
//	}
//
////	NTL::RR r2 = ;
////	NTL::RR r3 = ;
//	NTL::RR r4;
//	return r4;
//}
