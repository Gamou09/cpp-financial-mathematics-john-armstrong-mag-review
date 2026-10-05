//
//  HedgingSimulator.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 01/10/2026.
//

#ifndef HedgingSimulator_hpp
#define HedgingSimulator_hpp

#include <memory>
#include <vector>

class CallOption ;

class BlackScholesModel ;


class HedgingSimulator {

private:
    
    /* Note: it's more versatile to store objects via pointer
             This should be the default desuign choice when building classes that reference data of other classes
       Reason #1: Other alternative will be to use member variable which does not allow for subclass
       
       Improvement: Use member variable of a more general type so that we can simulate heding for other types of options
     
     */
    
    /* The Option that has been written */
    std::shared_ptr<CallOption> toHedge ;
    
    // By seperating the model, we introduce flexibility to test different assumption
    /* The model used to simulate stock prices */
    std::shared_ptr<BlackScholesModel> simulationModel ;
    
    /* The model used to compute prices and deltas */
    std::shared_ptr<BlackScholesModel> pricingModel ;
    
    /* The number of steps to use */
    int nSteps ;
    
    // Private helper functions to run the simulation
    
    /* run a simulation and compute the profit and loss */
    double runSimulation() const;
    
    /*
     Function overloading to keep the current architecture
     Allow user to specific the number of hedging steps
     usefull for Ex 14.4.1
     */
    double runSimulation(int steps) const;
    
    /* How much should we charge the constomer */
    double chooseCharge( double stockPrice) const ;
    
    /* How much we stock should we hold = delta */
    double selectStockQuantity( double date, double stockPrice) const ;
    
public:
    
    // Defining the setter functions
    void setToHedge (std::shared_ptr<CallOption> toHedge) {
        
        this->toHedge = toHedge ;
    }
    
    void setSimulationModel (std::shared_ptr<BlackScholesModel> model) {
        
        this->simulationModel = model ;
    }
    
    void setPricingModel (std::shared_ptr<BlackScholesModel> model) {
        
        this->pricingModel = model ;
    }
    
    void setNSteps (int nSteps) {
        
        this->nSteps = nSteps ;
    }
    
    /* Default constructor */
    HedgingSimulator() ;
    
    /* Runs a number of simulations and returns a vector of the profit and loss */
    std::vector<double> runSimulations( int nSimulations) const ;
    
    /* Mean Absolute PnL function */
    double meanAbsolutePnL(int steps, int nScenarios) const;
    
} ;

#endif /* HedgingSimulator_hpp */
