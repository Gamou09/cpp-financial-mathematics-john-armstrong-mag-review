//
//  testBlackScholesModel.cpp
//  MyTests
//
//  Created by Martial Aguessi on 08/09/2026.
//

#include "testing.hpp"
#include "BlackScholesModel.hpp"

using namespace std ;

// test

static void testBlackScholesModelGeneratePricePath(){
    
    // bsm model inputs
    BlackScholesModel bsm ;
    bsm.riskFreeRate = 0.05 ;
    bsm.volatility = 0.1 ;
    bsm.stockPrice = 100.0 ;
    bsm.date = 2.0 ;
    
    // test input
    int nSteps = 1000 ;
    double maturity = 4.0 ;
    
    // generate path function test
    vector<double> path = bsm.generatePricePath(maturity, nSteps) ;
    double dt = (maturity - bsm.date)/nSteps ;
    
    vector<double> times = linespace(dt, maturity, nSteps);
    
    // Visual graph
    LineChart lineChart ;
    lineChart.setTitle("Stock price path") ;
    lineChart.setSeries(times, path) ;
    lineChart.writeAsHTML("examplePricePath.html");
    
}

static void testBlackScholesModelRiskNeutralPricePath(){
    rng("default") ;
    
    // bsm model inputs
    BlackScholesModel bsm ;
    bsm.riskFreeRate = 0.05 ;
    bsm.volatility = 0.1 ;
    bsm.stockPrice = 100.0 ;
    bsm.date = 2.0 ;
    
    // test input
    int nPaths = 10000 ;
    int nSteps = 5 ;
    double maturity = 4.0 ;
    
    // generate the final price
    vector<double> finalPrices (nPaths, 0.0) ;
    for (int i = 0; i < nPaths; i++) {
        vector<double> path = bsm.generateRiskNeutralPricePath(maturity, nSteps) ;
        finalPrices[i] = path.back() ;
    }
    
    ASSERT_APPROX_EQUAL(mean_function_v2(finalPrices), exp(bsm.riskFreeRate*(maturity - bsm.date))*bsm.stockPrice, 0.5) ;
    
}

static void testBlackScholesSimulateStCSV(){
    // Seeting the simulation seed for reproductibility
    rng("default") ;
    
    // Parameters
    BlackScholesModel bsm ;
    bsm.riskFreeRate = 0.05 ;
    bsm.volatility = 0.2 ;
    bsm.stockPrice = 100.0 ;
    bsm.date = 1.0 ;
    int N = 10000 ; // Number of simulation
    
    vector<double> prices ;
    
    // Simulate stock prices
    for (int i = 0; i < N; i++) {
        double St = bsm.simulateSt() ;
        prices.push_back(St) ;
    }
    
    // Save to csv
    ofstream out("simulated_prices.csv") ;
    for (double price : prices) {
        out << price << "\n" ;
    }
    
    out.close() ;
    cout << "Saved " << N << " simulated prices to simulated_prices.csv\n" ;
}

void testBlackScholesModel(){
    
    std::cout << "\n.... Start of testBlackScholesModel ....\n" << std::endl;
    
    TEST( testBlackScholesModelGeneratePricePath) ;
    TEST( testBlackScholesModelRiskNeutralPricePath ) ;
    TEST( testBlackScholesSimulateStCSV ) ;
    
    std::cout << "\n.........................................\n" << std::endl;
    
}
