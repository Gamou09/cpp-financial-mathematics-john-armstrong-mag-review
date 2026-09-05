//
//  PathIndependentOption.hpp
//  MyLib
//
//  Created by Martial Aguessi on 13/08/2026.
//

#ifndef PathIndependentOption_hpp
#define PathIndependentOption_hpp

#include "stdafx.h"

class PathIndependentOption {
    
public:
    /* A virtual destructor */
    virtual ~PathIndependentOption() {}
    
    /* Return the payoff at maturtity */
    virtual double payoff(double finalStockPrice) const = 0 ;
    
    /* Return the maturity of the option */
    virtual double getMaturity() const = 0 ;
};

#endif /* PathIndependentOption_hpp */
