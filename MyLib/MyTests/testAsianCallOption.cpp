//
//  testAsianCallOption.cpp
//  MyTests
//
//  Created by Martial Aguessi on 16/09/2026.
//

#include "testing.hpp"
#include "AsianCallOption.hpp"
#include "BlackScholesModel.hpp"
#include "MonteCarloPricer.hpp"

#include <vector>


// Test that maturity is correctly passed through the inheritance chain:
// AsianCallOption -> PathDependentOption -> ContinuousTimeOptionBase.
static void testAsianCallOptionGetMaturity() {

    AsianCallOption option(
        100.0,   // strike
        1.0      // maturity
    );

    ASSERT_APPROX_EQUAL(
        1.0,
        option.getMaturity(),
        1e-12
    );
}


// Test the arithmetic-average Asian call payoff.
static void testAsianCallOptionPayoff() {

    AsianCallOption option(
        100.0,   // strike
        1.0      // maturity
    );


    // Average stock price:
    // (100 + 110 + 120 + 130) / 4 = 115
    //
    // Payoff:
    // max(115 - 100, 0) = 15
    std::vector<double> path1 {
        100.0, 110.0, 120.0, 130.0
    };

    ASSERT_APPROX_EQUAL(
        15.0,
        option.payoff(path1),
        1e-12
    );


    // Average stock price:
    // (80 + 90 + 100 + 110) / 4 = 95
    //
    // Average is below the strike, therefore the option expires OTM.
    //
    // Payoff:
    // max(95 - 100, 0) = 0
    std::vector<double> path2 {
        80.0, 90.0, 100.0, 110.0
    };

    ASSERT_APPROX_EQUAL(
        0.0,
        option.payoff(path2),
        1e-12
    );


    // Average stock price:
    // (90 + 100 + 110) / 3 = 100
    //
    // Average is exactly equal to the strike.
    //
    // Payoff:
    // max(100 - 100, 0) = 0
    std::vector<double> path3 {
        90.0, 100.0, 110.0
    };

    ASSERT_APPROX_EQUAL(
        0.0,
        option.payoff(path3),
        1e-12
    );


    // Important path-dependence test:
    //
    // Final stock price = 80, which is below the strike,
    // but the average stock price is:
    //
    // (140 + 140 + 140 + 80) / 4 = 125
    //
    // Therefore the Asian call is still ITM.
    //
    // Payoff:
    // max(125 - 100, 0) = 25
    std::vector<double> path4 {
        140.0, 140.0, 140.0, 80.0
    };

    ASSERT_APPROX_EQUAL(
        25.0,
        option.payoff(path4),
        1e-12
    );
}


// Test the Asian option through the generic Monte Carlo pricer.
//
// We use volatility = 0 and risk-free rate = 0 so that the simulated
// stock path remains deterministic at 100.
//
// With strike = 90:
// average stock price = 100
// payoff = 100 - 90 = 10
// discount factor = 1
//
// Therefore the Monte Carlo price should be exactly 10.
static void testAsianCallOptionPrice() {

    BlackScholesModel bsm;

    bsm.setDate(0.0);
    bsm.setStockPrice(100.0);
    bsm.setRiskFreeRate(0.0) ;
    bsm.setVolatility(0.0) ;

    AsianCallOption option(
        90.0,   // strike
        1.0     // maturity
    );

    MonteCarloPricer pricer;

    double actualPrice = pricer.price(
        option,
        bsm
    );

    ASSERT_APPROX_EQUAL(
        10.0,
        actualPrice,
        1e-12
    );
}


// Run all AsianCallOption tests.
void testAsianCallOption() {

    std::cout
        << "\n.... Start of testAsianCallOption ....\n"
        << std::endl;

    TEST( testAsianCallOptionGetMaturity );

    TEST( testAsianCallOptionPayoff );

    setDebugEnabled(true);

    TEST( testAsianCallOptionPrice );

    setDebugEnabled(false);

    std::cout
        << "\n ..................................... \n"
        << std::endl;
}
