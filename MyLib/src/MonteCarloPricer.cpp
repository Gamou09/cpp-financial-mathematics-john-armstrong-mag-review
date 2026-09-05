//
//  MonteCarloPricer.cpp
//  MyLib
//
//  Created by Martial Aguessi on 30/06/2025.
//

#include "stdafx.h"

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

static void testPriceCallOption(){
    
    // fix the seed
    rng("default") ;
    
    // definition the call option
    CallOption c ;
    c.strike = 110 ;
    c.maturity = 2 ;
    
    // definition of the model
    BlackScholesModel bsm ;
    bsm.volatility = 0.1 ;
    bsm.riskFreeRate = 0.05 ;
    bsm.stockPrice = 100 ;
    bsm.drift = 0.1 ;
    bsm.date = 1 ;
    
    // Use the pricer
    MonteCarloPricer monteCarloPricer ;
    double price = monteCarloPricer.price(c, bsm) ;
    double expected = c.price(bsm) ;
    ASSERT_APPROX_EQUAL(price, expected, 1e-1) ;
    
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

static void testPricePutOption(){
    
    // fix the seed
    rng("default") ;
    
    // definition the call option
    PutOption p ;
    p.setStrike(90) ;
    p.setMaturity(3) ;
    
    // definition of the model
    BlackScholesModel bsm ;
    bsm.volatility = 0.1 ;
    bsm.riskFreeRate = 0.05 ;
    bsm.stockPrice = 100 ;
    bsm.drift = 0.1 ;
    bsm.date = 1 ;
    
    // Use the pricer
    MonteCarloPricer monteCarloPricer ;
    double price = monteCarloPricer.price(p, bsm) ;
    double expected = p.price(bsm) ;
    ASSERT_APPROX_EQUAL(price, expected, 1e-1) ;
    
}

/* define and test Price a generic Path independent option */
double MonteCarloPricer::price (const PathIndependentOption& option,
                                const BlackScholesModel& bsm) {
    
    double total = 0.0 ;
    for ( int i = 0 ; i < nScenarios ; i++) {
        vector<double> path = bsm.generateRiskNeutralPricePath(option.getMaturity(), 1) ;
        double stockPrice = path.back() ;
        double payoff = option.payoff(stockPrice) ;
        total += payoff ;
    }
    
    double mean = total / nScenarios ;
    double r = bsm.riskFreeRate ;
    double T = option.getMaturity() - bsm.date ;
    
    return  exp(-r*T)*mean ;
}

static void testPutAndCall(){
    
    rng("default") ;
    
    BlackScholesModel m;
    m.volatility = 0.1 ;
    m.riskFreeRate = 0.05 ;
    m.stockPrice = 100.0 ;
    m.drift = 0.1 ;
    
    CallOption c ;
    c.strike = 110 ;
    c.maturity = 2;

    PutOption p ;
    p.setStrike(c.strike) ;
    p.setMaturity(c.maturity) ;
    
    // Our pricer can price puts and calls
    MonteCarloPricer pricer ;
    double priceC = pricer.price(c,m);
    ASSERT_APPROX_EQUAL(priceC, c.price(m), 0.1);
    double priceP = pricer.price(p,m);
    ASSERT_APPROX_EQUAL(priceP, p.price(m), 0.1);
    
}

void testMonteCarloPricer() {
    
    TEST( testPriceCallOption ) ;
    TEST( testPricePutOption ) ;
    TEST( testPutAndCall ) ;
    
}


