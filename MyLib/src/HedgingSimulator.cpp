//
//  HedgingSimulator.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 01/10/2026.
//

#include "HedgingSimulator.hpp"
#include "CallOption.hpp"
#include "BlackScholesModel.hpp"

using namespace std ;

double HedgingSimulator::runSimulation() const {
    
    double T = toHedge->getMaturity() ;
    double S0 = simulationModel->getStockPrice() ;
    
    vector<double> pricePath = simulationModel->generatePricePath(T, nSteps) ;
    
    double dt = T / nSteps ;
    double charge = chooseCharge(S0) ;
    double stockQuantity = selectStockQuantity(0, S0) ;
    double bankBalance = charge - stockQuantity*S0 ;
    
    for (int i = 0; i < nSteps - 1 ; i++) {
        double balanceWithInterest = bankBalance*exp(simulationModel->getRiskFreeRate()*dt) ;
        
        double S = pricePath[i] ;
        double date = dt*(i+1) ;
        double newStockQuantity = selectStockQuantity(date, S) ;
        double costs = (newStockQuantity - stockQuantity)*S ;
        
        bankBalance = balanceWithInterest - costs ;
        stockQuantity = newStockQuantity;
        
    }
    
    double balanceWithInterest = bankBalance*exp(simulationModel->getRiskFreeRate()*dt) ;
    
    double S = pricePath[nSteps - 1] ;
    double stockValue = stockQuantity*S ;
    double payout = toHedge->payoff(S) ;
    
    return balanceWithInterest + stockValue - payout ;
}

vector<double> HedgingSimulator::runSimulations( int nSimulations) const{
    
    vector<double> ret(nSimulations) ;
    for (int i = 0; i < nSimulations; i++) {
        ret[i] = runSimulation() ;
    }
    
    return  ret ;
    
}

// defining the default constructor with some reasonable values set for various parameters
HedgingSimulator::HedgingSimulator(){
    
    // choose default value model and options
    shared_ptr<BlackScholesModel> model (new BlackScholesModel()) ;
    
    model->setStockPrice(1) ;
    model->setDate(0) ;
    model->setRiskFreeRate(0.05) ;
    model->setVolatility(0.2) ;
    model->setDrift(0.10) ;
    
    shared_ptr<CallOption> option = make_shared<CallOption>() ;
    
    option->setStrike(model->getStockPrice()) ;
    option->setMaturity(1) ;
    
    setToHedge(option) ;
    setSimulationModel(model) ;
    setPricingModel(model) ;
    
    nSteps = 10 ;
}

double HedgingSimulator::selectStockQuantity(double date, double stockPrice) const {
    
    // Create a copy of the pricing model
    // Work as we do not wish to chnage the actual config of our hedging simulator
    // we only need to alter our pricing model so that its state reflects the state of the market currrent time step
    BlackScholesModel pm = *pricingModel ;
    pm.setStockPrice(stockPrice) ; // we can't use -> since no longer pointer (*ptr return the value of the adress )
    pm.setDate( date ) ;
    
    return toHedge->delta(pm) ; 
}

double HedgingSimulator::chooseCharge(double stockPrice) const {
    
    // create a cop of the pricing model
    // same reason as below
    BlackScholesModel pm = *pricingModel ;
    pm.setStockPrice(stockPrice) ;
    
    return toHedge->price(pm);
}
