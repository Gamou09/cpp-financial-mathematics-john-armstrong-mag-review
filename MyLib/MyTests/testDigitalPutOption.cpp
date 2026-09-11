//
//  testDigitalPutOption.cpp
//  MyTests
//
//  Created by Martial Aguessi on 09/09/2026.
//

#include "testing.hpp"
#include "DigitalPutOption.hpp"
#include "BlackScholesModel.hpp"


static void testDigitalPutOptionDefaultConstructor(){

    DigitalPutOption DigitalPutOption;

    ASSERT_APPROX_EQUAL(DigitalPutOption.getStrike(), 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(DigitalPutOption.getMaturity(), 0.0, 1e-12);
}


static void testDigitalPutOptionConstructor(){

    DigitalPutOption DigitalPutOption(105.0, 2.0);

    ASSERT_APPROX_EQUAL(DigitalPutOption.getStrike(), 105.0, 1e-12);
    ASSERT_APPROX_EQUAL(DigitalPutOption.getMaturity(), 2.0, 1e-12);
}


static void testDigitalPutOptionSettersGetters(){

    DigitalPutOption DigitalPutOption;

    DigitalPutOption.setStrike(110.0);
    DigitalPutOption.setMaturity(3.0);

    ASSERT_APPROX_EQUAL(DigitalPutOption.getStrike(), 110.0, 1e-12);
    ASSERT_APPROX_EQUAL(DigitalPutOption.getMaturity(), 3.0, 1e-12);
}


static void testDigitalPutOptionPayoff(){

    DigitalPutOption DigitalPutOption(105.0, 2.0);

    // OTM
    double stockAtMaturity = 110;
    double payoff = DigitalPutOption.payoff(stockAtMaturity);

    ASSERT_APPROX_EQUAL(payoff, 0.0, 1e-12);


    // ATM
    double stockAtMaturity2 = 105.0;
    double payoff2 = DigitalPutOption.payoff(stockAtMaturity2);

    ASSERT_APPROX_EQUAL(payoff2, 0.0, 1e-12);


    // ITM
    double stockAtMaturity3 = 100.0;
    double payoff3 = DigitalPutOption.payoff(stockAtMaturity3);

    ASSERT_APPROX_EQUAL(payoff3, 1.0, 1e-12);
}


static void testDigitalPutOptionPrice(){

    DigitalPutOption DigitalPutOption(105.0, 2.0);

    BlackScholesModel bsm;

    bsm.date = 1.0;
    bsm.volatility = 0.1;
    bsm.riskFreeRate = 0.05;
    bsm.stockPrice = 100.0;

    double price = DigitalPutOption.price(bsm);

    ASSERT_APPROX_EQUAL(price, 0.489994, 1e-1);
}


// Test Digital Call Option class
void testDigitalPutOption(){
    
    std::cout << "\n.... Start of testDigitalPutOption ....\n" << std::endl;

    TEST(testDigitalPutOptionDefaultConstructor);

    TEST(testDigitalPutOptionConstructor);

    TEST(testDigitalPutOptionSettersGetters);

    TEST(testDigitalPutOptionPayoff);

    setDebugEnabled(true);

    TEST(testDigitalPutOptionPrice);

    setDebugEnabled(false);
    
    std::cout << "\n ......................................... \n" << std::endl;
}
