//
//  testHedgingSimulator.cpp
//  MyTests
//
//  Created by Martial Aguessi on 02/10/2026.
//

#include <iostream>  // Standard library output: std::cout.
#include <vector>    // STL container: std::vector.

#include "testing.hpp"
#include "HedgingSimulator.hpp"
#include "matlib.h"  // Custom rng() declaration, if defined here.

#include "histogramChart.hpp"


using namespace std ;

static void testHedgingMeanPayoff(){
    
    rng("default") ;
    
    HedgingSimulator simulator ;
    simulator.setNSteps(100) ;
    
    vector<double> result = simulator.runSimulations(1) ;
    
    ASSERT_APPROX_EQUAL(result[0], 0.0, 1e-2) ;
    
}

static void testPlotDeltaHedgingHistogram(){
    
    rng("default") ;
    HedgingSimulator simulator ;
    
    simulator.setNSteps(252) ;
    vector<double> result = simulator.runSimulations(10000) ;
    
    hist("output/html/deltaHedgingPNL.html", result, 20);
}

void testHedingSimulator() {
    
    std::cout << "\n.... Start of testHedingSimulator ....\n" << std::endl;
    
    testPlotDeltaHedgingHistogram() ;
    
    TEST( testHedgingMeanPayoff ) ;
    
    std::cout << "\n ......................................... \n" << std::endl;
}
