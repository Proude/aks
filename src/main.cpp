//============================================================================
// Name        : AKS.cpp
// Author      : Anastasios Gemtos
// Version     :
// Copyright   : University of Bath
// Description : AKS algorithm in C++
//============================================================================

#include <iostream>
#include "AKS.h"

int main() {
    NTL::ZZ a;

    std::cout << "Give a number to test" << std::endl;
    std::cin >> a;
    AKS number(a);
    number.AlgorithmX(a);

    return 0;
}
