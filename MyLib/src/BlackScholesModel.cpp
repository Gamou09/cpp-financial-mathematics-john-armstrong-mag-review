//
//  BlackScholesModel.cpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#include "stdafx.h"

using namespace std ;

// default constructor
BlackScholesModel::BlackScholesModel(): stockPrice(0.0) {}

// default constructor
BlackScholesModel::BlackScholesModel(double stockPrice): stockPrice(0.0) {}

// definition of the generatePricePath member function and Test
vector<double> BlackScholesModel::generatePricePath(double toDate, int nSteps, double drift) const {
    
    vector<double> path(nSteps, 0.0) ;
    vector<double> epsilon = randn( nSteps ) ;
    double dt = (toDate - date)/nSteps ;
    
    double a = (drift - volatility*volatility*0.5)*dt ;
    double b = volatility*sqrt(dt) ;
    
    double currentLogS = log(stockPrice) ;
    
    for (int i = 0; i < nSteps; i++) {
        double dLogS = a + b*epsilon[i] ;
        double logS = currentLogS + dLogS ;
        path[i] = exp(logS) ;
        currentLogS = logS ;
    }
    
    return path ;
}

vector<double> BlackScholesModel::generatePricePath(double toDate, int nSteps) const {
    
    return generatePricePath(toDate, nSteps, drift);
    
}

vector<double> BlackScholesModel::generateRiskNeutralPricePath(double toDate, int nSteps) const {
    
    return generatePricePath(toDate, nSteps, riskFreeRate);
    
}

void testBlackScholesModelgeneratePricePath(){
    
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

void testBlackScholesModelRiskNeutralPricePath(){
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


// Defintion of the funciron simulate S_t

double BlackScholesModel::simulateSt(){
    
    mt19937 rng(random_device{}()) ;
    normal_distribution<> normal(0.0, 1.0) ;
    
    double Z = normal(rng) ;
    return stockPrice*exp(riskFreeRate - 0.5*volatility*volatility)*date + volatility*sqrt(date)*Z;
}

void testBlackScholesSimulateStCSV(){
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
    cout << "Savved " << N << " simulated prices to simulated_prices.csv\n" ;
}

void testBlackScholesModel(){
    
    TEST( testBlackScholesModelgeneratePricePath) ;
    TEST( testBlackScholesModelRiskNeutralPricePath ) ;
    TEST( testBlackScholesSimulateStCSV ) ; 
    
}
