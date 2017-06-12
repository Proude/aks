#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <NTL/tools.h>

class AKS {
public:
    AKS(NTL::ZZ number);
    bool AlgorithmX();
    bool isPerfectPower();
    inline NTL::RR log2(NTL::RR number) { return NTL::log(number) / NTL::log(NTL::RR(2)); }
    inline NTL::RR log2(NTL::ZZ number) { return NTL::log(number) / NTL::log(NTL::RR(2)); }
private:
    NTL::ZZ number;
    NTL::RR AlgorithmB(NTL::ZZ b, NTL::RR y, NTL::ZZ k);
    NTL::RR AlgorithmN(NTL::ZZ b, NTL::RR y, NTL::ZZ k);
    NTL::RR AlgorithmP(NTL::RR r, NTL::ZZ k, NTL::ZZ b);
    NTL::RR AlgorithmK(NTL::ZZ number, NTL::ZZ k, NTL::RR y);
};
