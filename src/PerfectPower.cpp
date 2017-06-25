#include "PerfectPower.h"

using namespace NTL;

bool PerfectPower::AlgorithmX(ZZ number)
{
    int f, nroot_b;
    double y;

    f = floor(log2(2 * number));
    nroot_b = 3 + ceil(f / 2);

    if (nroot_b <= ceil(log2(8)))
        y = AlgorithmB(nroot_b, conv<RR>(number), 1);
    else
        y = AlgorithmN(nroot_b, conv<RR>(number), 1);

    PrimeSeq p;
    long i = p.next();
    while(i < f)
    {
    	RR x = AlgorithmK(number, i, RR(y));
    	if (x > 0)
    		return true;
    	i = p.next();
    }
    return false;
}

double PerfectPower::AlgorithmB(int b, RR y, int k)
{
	int g = 0;
	int gn = -1;
	while(true)
	{
		if (pow(2, g - 1) < y && pow(2, g) >= y)
			break;
		if (pow(2, gn - 1) < y && pow(2, gn) >= y)
		{
			g = gn;
			break;
		}
		g++;
		gn--;
	}

	int a = floor(-g / k);

	double z = pow(2, a) + pow(2, a - 1);
	int j = 1;

	do {
		if (j == b)
			return z;
		RR r = pow(z, k) * y;

		if (r <= 0.9697265625)
			z = z + pow(2, a - j - 1);
		if (r > 1)
			z = z - pow(2, a -j -1);
		j++;
	} while (true);
}

double PerfectPower::AlgorithmN(int b, RR y, int k)
{
	int b_prime = ceil(log2(2 * k)) + ceil((b - ceil(log2(2 * k))) / 2);

	double z;

	if (b_prime <= ceil(log2(8 * k)))
		z = AlgorithmB(b_prime, y, k);
	else
		z = AlgorithmN(b_prime, y, k);

	double r2 = z * (k + 1);
	double r3 = pow(z, k + 1) * NTL::conv<double>(y);
	double r4 = (r2 - r3) / k;

	return r4;
}

RR PerfectPower::AlgorithmK(ZZ number, long k, RR y)
{
	int f = floor(log2(2 * number));
	int b = 3 + ceil(f / k);

	RR r;

	if (b <= ceil(log2(8 * k)))
		r = AlgorithmB(b, y, k);
	else
		r = AlgorithmN(b, y, k);

	RR x(0);

	if (fabs(r - floor(r)) <= 0.625)
		x = floor(r);
	else if (fabs(r - ceil(r)) <= 0.625)
		x = ceil(r);

	if (x == 0.0 || fabs(r - x) >= 0.25)
		return RR(0);

	if (number == power(conv<ZZ>(x), k))
		return x;
	return RR(0);
}
