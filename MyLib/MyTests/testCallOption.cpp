//
//  testCallOption.cpp
//  MyTests
//
//  Created by Martial Aguessi on 06/09/2026.
//


#include "testing.hpp"
#include "CallOption.hpp"
#include "BlackScholesModel.hpp"

static void testCallOptionPayoff(){
    
    CallOption callOption;
    callOption.strike = 105.0 ;
    
    // OTM
    double stockAtMaturity = 100 ;
    double payoff = callOption.payoff(stockAtMaturity) ;
    ASSERT_APPROX_EQUAL(payoff, 0, 1e-2) ;
    
    // ITM
    double stockAtMaturity2 = 110 ;
    double payoff2 = callOption.payoff(stockAtMaturity2) ;
    ASSERT_APPROX_EQUAL(payoff2, 5, 1e-2) ;
}

static void testCallOptionPrice(){
    
    CallOption callOption;
    callOption.strike = 105.0 ;
    callOption.maturity = 2.0 ;
    
    BlackScholesModel bsm ;
    bsm.date = 1.0 ;
    bsm.volatility = 0.1 ;
    bsm.riskFreeRate = 0.05 ;
    bsm.stockPrice = 100 ;
    
    double price = callOption.price(bsm) ;
    ASSERT_APPROX_EQUAL(price, 4.046, 1e-2) ;
}
// Test chap 8.6.1 - Call Option class
void testCallOption(){
    
    std::cout << "\n.... Start of testCallOption ....\n" << std::endl;
    
    TEST( testCallOptionPayoff) ;
    //    switch on the DEBUG_PRINT statements
    setDebugEnabled(true) ;
    TEST( testCallOptionPrice) ;
    setDebugEnabled(false) ;
    
    std::cout << "\n.........................................\n" << std::endl;
}
