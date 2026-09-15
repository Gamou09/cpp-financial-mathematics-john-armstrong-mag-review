//
//  PathDependentOption.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 15/09/2026.
//

#ifndef PathDependentOption_h
#define PathDependentOption_h

#include <vector>

class BlackScholesModel;

class PathDependentOption {

public:
    
    // get the maturity
    virtual double getMaturity() const = 0;

    // Payoff depends on the whole simulated stock-price path
    virtual double payoff(const std::vector<double>& path) const = 0;

    virtual ~PathDependentOption() = default;
};

#endif /* PathDependentOption_h */
