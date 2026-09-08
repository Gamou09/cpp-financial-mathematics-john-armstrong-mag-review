//
//  MonteCarloPricer.hpp
//  MyLib
//
//  Created by Martial Aguessi on 30/06/2025.
//

// #ifndef MonteCarloPricer_hpp
// #define MonteCarloPricer_hpp

#pragma once

// we only need forward declaratiion here since the object are passed by reference "...&"
// #include "PathIndependentOption.hpp"
// #include "BlackScholesModel.hpp"
// #include "CallOption.hpp"
// #include "PutOption.hpp"
class CallOption ;
class PutOption ;
class PathIndependentOption ;
class BlackScholesModel ;

class MonteCarloPricer {
    
public:
    /* Constructor */
    MonteCarloPricer() ;
    
    /* Number of scenarios */
    int nScenarios;
    
    /* Price a call option */
    double price (const CallOption& callOption,
                  const BlackScholesModel& bsm) ;
        
    /* Price a put option */
    double price (const PutOption& putOption,
                  const BlackScholesModel& bsm) ;
    
    /* Price a path independent option like Europreqn Put and Call  utilizing interface notion  */
    /* help avoid copy and easility extendable class by inherittance */
    /* Price a PathIndependentOption */
    double price (const PathIndependentOption& option,
                                   const BlackScholesModel& bsm) ;
    
};

// #endif /* MonteCarloPricer_hpp */
