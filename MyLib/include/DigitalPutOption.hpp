//
//  DigitalPutOption.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 11/09/2026.
//

#ifndef DigitalPutOption_hpp
#define DigitalPutOption_hpp

#include "PathIndependentOption.hpp"

class BlackScholesModel ;

class DigitalPutOption: public PathIndependentOption {
    
public:
    
    // default constructor
    DigitalPutOption(): PathIndependentOption() {};

    // constructor with parameters
    DigitalPutOption(double strike_, double maturity_)
        : PathIndependentOption(strike_, maturity_) {} ;
    
    // Analytical solution
    double price ( const BlackScholesModel& bsm) const override;
    
    // Inherited functinos from interface
    double payoff(double finalStockPrice) const override ;
};

#endif /* DigitalPutOption_hpp */
