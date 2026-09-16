//
//  MonteCarloPricer.hpp
//  MyLib
//
//  Created by Martial Aguessi on 30/06/2025.
//

// #ifndef MonteCarloPricer_hpp
// #define MonteCarloPricer_hpp

#pragma once

// Forward declarations are sufficient because the objects are passed
// by reference. Full class definitions are included in the .cpp file.
class ContinuousTimeOptionBase;
class BlackScholesModel;

/**
 * @brief Monte Carlo pricer for continuous-time options.
 *
 * The pricer is separated from both the option contract and the market model.
 * It uses BlackScholesModel to generate simulated price paths and delegates
 * payoff evaluation to the option through the ContinuousTimeOptionBase interface.
 */
class MonteCarloPricer {

public:

    /**
     * @brief Construct a Monte Carlo pricer with the default number of scenarios and steps
     */
    MonteCarloPricer();
    
    /**
     * @brief Construct a Monte Carlo pricer with the user input on  number of scenarios.
     */
    MonteCarloPricer(int nScenarios_, int nSteps_);

    /**
     * @brief Number of Monte Carlo scenarios used in the simulation.
     */
    int nScenarios;
    
    /**
     * @brief Number of Monte Carlo steps used in the simulation.
     */
    int nSteps;

    /**
     * @brief Price any option derived from ContinuousTimeOptionBase.
     *
     * Refactored to use a single polymorphic pricing interface.
     *
     * Previous overloads for CallOption, PutOption, PathIndependentOption,
     * and PathDependentOption were removed because all these option types
     * ultimately inherit from ContinuousTimeOptionBase.
     *
     * This avoids duplicated pricing logic and allows new option types
     * to work with MonteCarloPricer without adding new price() overloads.
     */
    double price(const ContinuousTimeOptionBase& option,
                 const BlackScholesModel& bsm);
};
