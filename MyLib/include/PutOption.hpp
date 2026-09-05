//
//  PutOption.hpp
//  MyLib
//
//  Created by Martial Aguessi on 26/06/2025.
//

#ifndef PutOption_hpp
#define PutOption_hpp

#include "stdafx.h"

// Significant benefit opf seperating the the Model to the Options
// the option is the contract and doesn't change when market changed even though its price may vary
class PutOption: public PathIndependentOption {

// member variables in private to align with design principle of Encapsulation
private:
    double strike;
    double maturity ;

public:
    // declarations of constructors
    PutOption();
    PutOption(const double strike_, const double maturity_);
    
    // setter function member
    void setStrike ( double inputStrike) ;
    void setMaturity ( double inputMaturity) ;
    
    // method to be used
    double payoff ( double stockAtMaturity) const ;
    double price ( const BlackScholesModel& bsm) const ;
    
    // getter function member
    double getStrike () const ;
    double getMaturity () const ;
} ;

void testPutOption() ;

#endif /* PutOption_hpp */
