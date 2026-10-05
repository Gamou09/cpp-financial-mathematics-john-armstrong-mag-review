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

static void testDeltaHedgingExercise_14_4_1() {

    // Hedging simulator configured using its existing/default setup.
    HedgingSimulator simulator;

    // Number of Monte Carlo scenarios used for each hedging frequency.
    const int nScenarios = 100000;

    // Different numbers of rehedging dates.
    // Increasing the number of steps should reduce the discrete
    // delta-hedging error.
    const vector<int> numberOfRehedges = {
        4,
        8,
        16,
        32,
        64,
        128,
        256,
        512,
        1024
    };

    cout << "\n========================================\n";
    cout << "Exercise 14.4.1 - Delta Hedging Error\n";
    cout << "========================================\n";

    cout << "Scenarios per experiment: "
         << nScenarios << "\n\n";

    cout << "Rehedges\tMean Absolute P&L\n";
    cout << "----------------------------------------\n";

    // Run the Monte Carlo experiment for each hedging frequency.
    for (int nRehedges : numberOfRehedges) {

        // meanAbsolutePnL() internally calls:
        //
        //      runSimulation(nRehedges)
        //
        // nScenarios times and computes:
        //
        //      mean( |P&L| )
        //
        double meanAbsPnL =
            simulator.meanAbsolutePnL(
                nRehedges,
                nScenarios
            );

        cout << nRehedges
             << "\t\t"
             << meanAbsPnL
             << '\n';
    }

    cout << "========================================\n";
}

void testHedingSimulator() {
    
    std::cout << "\n.... Start of testHedingSimulator ....\n" << std::endl;
    
    // Uncomment if you want to regenerate the delta Hedging Histogram
    // testPlotDeltaHedgingHistogram() ;
    
    TEST( testHedgingMeanPayoff ) ;
    
    TEST( testDeltaHedgingExercise_14_4_1 ) ;
    
    std::cout << "\n ......................................... \n" << std::endl;
}
