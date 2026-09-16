//
//  PutOption.hpp
//  MyLib
//
//  Created by Martial Aguessi on 26/06/2025.
//

#ifndef PutOption_hpp
#define PutOption_hpp

#include "ContinuousTimeOptionBase.h"

class BlackScholesModel ; 

// Significant benefit of separating the Model from the Option:
// the option represents the contract and does not change when the market changes,
// even though its price may vary.
//
// Sep 15: changed superclass from PathIndependentOption
// to ContinuousTimeOptionBase.
//
// Because PutOption now inherits from ContinuousTimeOptionBase,
// we no longer need to redeclare the common option data members
// such as strike and maturity.
//
// We also inherit the common getter/setter functions:
//      getStrike(), getMaturity(), setStrike(), setMaturity()
//
// PutOption therefore only needs to define behaviour that is specific
// to a put option.

class PutOption: public ContinuousTimeOptionBase {


public:
    
    // declarations of constructors
    // No more constructor by PutOption since the member variables are from Parent class
    
    // Put-specific payoff implementation.
    // This overrides the pure virtual function declared in
    // the ContinuousTimeOption interface.
    double payoff(const std::vector<double>& stockPrices) const override;

    // A standard European put only depends on the stock price at maturity.
    // since its payoff depends only on the stock price at maturity.
    bool isPathDependent() const override { return false; }

    // Price the option using the supplied Black-Scholes model.
    // using they keyword override for compiler
    // to check that we have appropriately override the parent class virtual price function
    // No change in the behaviour of the program but help compiler check for you and very helpful for debuggin
    double price(const BlackScholesModel& bsm) const override;
} ;

#endif /* PutOption_hpp */
