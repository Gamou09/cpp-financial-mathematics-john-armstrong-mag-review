//
//  Integral.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 12/09/2026.
//

#ifndef Integral_hpp
#define Integral_hpp

class RealFunction ;
class PathIndependentOption ;

double integral (const RealFunction& f,
                 double a,
                 double b,
                 int nPoints) ;

double integralPayOff(double a,
                      double b,
                      const PathIndependentOption& option) ;

#endif /* Integral_hpp */
