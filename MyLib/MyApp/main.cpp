//
//  main.cpp
//  MyLib
//
//  Created by Martial Aguessi on 21/05/2025.
//

// Angle bracket vs double quote when importing
// Anlge brackets tell the compiler that this file won't have changed since last compilation
// thus no need to compile again thefere compiler runs faster
#include <iostream>

#include "CallOption.hpp"

// one by one addition of header files
//#include "matlib.h"
//#include "geometry.hpp" // same as h file but h for c++
// #include "stdafx.h"

// simplified addition of header file using the windows convention
// this header file remove redundant typing of include header and library


int main() {
    
    std::cout << "Hello, World!\n";
    std::cout << "Welcome to my App - where I experiment what i built\n\n";
        
    std::cout << "Running MyApp...\n";

    std::cout << "C++ version: ";

    if (__cplusplus >= 202302L)
        std::cout << "C++23";
    else if (__cplusplus >= 202002L)
        std::cout << "C++20";
    else if (__cplusplus >= 201703L)
        std::cout << "C++17";
    else if (__cplusplus >= 201402L)
        std::cout << "C++14";
    else if (__cplusplus >= 201103L)
        std::cout << "C++11";
    else
        std::cout << "Pre-C++11";

    std::cout << " (" << __cplusplus << ")" << std::endl;
    
    std::cout << "\n1 - The call Option with default constructor\n";
    CallOption callOption;

    double spot = 120.0;
    double strike = callOption.getStrike() ;
    double payoff = callOption.payoff(spot);
    double maturity = callOption.getMaturity() ;

    std::cout << "Spot price: " << spot << '\n';
    std::cout << "Spot strike: " << strike << '\n';
    std::cout << "Call payoff: " << payoff << '\n';
    std::cout << "Call maturity: " << maturity << '\n';
    
    std::cout << "\n2 - The call Option with strike and maturity\n";
    CallOption callOption2(100, 5);

    double spot2 = 120.0;
    double strike2 = callOption2.getStrike() ;
    double payoff2 = callOption2.payoff(spot);
    double maturity2 = callOption2.getMaturity() ;


    std::cout << "Spot price: " << spot2 << '\n';
    std::cout << "Spot strike: " << strike2 << '\n';
    std::cout << "Call payoff: " << payoff2 << '\n';
    std::cout << "Call maturity: " << maturity2 << '\n';

    return 0;
    
}
