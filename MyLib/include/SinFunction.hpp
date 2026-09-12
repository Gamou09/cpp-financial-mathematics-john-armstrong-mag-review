//
//  SinFunction.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 12/09/2026.
//

#ifndef SinFunction_hpp
#define SinFunction_hpp

#include "RealFunction.h"

class SinFunction: public RealFunction {
    
public:
    double evaluate (double x) const override;
};

#endif /* SinFunction_hpp */
