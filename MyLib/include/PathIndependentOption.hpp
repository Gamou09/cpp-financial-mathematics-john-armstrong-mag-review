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

// we don't need this line as the PathIndependentOption should be self contain with only built in C++ functions
// #include "stdafx.h"

class PathIndependentOption {
    
public:
    /* A virtual destructor */
    virtual ~PathIndependentOption() {}
    
    /* Return the payoff at maturtity */
    virtual double payoff(double finalStockPrice) const = 0 ;
    
    /* Return the maturity of the option */
    virtual double getMaturity() const = 0 ;
};

// see line 8-12 comments
// #endif /* PathIndependentOption_hpp */
