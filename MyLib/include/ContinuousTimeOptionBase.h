//
//  ContinuousTimeOptionBase.h
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 15/09/2026.
//

#ifndef ContinuousTimeOptionBase_h
#define ContinuousTimeOptionBase_h

#include "ContinuousTimeOption.h"

class BlackScholesModel ;

// Now we will build the base class ContinuousTimeOptionBase out of the interface
// Unlike interface, classes have some member variables

// One important consequence: ContinuousTimeOptionBase is still abstract, because it does not implement:
// payoff()
// isPathDependent ()

// So you cannot instantiate it directly: ContinuousTimeOptionBase option; // ERROR: abstract class

class ContinuousTimeOptionBase: public ContinuousTimeOption {
    
private:
    double maturity ;
    double strike ;
    
public:
    
    // Base class should do their own constrcutors
    // Avoid inline definition as it could grow and create some delay in compilation time
    ContinuousTimeOptionBase() ;
    ContinuousTimeOptionBase(const double strike_, const double maturity_) ;
    
    // Virtual destructor allows derived option objects to be safely
    // destroyed through a ContinuousTimeOptionBase pointer/reference.
    virtual ~ContinuousTimeOptionBase() {} ;
    
    // inline defintion for the getter functions
    double getMaturity() const { return maturity ; }
    double getStrike() const { return strike ; }
    
    // inline defintion of the setter functions
    void setMaturity(double maturity) {this->maturity = maturity ;}
    void setStrike(double strike) {this->strike = strike ;}
    
    /* Price the option, by Monte Carlo or otherwise*/
    // Adding the virtual keyword allow subclass to override this function wherever necessary
    // e.g. PutOption is best priced analytically rather than by MonteCarlo
    virtual double price(const BlackScholesModel& model) const ;
};

#endif /* ContinuousTimeOptionBase_h */
