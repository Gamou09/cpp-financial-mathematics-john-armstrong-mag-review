//
//  PutOption.cpp
//  MyLib
//
//  Created by Martial Aguessi on 26/06/2025.
//

// we will be specific and prefer to add the proper header file
// #include "stdafx.h"
#include "PutOption.hpp"
#include "BlackScholesModel.hpp"

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

void PutOption::setMaturity(double inputMaturity){
    maturity = inputMaturity ;
}

// Implementation of PutOption class methods
double PutOption::payoff( double stockAtMaturity) const {
    
    // we don't nee to pass strike as a arg of the method payoff since it's already a member variable of the class PutOption
    if (stockAtMaturity < strike) return strike - stockAtMaturity ;
    else return 0.0 ;
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
