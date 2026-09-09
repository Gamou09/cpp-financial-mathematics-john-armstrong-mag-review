//
//  testDigitalCallOption.cpp
//  MyTests
//
//  Created by Martial Aguessi on 09/09/2026.
//

#include "testing.hpp"
#include "DigitalCallOption.hpp"
#include "BlackScholesModel.hpp"


static void testDigitalCallOptionDefaultConstructor(){

    DigitalCallOption digitalCallOption;

    ASSERT_APPROX_EQUAL(digitalCallOption.getStrike(), 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(digitalCallOption.getMaturity(), 0.0, 1e-12);
}


static void testDigitalCallOptionConstructor(){

    DigitalCallOption digitalCallOption(105.0, 2.0);

    ASSERT_APPROX_EQUAL(digitalCallOption.getStrike(), 105.0, 1e-12);
    ASSERT_APPROX_EQUAL(digitalCallOption.getMaturity(), 2.0, 1e-12);
}


static void testDigitalCallOptionSettersGetters(){

    DigitalCallOption digitalCallOption;

    digitalCallOption.setStrike(110.0);
    digitalCallOption.setMaturity(3.0);

    ASSERT_APPROX_EQUAL(digitalCallOption.getStrike(), 110.0, 1e-12);
    ASSERT_APPROX_EQUAL(digitalCallOption.getMaturity(), 3.0, 1e-12);
}


static void testDigitalCallOptionPayoff(){

    DigitalCallOption digitalCallOption(105.0, 2.0);

    // OTM
    double stockAtMaturity = 100.0;
    double payoff = digitalCallOption.payoff(stockAtMaturity);

    ASSERT_APPROX_EQUAL(payoff, 0.0, 1e-12);


    // ATM
    double stockAtMaturity2 = 105.0;
    double payoff2 = digitalCallOption.payoff(stockAtMaturity2);

    ASSERT_APPROX_EQUAL(payoff2, 0.0, 1e-12);


    // ITM
    double stockAtMaturity3 = 110.0;
    double payoff3 = digitalCallOption.payoff(stockAtMaturity3);

    ASSERT_APPROX_EQUAL(payoff3, 1.0, 1e-12);
}


static void testDigitalCallOptionPrice(){

    DigitalCallOption digitalCallOption(105.0, 2.0);

    BlackScholesModel bsm;

    bsm.date = 1.0;
    bsm.volatility = 0.1;
    bsm.riskFreeRate = 0.05;
    bsm.stockPrice = 100.0;

    double price = digitalCallOption.price(bsm);

    ASSERT_APPROX_EQUAL(price, 0.4612, 1e-2);
}


// Test Digital Call Option class
void testDigitalCallOption(){
    
    std::cout << "\n.... Start of testDigitalCallOption ....\n" << std::endl;

    TEST(testDigitalCallOptionDefaultConstructor);

    TEST(testDigitalCallOptionConstructor);

    TEST(testDigitalCallOptionSettersGetters);

    TEST(testDigitalCallOptionPayoff);

    setDebugEnabled(true);

    TEST(testDigitalCallOptionPrice);

    setDebugEnabled(false);
    
    std::cout << "\n ......................................... \n" << std::endl;
}
