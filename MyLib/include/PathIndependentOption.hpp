//
//  PathIndependentOption.hpp
//  MyLib
//
//  Created by Martial Aguessi on 13/08/2026.
//

// ifndef, define and endif are old C++
// #ifndef PathIndependentOption_hpp
// #define PathIndependentOption_hpp

// Modern and simpler C++ need to prevent circular inclusion
#pragma once

#include "ContinuousTimeOptionBase.h"
#include <vector>

/**
 * @brief Abstract base class for path-independent options.
 *
 * A path-independent option depends only on the underlying asset price
 * at maturity, rather than on the full price path.
 *
 * This class adapts the path-based payoff interface inherited from
 * ContinuousTimeOptionBase to a simpler payoff function that takes only
 * the final stock price.
 *
 * Concrete subclasses, such as CallOption and PutOption, implement the
 * scalar payoff(double) function.
 */


class PathIndependentOption : public ContinuousTimeOptionBase {

public:
    
    PathIndependentOption(): ContinuousTimeOptionBase() {} ;
    
    PathIndependentOption(double strike_, double maturity_)
        : ContinuousTimeOptionBase(strike_, maturity_) {}

    // Virtual destructor for safe polymorphic destruction.
    virtual ~PathIndependentOption() = default;

    // Return the payoff based on the stock price at maturity.
    // Each path-independent option must provide its own implementation.
    virtual double payoff(double finalStockPrice) const = 0;

    // Adapt the full price-path payoff interface to the path-independent case.
    // Only the final stock price is needed.
    double payoff(const std::vector<double>& stockPrices) const override {
        return payoff(stockPrices.back());
    }

    // A path-independent option depends only on the final stock price.
    bool isPathDependent() const override {
        return false;
    }
};

// see line 8-12 comments
// #endif /* PathIndependentOption_hpp */
