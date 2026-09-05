//
//  Polynomial.cpp
//  MyLib
//
//  Created by Martial Aguessi on 29/06/2025.
//

#include "stdafx.h"

using namespace std ;

// definition and Test of getter function
vector<double> Polynomial::getCoefficients() const{
    return coefficients ;
}

// Definition and Test of default constructor
Polynomial::Polynomial() : coefficients(vector<double>({0.0})) {}

void testPolynomialConstructorDefault(){
    Polynomial polynomialExample ;
    ASSERT(polynomialExample.getCoefficients().size() == 1) ;
    ASSERT(polynomialExample.getCoefficients()[0] == 0.0) ;
}
// Definition and Test of Alterative constructor 2
Polynomial::Polynomial(const double& a0_) : coefficients(vector<double>({a0_})) {}

void testPolynomialConstructor1(){
    Polynomial polynomialExample(99.99) ;
    ASSERT(polynomialExample.getCoefficients().size() == 1) ;
    ASSERT(polynomialExample.getCoefficients()[0] == 99.99) ;
}

// Definition of Alterative constructor 1
Polynomial::Polynomial(const std::vector<double>& coefficients_) : coefficients(coefficients_) {}

void testPolynomialConstructor2(){
    
    vector<double> example_coeffs = vector<double>({10, 20, 30, 40}) ;
    Polynomial polynomialExample(example_coeffs) ;
    ASSERT(polynomialExample.getCoefficients().size() == 4) ;
    ASSERT(polynomialExample.getCoefficients()[0] == 10) ;
    ASSERT(polynomialExample.getCoefficients()[1] == 20) ;
    ASSERT(polynomialExample.getCoefficients()[2] == 30) ;
    ASSERT(polynomialExample.getCoefficients()[3] == 40) ;
}

// Defintition and Test of the member function evaluate
double Polynomial::evaluate(const double& x) const {
    
    double res = 0 ;
    int powerPolynom = (int) coefficients.size() - 1 ;
    
    for (int power_i = 0; power_i <= powerPolynom; power_i++) {
        res += coefficients[power_i] * pow(x, power_i) ;
    }
    return res ;
}

void testPolynomialEvalute(){
    
    Polynomial examplePoly(vector<double>({1, 2, 3})) ;
    ASSERT( examplePoly.evaluate(0.0) == 1) ;
    ASSERT( examplePoly.evaluate(1.0) == 6) ;
    ASSERT( examplePoly.evaluate(-1.0) == 2) ;
}

// Defintition and Test of the member function add
void Polynomial::add(const Polynomial& inputPoly){
    
    // retrieve the coeff of both polynom to be added
    int powerMainPoly = (int) coefficients.size() - 1 ;
    int powerInputPoly = (int) inputPoly.getCoefficients().size() - 1 ;
    int maxPowerPoly = max(powerMainPoly, powerInputPoly) ;

    // Initialize a new coeff vector
    vector<double> newPolyCoefficients ;
    
    for (int power_i = 0 ; power_i <= maxPowerPoly; power_i++) {
        
        // if the power we are currently considering is lower than each of the two poly -- add coeff
        if (power_i <= powerMainPoly && power_i <= powerInputPoly ) {
            newPolyCoefficients.push_back(coefficients[power_i] + inputPoly.getCoefficients()[power_i]);
        }
        // if the power we are currently considering is higher than main poly -- coeff is from InputPoly
        else if ( power_i > powerMainPoly ) {
            newPolyCoefficients.push_back(inputPoly.getCoefficients()[power_i]);
        }
        // if the power we are currently considering is higher than Input poly -- coeff is from MainPoly
        else {
            newPolyCoefficients.push_back(coefficients[power_i]);
        }
    }
    
    coefficients = newPolyCoefficients ;
    
}

void testPolynomialAdd(){
    
    // Initial poly
    Polynomial examplePolyMain(vector<double>({1, 2, 3})) ;
    //cout << examplePolyMain.getCoefficients().size() << "\n" ;

    Polynomial examplePolyInput(vector<double>({0, 0, 0, 1, 2, 3})) ;
    //cout << examplePolyInput.getCoefficients().size() << "\n" ;

    
    // add operation on examplePolyMain
    examplePolyMain.add(examplePolyInput) ;
    //cout << examplePolyMain.getCoefficients().size() << "\n" ;
    
    ASSERT( examplePolyMain.getCoefficients().size() == 6) ;
    ASSERT( examplePolyMain.getCoefficients()[0] == 1) ;
    ASSERT( examplePolyMain.getCoefficients()[1] == 2) ;
    ASSERT( examplePolyMain.getCoefficients()[2] == 3) ;
    ASSERT( examplePolyMain.getCoefficients()[3] == 1) ;
    ASSERT( examplePolyMain.getCoefficients()[4] == 2) ;
    ASSERT( examplePolyMain.getCoefficients()[5] == 3) ;
    
    // Initial poly
    Polynomial examplePolyMain2(vector<double>({0, 0, 2, 3})) ;
    //cout << examplePolyMain2.getCoefficients().size() << "\n" ;

    Polynomial examplePolyInput2(vector<double>({98, 99})) ;
    //cout << examplePolyInput2.getCoefficients().size() << "\n" ;

    
    // add operation on examplePolyMain
    examplePolyMain2.add(examplePolyInput2) ;
    //cout << examplePolyMain2.getCoefficients().size() << "\n" ;
    
    ASSERT( examplePolyMain2.getCoefficients().size() == 4) ;
    ASSERT( examplePolyMain2.getCoefficients()[0] == 98) ;
    ASSERT( examplePolyMain2.getCoefficients()[1] == 99) ;
    ASSERT( examplePolyMain2.getCoefficients()[2] == 2) ;
    ASSERT( examplePolyMain2.getCoefficients()[3] == 3) ;
}


void testPolynomialClass(){
    
//    setDebugEnabled(true) ;
    TEST( testPolynomialConstructorDefault );
//    setDebugEnabled(false) ;
    TEST( testPolynomialConstructor1 );
    TEST( testPolynomialConstructor2 );
    TEST( testPolynomialEvalute );
    TEST( testPolynomialAdd );
}
