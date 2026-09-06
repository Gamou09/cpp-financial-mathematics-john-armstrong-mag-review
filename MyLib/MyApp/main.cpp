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

    std::cout << "\n1 - The call Option with default constructor\n";
    CallOption callOption;

    double spot = 120.0;
    double strike = callOption.strike ;
    double payoff = callOption.payoff(spot);
    double maturity = callOption.maturity ;

    std::cout << "Spot price: " << spot << '\n';
    std::cout << "Spot strike: " << strike << '\n';
    std::cout << "Call payoff: " << payoff << '\n';
    std::cout << "Call maturity: " << maturity << '\n';
    
    std::cout << "\n2 - The call Option with strike and maturity\n";
    CallOption callOption2(100, 5);

    double spot2 = 120.0;
    double strike2 = callOption2.strike ;
    double payoff2 = callOption2.payoff(spot);
    double maturity2 = callOption2.maturity ;


    std::cout << "Spot price: " << spot2 << '\n';
    std::cout << "Spot strike: " << strike2 << '\n';
    std::cout << "Call payoff: " << payoff2 << '\n';
    std::cout << "Call maturity: " << maturity2 << '\n';

    return 0;
    
}
