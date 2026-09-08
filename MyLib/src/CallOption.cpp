//
//  CallOption.cpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#include "CallOption.hpp"
#include "BlackScholesModel.hpp"

// default constructor implementation
CallOption::CallOption() : strike(0.0), maturity(0.0){}

// Alternative constructor implementation
CallOption::CallOption(double s, double m): strike(s), maturity(m){}

// chap 8 - Implementation of payoff for a call option
double CallOption::payoff( double stockAtMaturity) const {
    
    // we don't nee to pass strike as a arg of the method payoff since it's already a member variable of the class CallOption
    if (stockAtMaturity > strike) return stockAtMaturity - strike ;
    else return 0.0 ;
}

double CallOption::getMaturity() const {
    return maturity ;
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
