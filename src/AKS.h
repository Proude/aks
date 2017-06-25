#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <NTL/ZZXFactoring.h>
#include <NTL/tools.h>
#include "LPF.h"
#include "PerfectPower.h"
#include <gmp.h>

class AKS {
public:
	AKS(NTL::ZZ number);
	bool AKSAlgorithm();
private:
    NTL::ZZ number;
    bool congruence(int a, long r);
};
