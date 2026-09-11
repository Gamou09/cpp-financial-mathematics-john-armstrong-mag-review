//
//  DigitalPutOption.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 11/09/2026.
//

#include "DigitalPutOption.hpp"
#include "BlackScholesModel.hpp"

// default constructor
DigitalPutOption::DigitalPutOption() : strike(0.0), maturity(0.0) {}

// constructor with parameters
DigitalPutOption::DigitalPutOption(double s, double m): strike(s), maturity(m) {}

// setter
void DigitalPutOption::setStrike(double strike)
{
    this->strike = strike;
}

// setter
void DigitalPutOption::setMaturity(double maturity)
{
    this->maturity = maturity;
}

// getter
double DigitalPutOption::getStrike() const
{
    return strike;
}

// getter / override from PathIndependentOption
double DigitalPutOption::getMaturity() const
{
    return maturity;
}

// payoff of a cash-or-nothing digital call
double DigitalPutOption::payoff(double stockAtMaturity) const
{
    return stockAtMaturity < strike ? 1.0 : 0.0;
}

// analytical Black-Scholes price
double DigitalPutOption::price(const BlackScholesModel& bsm) const
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
           * normcdf(-d2);
}
