//
//  AsianCallOption.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 16/09/2026.
//

#ifndef AsianCallOption_hpp
#define AsianCallOption_hpp

#include <vector>

#include "PathDependentOption.hpp"

class AsianCallOption : public PathDependentOption {

public:

    // Default constructor.
    AsianCallOption()
        : PathDependentOption() {}

    // Construct an Asian call option with a given strike and maturity.
    // The common option parameters are forwarded to the direct parent class.
    AsianCallOption(double strike_, double maturity_)
        : PathDependentOption(strike_, maturity_) {}

    // Asian options are path-dependent because the payoff depends on
    // the average stock price over the complete simulated price path.
    double payoff(const std::vector<double>& stockPrices) const override;
};

#endif /* AsianCallOption_hpp */
