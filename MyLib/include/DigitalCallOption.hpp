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

private:

    // member variables
    double strike;
    double maturity;

public:

    // default constructor
    DigitalCallOption();

    // constructor with parameters
    DigitalCallOption(double strike, double maturity);

    // member variable setters
    void setStrike(double strike);
    void setMaturity(double maturity);

    // member variable getters
    double getStrike() const;
    double getMaturity() const override; // Also a function overriden from the interface
    
    // member function / method
    double price(const BlackScholesModel& bsm) const;

    // functions overridden from the interface
    double payoff(double stockAtMaturity) const override;
};

#endif /* DigitalCallOption_hpp */
