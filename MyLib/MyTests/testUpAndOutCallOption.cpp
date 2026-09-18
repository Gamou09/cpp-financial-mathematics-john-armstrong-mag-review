//
//  testUpAndOutCallOption.cpp
//  MyTests
//
//  Created by Martial Aguessi on 15/09/2026.
//

#include <stdio.h>

#include "testing.hpp"
#include "UpAndOutCallOption.hpp"
#include "BlackScholesModel.hpp"
#include "MonteCarloPricer.hpp"

#include <vector>


static void testUpAndOutCallOptionGetMaturity() {

    UpAndOutCallOption option(
        100.0,   // strike
        130.0,   // barrier
        1.0      // maturity
    );

    ASSERT_APPROX_EQUAL(
        1.0,
        option.getMaturity(),
        1e-12
    );
}


static void testUpAndOutCallOptionPayoff() {

    UpAndOutCallOption option(
        100.0,
        130.0,
        1.0
    );

    // Barrier not reached and option finishes ITM.
    std::vector<double> path1 {
        100.0, 105.0, 110.0, 120.0
    };

    ASSERT_APPROX_EQUAL(
        20.0,
        option.payoff(path1),
        1e-12
    );


    // Barrier touched exactly -> option knocked out.
    std::vector<double> path2 {
        100.0, 110.0, 130.0, 120.0
    };

    ASSERT_APPROX_EQUAL(
        0.0,
        option.payoff(path2),
        1e-12
    );


    // Barrier exceeded -> option knocked out.
    std::vector<double> path3 {
        100.0, 110.0, 135.0, 120.0
    };

    ASSERT_APPROX_EQUAL(
        0.0,
        option.payoff(path3),
        1e-12
    );


    // Barrier not reached, but call finishes OTM.
    std::vector<double> path4 {
        100.0, 95.0, 90.0
    };

    ASSERT_APPROX_EQUAL(
        0.0,
        option.payoff(path4),
        1e-12
    );
}


static void testUpAndOutCallOptionPrice() {

    BlackScholesModel bsm;

    bsm.setDate(0.0) ;
    bsm.setStockPrice(100.0);
    bsm.setRiskFreeRate(0.05);
    bsm.setVolatility(0.20) ;

    // Barrier = 0 means every positive simulated path
    // is immediately knocked out.
    UpAndOutCallOption option(
        100.0,
        0.0,
        1.0
    );

    double actualPrice = option.price(bsm);

    ASSERT_APPROX_EQUAL(
        0.0,
        actualPrice,
        1e-12
    );
}

void testUpAndOutCallOption() {
    
    std::cout << "\n.... Start of testUpAndOutCallOption ....\n" << std::endl;
    
    TEST( testUpAndOutCallOptionGetMaturity ) ;
    TEST( testUpAndOutCallOptionPayoff ) ;
    
    setDebugEnabled(true) ;
    TEST( testUpAndOutCallOptionPrice ) ;
    setDebugEnabled(false) ;
    
    std::cout << "\n ......................................... \n" << std::endl;
}

