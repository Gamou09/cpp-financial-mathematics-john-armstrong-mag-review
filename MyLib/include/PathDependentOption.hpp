//
//  PathDependentOption.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 15/09/2026.
//

#ifndef PathDependentOption_h
#define PathDependentOption_h

#include <vector>
#include "ContinuousTimeOptionBase.h"

class BlackScholesModel;

class PathDependentOption : public ContinuousTimeOptionBase {

public:

    // Virtual destructor for safe polymorphic destruction.
    virtual ~PathDependentOption() = default;

    // Payoff depends on the full simulated stock-price path.
    // Each path-dependent option must provide its own implementation.
    //
    // Unlike PathIndependentOption, no payoff adapter is needed here.
    // Path-dependent options already use the full stock-price path,
    // which directly matches the payoff interface defined in
    // ContinuousTimeOptionBase.

    // A path-dependent option depends on the full stock-price path,
    // not only on the final stock price.
    bool isPathDependent() const override {
        return true;
    }

};
#endif /* PathDependentOption_h */

