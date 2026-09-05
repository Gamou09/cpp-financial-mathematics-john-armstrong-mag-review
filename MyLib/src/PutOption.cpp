//
//  PutOption.cpp
//  MyLib
//
//  Created by Martial Aguessi on 26/06/2025.
//

#include "stdafx.h"

// defintion of constructors
PutOption::PutOption(): strike(0.0), maturity(0.0){};
PutOption::PutOption(const double strike_, const double maturity_) : strike(strike_), maturity(maturity_){};

// getter functions
double PutOption::getStrike() const {
    return strike ;
}

double PutOption::getMaturity() const {
    return maturity ;
}

// questions - how to I test these function ?

// Setter functions to be used since the member variables are private
void PutOption::setStrike(double inputStrike){
    strike = inputStrike ;
}

static void testPutOptionSetStrike(){
    
    PutOption putOption ;
    putOption.setStrike(105.0) ;
    ASSERT(putOption.getStrike() == 105.0) ;
}

void PutOption::setMaturity(double inputMaturity){
    maturity = inputMaturity ;
}

static void testPutOptionSetMaturity(){
    
    PutOption putOption ;
    putOption.setMaturity(2.0) ;
    ASSERT(putOption.getMaturity() == 2.0) ;
}

// Implementation of PutOption class methods
double PutOption::payoff( double stockAtMaturity) const {
    
    // we don't nee to pass strike as a arg of the method payoff since it's already a member variable of the class PutOption
    if (stockAtMaturity < strike) return strike - stockAtMaturity ;
    else return 0.0 ;
}

static void testPutOptionPayoff(){
    
    PutOption putOption;
    putOption.setStrike(105.0) ;
    
    // ITM
    double stockAtMaturity = 100 ;
    double payoff = putOption.payoff(stockAtMaturity) ;
    ASSERT_APPROX_EQUAL(payoff, 5, 1e-2) ;
    
    // OTM
    double stockAtMaturity2 = 110 ;
    double payoff2 = putOption.payoff(stockAtMaturity2) ;
    ASSERT_APPROX_EQUAL(payoff2, 0, 1e-2) ;
}

double PutOption::price( const BlackScholesModel& bsm) const {
    
    double S = bsm.stockPrice ;
    double K = strike ;
    double sigma = bsm.volatility ;
    double r = bsm.riskFreeRate ;
    double T = maturity - bsm.date ;
    
    double numerator = log(S/K) + (r + sigma*sigma*0.5)*T ;
    double denominator = sigma*sqrt(T) ;
    
    double d1 = numerator / denominator ;
    double d2 = d1 - denominator ;
    
    return K*exp(-r*T)*normcdf(-d2) - S*normcdf(-d1);
}

static void testPutOptionPrice(){
    
    PutOption putOption;
    putOption.setStrike(105.0) ;
    putOption.setMaturity(2.0) ;
    
    BlackScholesModel bsm ;
    bsm.date = 1.0 ;
    bsm.volatility = 0.1 ;
    bsm.riskFreeRate = 0.05 ;
    bsm.stockPrice = 100 ;
    
    double price = putOption.price(bsm) ;
    ASSERT_APPROX_EQUAL(price, 3.9252, 1e-2) ;
}


void testPutOption(){
    TEST( testPutOptionSetStrike) ;
    TEST( testPutOptionSetMaturity ) ;
    TEST( testPutOptionPayoff ) ;
    TEST( testPutOptionPrice) ;
}

