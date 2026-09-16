//
//  DigitalCallOption.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 09/09/2026.
//

#include "DigitalCallOption.hpp"
#include "BlackScholesModel.hpp"
#include "matlib.h"

// payoff of a cash-or-nothing digital call
double DigitalCallOption::payoff(double stockAtMaturity) const
{
    if (stockAtMaturity > getStrike())
    {
        return 1.0;
    }

    return 0.0;
}

// analytical Black-Scholes price
double DigitalCallOption::price(const BlackScholesModel& bsm) const
{
    double timeToMaturity = getMaturity() - bsm.date;

    double d2 =
        (
            std::log(bsm.stockPrice / getStrike())
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
