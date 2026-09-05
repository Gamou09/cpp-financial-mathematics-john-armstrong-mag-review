//
//  CallOption.cpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#include "stdafx.h"

// chap 8 - Implementation of payoff for a call option
double CallOption::payoff( double stockAtMaturity) const {
    
    // we don't nee to pass strike as a arg of the method payoff since it's already a member variable of the class CallOption
    if (stockAtMaturity > strike) return stockAtMaturity - strike ;
    else return 0.0 ;
}

double CallOption::price( const BlackScholesModel& bsm) const {
    
    double S = bsm.stockPrice ;
    double K = strike ;
    double sigma = bsm.volatility ;
    double r = bsm.riskFreeRate ;
    double T = maturity - bsm.date ;
    
    double numerator = log(S/K) + (r + sigma*sigma*0.5)*T ;
    double denominator = sigma*sqrt(T) ;
    
    double d1 = numerator / denominator ;
    double d2 = d1 - denominator ;
    
    return S*normcdf(d1) - K*exp(-r*T)*normcdf(d2);
}


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

static void testCallOptionprice(){
    
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

// default constructor implementation
CallOption::CallOption() : strike(0.0), maturity(0.0){}

// Alternative constructor implementation
CallOption::CallOption(double s, double m): strike(m), maturity(m){}

void testCallOption(){
    TEST( testCallOptionPayoff) ; 
    //    switch on the DEBUG_PRINT statements
    setDebugEnabled(true) ;
    TEST( testCallOptionprice) ;
    setDebugEnabled(false) ;
}

