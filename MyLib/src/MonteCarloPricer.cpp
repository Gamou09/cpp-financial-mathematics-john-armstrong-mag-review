//
//  MonteCarloPricer.cpp
//  MyLib
//
//  Created by Martial Aguessi on 30/06/2025.
//

#include "MonteCarloPricer.hpp"
#include "BlackScholesModel.hpp"
#include "ContinuousTimeOptionBase.h"
#include <cmath>
#include <vector>

// Construct the pricer with the default number of Monte Carlo scenarios.
// Default is 1,000 scenarios and 252 steps
MonteCarloPricer::MonteCarloPricer() : nScenarios(10000), nSteps(252) {}

MonteCarloPricer::MonteCarloPricer(int nScenarios_, int nSteps_): nScenarios(nScenarios_), nSteps(nSteps_) {}

/*
 Price any option derived from ContinuousTimeOptionBase.

 Refactoring note:
 Previous overloads for CallOption, PutOption, PathIndependentOption,
 and PathDependentOption have been removed.

 All these option types ultimately inherit from ContinuousTimeOptionBase,
 so a single polymorphic price() function is sufficient.

 The Monte Carlo pricer is therefore responsible only for:
 1. generating simulated stock-price paths,
 2. passing each path to the option,
 3. averaging the resulting payoffs,
 4. discounting the expected payoff back to the model date.

 The option itself decides how the simulated path is used.

 For a path-dependent option, payoff() may inspect the entire path.

 For a path-independent option, ContinuousTimeOptionBase is used through
 the PathIndependentOption adapter, which extracts the final stock price
 and forwards it to payoff(double).

 As a result, MonteCarloPricer does not need to know whether the concrete
 option is path-dependent or path-independent.
 
 */

double MonteCarloPricer::price(const ContinuousTimeOptionBase& option,
                               const BlackScholesModel& bsm) {
    double total = 0.0;

    for (int i = 0; i < nScenarios; i++) {

        // Always generate and pass a complete simulated price path.
        //
        // Path-dependent options use the path directly.
        //
        // Path-independent options ignore the intermediate values through
        // their adapter implementation and use only the final stock price.
        //
        // This keeps the pricing algorithm generic and avoids special-case
        // logic based on the concrete option type.
        
        std::vector<double> pricePath =
                bsm.generateRiskNeutralPricePath(
                option.getMaturity(),
                100);  // number of simulation time steps

        double payoff = option.payoff(pricePath);

        total += payoff;
    }

    // Estimate the risk-neutral expected payoff.
    double mean = total / nScenarios;

    // Discount the expected payoff from maturity back to the model date.
    double r = bsm.riskFreeRate;
    double T = option.getMaturity() - bsm.date;

    return std::exp(-r * T) * mean;
}

