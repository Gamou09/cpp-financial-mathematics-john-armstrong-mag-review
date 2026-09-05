//
//  derivatives.cpp
//  MyLib
//
//  Created by Martial Aguessi on 26/05/2025.
//

//#include "derivatives.hpp"
#include "stdafx.h"

// using namespace
using namespace std ;

// Black-Scholes price for a European put option
double black_scholes_put(double S, double K, double r, double sigma, double T) {
    
    if (T <= 0 || sigma <= 0 || S <= 0 || K <= 0) return 0.0;

    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    return K * exp(-r * T) * normcdf(-d2) - S * normcdf(-d1);
}

void test_black_scholes_put() {
    double S = 100.0;    // Spot price
    double K = 100.0;    // Strike price
    double r = 0.05;     // Risk-free rate
    double sigma = 0.2;  // Volatility
    double T = 1.0;      // Time to maturity in years
    
    // Test
    // Compare with known result (e.g. from Excel or QuantLib)
    DEBUG_PRINT( "test_black_scholes_put(" << S << ", " << K << ", " << r << ", " << sigma << ", " << ")" );
    double price = black_scholes_put(S, K, r, sigma, T);
    double expected = 5.5735;
    ASSERT_APPROX_EQUAL(price, expected, 1e-2) ;
    
}

// Black-Scholes price for a European Call option
double black_scholes_call(double S, double K, double r, double sigma, double T) {
    
    if (T <= 0 || sigma <= 0 || S <= 0 || K <= 0) return 0.0;

    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    return S * normcdf(d1) - K * exp(-r * T) * normcdf(d2);
}

void test_black_scholes_call() {
    double S = 100.0;    // Spot price
    double K = 100.0;    // Strike price
    double r = 0.05;     // Risk-free rate
    double sigma = 0.2;  // Volatility
    double T = 1.0;      // Time to maturity in years
    
    // Test
    // Compare with known result (e.g. from Excel or QuantLib)
    DEBUG_PRINT( "test_black_scholes_call(" << S << ", " << K << ", " << r << ", " << sigma << ", " << ")" );
    double price = black_scholes_call(S, K, r, sigma, T);
    double expected = 10.451;
    ASSERT_APPROX_EQUAL(price, expected, 1e-2) ;
    
}

void testDerivatives(){
    //    switch on the DEBUG_PRINT statements
    setDebugEnabled(true) ;
    TEST( test_black_scholes_put ); // should not be called witht he parenthesis
    setDebugEnabled(false) ;
    TEST( test_black_scholes_call );
}

