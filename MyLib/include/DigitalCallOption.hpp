//
//  DigitalCallOption.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 09/09/2026.
//

#ifndef DigitalCallOption_hpp
#define DigitalCallOption_hpp

#include "PathIndependentOption.hpp"

class BlackScholesModel ;

class DigitalCallOption : public PathIndependentOption {


public:
    
    // Data members and getters/setters are inherited.
    //
    // Constructors are different:
    // base-class constructors are not automatically inherited by the derived class.
    //
    // Therefore DigitalCallOption explicitly provides its constructor and
    // delegates initialization of strike and maturity to PathIndependentOption.
    DigitalCallOption(): PathIndependentOption() {} ;
    
    DigitalCallOption(double strike_, double maturity_)
    : PathIndependentOption(strike_, maturity_) {} ; 

    // functions overridden from the interface
    double payoff(double stockAtMaturity) const override;
    
    double price(const BlackScholesModel& bsm) const override;
};

#endif /* DigitalCallOption_hpp */
