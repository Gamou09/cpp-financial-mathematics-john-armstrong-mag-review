//
//  BlackScholesModel.cpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#include "BlackScholesModel.hpp"

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

// Defintion of the funciron simulate S_t

double BlackScholesModel::simulateSt(){
    
    mt19937 rng(random_device{}()) ;
    normal_distribution<> normal(0.0, 1.0) ;
    
    double Z = normal(rng) ;
    return stockPrice*exp(riskFreeRate - 0.5*volatility*volatility)*date + volatility*sqrt(date)*Z;
}
