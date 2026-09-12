//
//  Integral.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 12/09/2026.
//

#include "Integral.hpp"
#include "RealFunction.h"
#include "PathIndependentOption.hpp"

double integral (const RealFunction& f,
                 double a,
                 double b,
                 int nPoints){
    
    // intermediate variable initialization
    double h = (b - a) / nPoints ;
    double x = a + 0.5*h ;
    
    // computatioin using rectangle method
    double total =  0.0 ;
    for (int i = 0; i < nPoints; ++i) {
        double y = f.evaluate(x) ;
        total += y ;
        x += h ;
    }
    
    return h*total ;
    
}

double integralPayOff(double a,
                      double b,
                      const PathIndependentOption& option){
    
    class PayoffFunction : public RealFunction {
        
    public:
        /* Member variable */
        const PathIndependentOption& option ;
        
        /* Constructor */
        PayoffFunction(const PathIndependentOption& option): option(option) {};
        
        /* Overriding function */
        double evaluate( double x) const override  {return option.payoff(x) ; }
    } ;
    
    PayoffFunction integrand (option) ;
    return integral(integrand, a, b, 1000) ;
}
