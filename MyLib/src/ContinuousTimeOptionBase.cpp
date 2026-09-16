//
//  ContinuousTimeOptionBase.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 15/09/2026.
//

#include "ContinuousTimeOptionBase.h"

#include "MonteCarloPricer.hpp"

#include <stdio.h>

// Base class should do their own constrcutors
// Avoid inline definition as it could grow and create some delay in compilation time
// default constructors
ContinuousTimeOptionBase::ContinuousTimeOptionBase()
    : maturity(0.0), strike(0.0) {}

// Constructor with params
ContinuousTimeOptionBase::ContinuousTimeOptionBase(const double strike_, const double maturity_)
    : maturity(maturity_), strike(strike_) {}

/* Price the option, by Monte Carlo or otherwise */
double ContinuousTimeOptionBase::price(const BlackScholesModel& model) const {
    
    MonteCarloPricer pricer ;
    return pricer.price(*this, model) ;
    
}
