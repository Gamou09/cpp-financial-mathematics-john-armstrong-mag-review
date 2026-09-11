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
    
private:
    
    // member variables
    double strike ;
    double maturity ;
    
public:
    
    // default constructor
    DigitalPutOption();

    // constructor with parameters
    DigitalPutOption(double strike, double maturity);
    
    // getter functions since the member variables are private
    double getStrike() const;
    double getMaturity() const override ; // always a mandatory function from the intercface
    
    // member variables setter functions
    void setStrike( double strike);
    void setMaturity( double maturity) ; //
    
    // Analytical solution
    double price ( const BlackScholesModel& bsm) const ;
    
    // Inherited functinos from interface
    double payoff(double finalStockPrice) const override ;
};

#endif /* DigitalPutOption_hpp */
