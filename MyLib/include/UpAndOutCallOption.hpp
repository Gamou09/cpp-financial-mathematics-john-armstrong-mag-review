//
//  UpAndOutOption.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 15/09/2026.
//

#ifndef UpAndOutOption_hpp
#define UpAndOutOption_hpp

#include <stdio.h>
#include <vector>

#include "PathDependentOption.hpp"

class BlackScholesModel ;

class UpAndOutCallOption: public PathDependentOption  {
    
    // Up-and-out call:
    // - behaves like a normal call while the stock remains below the barrier;
    // - if the stock ever reaches/exceeds the barrier, the option is knocked out;
    // - once knocked out, its payoff is 0 even if the stock later falls below
    //   the barrier and finishes above the strike.

private:
    
    // Specifc new member variable
    double barrier ;
    
public:
    
    UpAndOutCallOption(): PathDependentOption() {} ; 
    
    UpAndOutCallOption(double strike_, double barrier_, double maturity_) ;
    
    double payoff(const std::vector<double>& stockPrices) const override ; 
    
};

#endif /* UpAndOutOption_hpp */
 
