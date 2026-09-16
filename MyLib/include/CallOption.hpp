//
//  CallOption.hpp//
//  Created by Martial Aguessi on 25/06/2025.
//

#ifndef CallOption_hpp
#define CallOption_hpp

/**For inheritance, this is important: you cannot merely forward-declare PathIndependentOption.
 The compiler needs the complete definition of the base class before defining CallOption.
 Thus we need to include it specifically or with stdafx.h**/
#include "PathIndependentOption.hpp"

class BlackScholesModel ;

// Separating the model from the option is an important design choice:
// the option represents the contract and does not change when market
// conditions change, even though its price may change.

class CallOption : public PathIndependentOption {

public:

    // Constructors and common option data such as strike and maturity
    // are inherited from ContinuousTimeOptionBase.
    CallOption(): PathIndependentOption() {} ;
    
    CallOption(double strike_, double maturity_)
    : PathIndependentOption(strike_, maturity_) {} ;

    // Override the pricing function because a European call option
    // can be priced analytically using the Black-Scholes formula
    // rather than using the default MonteCarlo Implementation by ContinuousTimeOptionBase
    double price(const BlackScholesModel& bsm) const override;

    // Call-specific payoff at maturity.
    double payoff(double stockAtMaturity) const override;
};

#endif /* CallOption_hpp */
