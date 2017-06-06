#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <NTL/tools.h>

class AKS {
public:
    AKS(NTL::ZZ number);
    bool AlgorithmX(NTL::ZZ number);
private:
    NTL::ZZ number;
    NTL::ZZ AlgorithmB(NTL::ZZ b, NTL::ZZ y, NTL::ZZ k);
    NTL::ZZ AlgorithmN(NTL::ZZ b, NTL::ZZ y, NTL::ZZ k);
    NTL::RR AlgorithmP(NTL::RR r, NTL::ZZ k, NTL::ZZ b);
};
