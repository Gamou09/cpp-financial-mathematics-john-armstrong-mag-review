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
           * normcdf(-d2);
}
