//
//  Polynomial.hpp
//  MyLib
//
//  Created by Martial Aguessi on 29/06/2025.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include "stdafx.h"

class Polynomial {
    
public:
    // getter function
    std::vector<double> getCoefficients() const ;
    
    // constructor
    Polynomial ();
    explicit Polynomial( const double& a0_) ;
    explicit Polynomial( const std::vector<double>& coefficients_) ;
    
    // Update the coefficient
    void setCoefficients(const std::vector<double>& newCoefficients) ;
    
    // method
    double evaluate (const double& x) const ;
    void add (const Polynomial& p); // this operation will nodify the poly's coefficient thus no const 
    
private:
    // member variable
    std::vector<double> coefficients ;
    
};

void testPolynomialClass() ;

#endif /* Polynomial_hpp */
