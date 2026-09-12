//
//  testIntegral.cpp
//  MyTests
//
//  Created by Martial Aguessi on 12/09/2026.
//

#include "RealFunction.h"
#include "SinFunction.hpp"
#include "Integral.hpp"
#include "testing.hpp"
#include "PathIndependentOption.hpp"

#include "CallOption.hpp"
#include "PutOption.hpp"

#include <cmath>

#include <stdio.h>

static void testIntegralSin(){
    
    SinFunction integrand ;
    double actual = integral(integrand, 1, 3, 1000) ;
    double expected = -cos(3.0) + cos(1.0) ;
    
    ASSERT_APPROX_EQUAL(actual, expected, 1e-5) ;
    
}

// Using Local class Sin to avoid crreating a new CPP file everytime we want to test a function
static void testIntegralVersion2(){
   
    // Local class which will only exists inside the scope of the testIntegralVersion2
    class Sin: public RealFunction {
        
    public:
        // since local class, the declaration already include the method definition
        double evaluate (double x) const override {
            return sin(x) ;
        }
    } ;
    
    // Instantiating the local class
    Sin integrand ;
    double actual = integral(integrand, 1, 3, 1000) ;
    double expected = -cos(3.0) + cos(1.0) ;
    
    ASSERT_APPROX_EQUAL(actual, expected, 1e-5) ;
}


// ---------------------------------------------------------
// Test integralPayOff with a CallOption
// ---------------------------------------------------------
static void testIntegralPayOffCallOption()
{
    CallOption call;
    call.strike = 100.0;

    double result = integralPayOff(
        100.0,
        110.0,
        call
    );

    // Integral from 100 to 110 of (x - 100)
    // = 1/2 * (110 - 100)^2
    // = 50
    ASSERT_APPROX_EQUAL(result, 50.0, 1e-2);
}


// ---------------------------------------------------------
// Test integralPayOff with a PutOption
// ---------------------------------------------------------
static void testIntegralPayOffPutOption()
{
    PutOption put;
    put.setStrike(100.0) ;

    double result = integralPayOff(
        90.0,
        100.0,
        put
    );

    // Integral from 90 to 100 of (100 - x)
    // = 1/2 * (100 - 90)^2
    // = 50
    ASSERT_APPROX_EQUAL(result, 50.0, 1e-2);
}


// ---------------------------------------------------------
// Test zero payoff region
// ---------------------------------------------------------
static void testIntegralPayOffZeroPayoff()
{
    CallOption call;
    call.strike = 100.0;

    double result = integralPayOff(
        80.0,
        90.0,
        call
    );

    // Call is OTM over the entire interval.
    ASSERT_APPROX_EQUAL(result, 0.0, 1e-2);
}

void testIntegral() {
    
    std::cout << "\n.... Start of testIntegral ....\n" << std::endl;
    
    TEST( testIntegralSin ) ;

    setDebugEnabled(true) ;
    TEST( testIntegralVersion2 ) ;
    setDebugEnabled(false) ;
    
    TEST( testIntegralPayOffCallOption ) ;
    
    TEST( testIntegralPayOffPutOption ) ;
    
    TEST( testIntegralPayOffZeroPayoff ) ;
    
    
    std::cout << "\n ......................................... \n" << std::endl;
}
