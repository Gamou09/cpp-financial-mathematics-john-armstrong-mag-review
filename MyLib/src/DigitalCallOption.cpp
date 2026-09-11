//
//  DigitalCallOption.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 09/09/2026.
//

#include "DigitalCallOption.hpp"
#include "BlackScholesModel.hpp"
#include "matlib.h"


// default constructor
DigitalCallOption::DigitalCallOption() : strike(0.0), maturity(0.0) {}

// constructor with parameters
DigitalCallOption::DigitalCallOption(double s, double m): strike(s), maturity(m) {}

// setter
void DigitalCallOption::setStrike(double strike)
{
    this->strike = strike;
}

// setter
void DigitalCallOption::setMaturity(double maturity)
{
    this->maturity = maturity;
}

// getter
double DigitalCallOption::getStrike() const
{
    return strike;
}

// getter / override from PathIndependentOption
double DigitalCallOption::getMaturity() const
{
    return maturity;
}

// payoff of a cash-or-nothing digital call
double DigitalCallOption::payoff(double stockAtMaturity) const
{
    if (stockAtMaturity > strike)
    {
        return 1.0;
    }

    return 0.0;
}

// analytical Black-Scholes price
double DigitalCallOption::price(const BlackScholesModel& bsm) const
{
    double timeToMaturity = maturity - bsm.date;

    double d2 =
        (
            std::log(bsm.stockPrice / strike)
            +
            (
                bsm.riskFreeRate
                - 0.5 * bsm.volatility * bsm.volatility
            )
            * timeToMaturity
        )
        /
        (
            bsm.volatility
            * std::sqrt(timeToMaturity)
        );

    return std::exp(-bsm.riskFreeRate * timeToMaturity)
           * normcdf(d2);
}
