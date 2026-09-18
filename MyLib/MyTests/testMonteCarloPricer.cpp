//
//  testMonteCarloPricer.cpp
//  MyTests
//
//  Created by Martial Aguessi on 08/09/2026.
//

#include "MonteCarloPricer.hpp"
#include "CallOption.hpp"
#include "BlackScholesModel.hpp"
#include "PutOption.hpp"
#include "matlib.h" // rng("default") to fix the seed
#include "DigitalCallOption.hpp"
#include "UpAndOutCallOption.hpp"

static void testPriceCallOption(){
    
    // fix the seed
    rng("default") ;
    
    // definition the call option
    CallOption c ;
    c.setStrike(110.0) ;
    c.setMaturity(2.0) ;
    
    // definition of the model
    BlackScholesModel bsm ;
    bsm.setVolatility(0.1) ;
    bsm.setRiskFreeRate(0.05) ;
    bsm.setStockPrice(100.0) ;
    bsm.setDrift(0.1) ;
    bsm.setDate(1.0);
    
    // Price using Monte Carlo
    MonteCarloPricer monteCarloPricer ;
    double price = monteCarloPricer.price(c, bsm) ;
    double expected = c.price(bsm) ;
    ASSERT_APPROX_EQUAL(price, expected, 0.2) ;
    
}

static void testPricePutOption(){
    
    // fix the seed
    rng("default") ;
    
    // definition the Put option
    PutOption p ;
    p.setStrike(90) ;
    p.setMaturity(3) ;
    
    // definition of the model
    BlackScholesModel bsm ;
    bsm.setVolatility(0.1) ;
    bsm.setRiskFreeRate(0.05) ;
    bsm.setStockPrice(100.0) ;
    bsm.setDrift(0.1) ;
    bsm.setDate(1.0);
    
    // Use the pricer
    MonteCarloPricer monteCarloPricer ;
    double price = monteCarloPricer.price(p, bsm) ;
    double expected = p.price(bsm) ;
    ASSERT_APPROX_EQUAL(price, expected, 0.2) ;
    
}

static void testPutAndCall(){
    
    // Fix random seed
    rng("default") ;
    
    // Definte the Black-Scholes model
    BlackScholesModel m;
    m.setVolatility(0.1) ;
    m.setRiskFreeRate(0.05) ;
    m.setStockPrice(100.0) ;
    m.setDrift(0.1) ;
    
    // Define call option
    CallOption c ;
    c.setStrike(110) ;
    c.setMaturity(2.0) ;

    // definte Put option
    PutOption p ;
    p.setStrike(c.getStrike()) ;
    p.setMaturity(c.getMaturity()) ;
    
    // Our pricer can price puts and calls
    MonteCarloPricer pricer ;
    double priceC = pricer.price(c,m);
    ASSERT_APPROX_EQUAL(priceC, c.price(m), 0.2);
    
    double priceP = pricer.price(p,m);
    ASSERT_APPROX_EQUAL(priceP, p.price(m), 0.2);
    
}

static void testDigitalCallOption(){
    
    // Fix random seed
    rng("default") ;
    
    // Definte the Black-Scholes model
    BlackScholesModel m;
    m.setVolatility(0.1) ;
    m.setRiskFreeRate(0.05) ;
    m.setStockPrice(100.0) ;
    m.setDrift(0.1) ;

    // Define Digital Call Option
    DigitalCallOption digitCallOption(100, 2) ;
    
    // Out pricer
    MonteCarloPricer pricer ;
    double digitCallOptionPrice = pricer.price(digitCallOption, m) ;
    ASSERT_APPROX_EQUAL(digitCallOptionPrice, digitCallOption.price(m), 0.2) ;
}


static void testMonteCarloPricerPathDependentOption() {

    BlackScholesModel bsm;
    
    bsm.setVolatility(0.2) ;
    bsm.setRiskFreeRate(0.05) ;
    bsm.setStockPrice(100.0) ;
    bsm.setDate(0.0);

    UpAndOutCallOption option(
        100.0,
        0.0,
        1.0
    );

    MonteCarloPricer pricer;

    double actualPrice = pricer.price(option, bsm);

    ASSERT_APPROX_EQUAL(
        0.0,
        actualPrice,
        1e-12
    );
}

void testMonteCarloPricer() {
    
    std::cout << "\n.... Start of testMonteCarloPricer ....\n" << std::endl;
    
    TEST( testPriceCallOption ) ;
    
    TEST( testPricePutOption ) ;
    
    TEST( testPutAndCall ) ;
    
    setDebugEnabled(true) ;
    TEST( testDigitalCallOption ) ;
    setDebugEnabled(false) ;
    
    TEST( testMonteCarloPricerPathDependentOption ) ;
    
    std::cout << "\n ......................................... \n" << std::endl;
}


