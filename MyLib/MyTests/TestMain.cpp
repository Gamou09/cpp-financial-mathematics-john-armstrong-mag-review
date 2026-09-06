//
//  Testmain.cpp
//  MyTests
//
//  Created by Martial Aguessi on 06/09/2026.
//

#include <iostream>
#include "stdafx.h"
#include "TestFunctions.h"

using namespace std;

int main()
{
    std::cout << "Hello, World!\n";
    std::cout << "Welcome to my Test - where I prove what I built works\n\n";
    
    std::cout << "Running the tests with the new framework..." << std::endl;
    
    testCallOption(); 
    
    std::cout << "\n\n" << std::endl;
    
    std::cout << "Running the tests with the old framework..." << std::endl;
    
    // Test matLib
    testMatlib();
    
    // Test geometry
    testGeometry();
    
    // test for derivatives
    testDerivatives() ;
    
    // test vector
    testVector() ;
    
    // test Pass by Ref or value, with or without const
    testPassRef() ;
    
    // Test ofstream module
    useOfstreamToWriteFile() ;
    
    // test the Write haiku function
    testWriteHaiku() ;
    
    // testing basic String fucntion
    testStringBasic() ;
    
    // test chart
    testCharts() ;
    
    // Test exercice from chapter 7
    testChap7_solutions() ;
    
    // Test use of class Cartesial
    useCartesianClass() ;
    
    // Test chap 8
    testCallOption() ;
    
    // test Pie chart with class
    testPieChart() ;
    
    // Test chap 8.6.1 - PutOption class
    testPutOption() ;
    
    // Test chap 8.6.2 - LineChart class
    testLineChart() ;
    
    // Testing a class with default constructor who know work
    cout  << "--- Testing Class with or without a (default) constructor ---\n" ;
    //    // This code will generate a warning because variable not initialize
          // leading to fail build up in our case since that's our setting is
    //    double d ;
    //    cout << "What is the value of d\n?" ;
    //    cout << d ;
    //
    //    CartesianPoint cartP ;
    //    cout << "What is the value of x?\n" ;
    //    cout << cartP.x ;
        
    //    Clean solution would be add a constructor in our self defined class (since we can't fix all c++)
    //    return 0 ;
    
    Point p ;
    cout << "What is the value of x?\n" ;
    cout << "x = " << p.x << "\n\n";
    
    // Testing PolynomialClass
    testPolynomialClass() ;
    
    // Test BlackScholesModel class
    testBlackScholesModel() ;
    
    // Test of the Monte Carlo Pricer
    testMonteCarloPricer() ;
    
    // Manual draft
    vector<double> vec ({0.0}) ;
    cout << vec.size() << "\n" ;
    
    return 0;
}
