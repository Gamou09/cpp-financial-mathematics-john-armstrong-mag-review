//
//  MonteCarloPricer.hpp
//  MyLib
//
//  Created by Martial Aguessi on 30/06/2025.
//

// #ifndef MonteCarloPricer_hpp
// #define MonteCarloPricer_hpp

#pragma once

#include "stdafx.h"

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

void testMonteCarloPricer() ;

// #endif /* MonteCarloPricer_hpp */
