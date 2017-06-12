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
    NTL::ZZ a(2);

    std::cout << "Give a number to test" << std::endl;
    std::cin >> a;
//    while(true)
//    {
		AKS number(a);
		if (number.AlgorithmX())
			std::cout << a << " is perfect power" << std::endl;
		else
			std::cout << a << " is not a perfect power" << std::endl;
		a++;
//    }
    return 0;
}
