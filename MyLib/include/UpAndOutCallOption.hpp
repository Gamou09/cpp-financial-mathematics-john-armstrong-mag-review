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
    double strike ;
    double barrier ;
    double maturity ;
    
public:
    UpAndOutCallOption(double strike, double barrier, double maturity);

    double payoff(const std::vector<double>& path) const override;
    
    double getMaturity() const override;

    double price(const BlackScholesModel& model) const;
};

#endif /* UpAndOutOption_hpp */
 
