//
//  DigitalPutOption.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 11/09/2026.
//

#include "DigitalPutOption.hpp"
#include "BlackScholesModel.hpp"

// payoff of a cash-or-nothing digital call
double DigitalPutOption::payoff(double stockAtMaturity) const
{
    return stockAtMaturity < getStrike() ? 1.0 : 0.0;
}

// analytical Black-Scholes price
double DigitalPutOption::price(const BlackScholesModel& bsm) const
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
           * normcdf(-d2);
}
