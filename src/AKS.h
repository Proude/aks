#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <NTL/ZZXFactoring.h>
#include <NTL/tools.h>
#include "LPF.h"
#include "PerfectPower.h"
#include "Utilities.h"
#include <gmp.h>

class AKS {
public:
	AKS(NTL::ZZ number);
	bool AKSAlgorithm();
	bool AKSAlgorithm_Bernstein();
	int phi(NTL::ZZ r);
	int phi(int r);
	int primitiveModulo();
	void setNumber(NTL::ZZ number) { this->number = number; }
private:
    NTL::ZZ number;
    PerfectPower pp;
    Utilities tools;
    LPF lpf;
    bool congruence(int a, NTL::ZZ_pX rhs, NTL::ZZ_pX lhs, NTL::ZZ_pXModulus pf);
    int findRBernstein();
    bool isPrimitiveModulo(long r);
    int findRMultiplicativeOrder();
    int order(int r);
    int order(NTL::ZZ number, NTL::ZZ r);
    long findS(const long r, const double d, const double i, const double j);
    long findSB(const long r, double d, double i, double j);
};
