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
    double timeToMaturity = getMaturity() - bsm.getDate();

    double d2 =
        (
            std::log(bsm.getStockPrice() / getStrike())
            +
            (
                bsm.getRiskFreeRate()
                - 0.5 * bsm.getVolatility() * bsm.getVolatility()
            )
            * timeToMaturity
        )
        /
        (
            bsm.getVolatility()
            * std::sqrt(timeToMaturity)
        );

    return std::exp(-bsm.getRiskFreeRate() * timeToMaturity)
           * normcdf(d2);
}
