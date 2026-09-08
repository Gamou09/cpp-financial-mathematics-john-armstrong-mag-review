//
//  MonteCarloPricer.cpp
//  MyLib
//
//  Created by Martial Aguessi on 30/06/2025.
//

// we want to precise and directly call the header needed
// #include "stdafx.h"
#include "MonteCarloPricer.hpp"
#include "BlackScholesModel.hpp"
#include "CallOption.hpp"
#include "PutOption.hpp"

using namespace std ;

/* define Constructor */
MonteCarloPricer::MonteCarloPricer() : nScenarios(10000) {};

/* define and test Price a call option */
double MonteCarloPricer::price (const CallOption& callOption,
                                const BlackScholesModel& bsm) {
    
    double total = 0.0 ;
    for ( int i = 0 ; i < nScenarios ; i++) {
        vector<double> path = bsm.generateRiskNeutralPricePath(callOption.maturity, 1) ;
        double stockPrice = path.back() ;
        double payoff = callOption.payoff(stockPrice) ;
        total += payoff ;
    }
    
    double mean = total / nScenarios ;
    double r = bsm.riskFreeRate ;
    double T = callOption.maturity - bsm.date ;
    
    return  exp(-r*T)*mean ;
}

/* define and test Price a put option */
double MonteCarloPricer::price (const PutOption& putOption,
                                const BlackScholesModel& bsm) {
    
    double total = 0.0 ;
    for ( int i = 0 ; i < nScenarios ; i++) {
        vector<double> path = bsm.generateRiskNeutralPricePath(putOption.getMaturity(), 1) ;
        double stockPrice = path.back() ;
        double payoff = putOption.payoff(stockPrice) ;
        total += payoff ;
    }
    
    double mean = total / nScenarios ;
    double r = bsm.riskFreeRate ;
    double T = putOption.getMaturity() - bsm.date ;
    
    return  exp(-r*T)*mean ;
}

/* define and test Price a generic Path independent option */
double MonteCarloPricer::price (const PathIndependentOption& pathIndepentOption,
                                const BlackScholesModel& bsm) {
    
    double total = 0.0 ;
    for ( int i = 0 ; i < nScenarios ; i++) {
        vector<double> pricePath = bsm.generateRiskNeutralPricePath(pathIndepentOption.getMaturity(), 1) ;
        double stockPrice = pricePath.back() ;
        double payoff = pathIndepentOption.payoff(stockPrice) ;
        total += payoff ;
    }
    
    double mean = total / nScenarios ;
    double r = bsm.riskFreeRate ;
    double T = pathIndepentOption.getMaturity() - bsm.date ;
    
    return  exp(-r*T)*mean ;
}
