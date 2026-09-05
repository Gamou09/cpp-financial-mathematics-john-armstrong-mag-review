//
//  derivatives.hpp
//  MyLib
//
//  Created by Martial Aguessi on 26/05/2025.
//

#ifndef derivatives_hpp
#define derivatives_hpp

#include "stdafx.h"

double black_scholes_put(double S, double K, double r, double sigma, double T) ;

double black_scholes_call(double S, double K, double r, double sigma, double T);

void testDerivatives() ;

#endif /* derivatives_hpp */
