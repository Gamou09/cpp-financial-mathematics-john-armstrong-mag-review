//
//  CallOption.cpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#include "CallOption.hpp"
#include "BlackScholesModel.hpp"
#include "PathIndependentOption.hpp"
#include "matlib.h"

// chap 8 - Implementation of payoff for a call option
double CallOption::payoff( double stockAtMaturity) const {
    
    // we don't nee to pass strike as a arg of the method payoff since it's already a member variable of the class CallOption
    if (stockAtMaturity > getStrike()) return stockAtMaturity - getStrike() ;
    else return 0.0 ;
}

double CallOption::price( const BlackScholesModel& bsm) const {
    
    double S = bsm.stockPrice ;
    double K = getStrike() ;
    double sigma = bsm.volatility ;
    double r = bsm.riskFreeRate ;
    double T = getMaturity() - bsm.date ;
    
    double numerator = log(S/K) + (r + sigma*sigma*0.5)*T ;
    double denominator = sigma*sqrt(T) ;
    
    double d1 = numerator / denominator ;
    double d2 = d1 - denominator ;
    
    return S*normcdf(d1) - K*exp(-r*T)*normcdf(d2);
}
