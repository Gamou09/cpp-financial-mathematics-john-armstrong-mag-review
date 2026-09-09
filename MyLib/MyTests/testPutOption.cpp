//
//  testCallOption.cpp
//  MyTests
//
//  Created by Martial Aguessi on 06/09/2026.
//


#include "testing.hpp"
#include "PutOption.hpp"
#include "BlackScholesModel.hpp"

static void testPutOptionSetStrike(){
    
    PutOption putOption ;
    putOption.setStrike(105.0) ;
    ASSERT(putOption.getStrike() == 105.0) ;
}

static void testPutOptionSetMaturity(){
    
    PutOption putOption ;
    putOption.setMaturity(2.0) ;
    ASSERT(putOption.getMaturity() == 2.0) ;
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
    
    std::cout << "\n.... Start of testPutOption ....\n" << std::endl;
    
    TEST( testPutOptionSetStrike) ;
    TEST( testPutOptionSetMaturity ) ;
    TEST( testPutOptionPayoff ) ;
    TEST( testPutOptionPrice) ;
    
    std::cout << "\n.........................................\n" << std::endl;
}
