//
//  PutOption.cpp
//  MyLib
//
//  Created by Martial Aguessi on 26/06/2025.
//

#include "PutOption.hpp"
#include "BlackScholesModel.hpp"

#include <cmath>


// Put-specific payoff implementation.
// Overrides the pure virtual function declared in the
// ContinuousTimeOption interface.
// The "override" keyword is used only in the class declaration in the header.
double PutOption::payoff(const std::vector<double>& stockPrices) const {

    const double stockAtMaturity = stockPrices.back();

    // Strike is stored in ContinuousTimeOptionBase
    // and inherited through the public getter.
    if (stockAtMaturity < getStrike()) {
        return getStrike() - stockAtMaturity;
    }

    return 0.0;
}


// Price the option using the supplied Black-Scholes model.
// the override key word used in declaration allow to deviate from parent class defintion
// e.g. here in particular, we want to use usual black and Scholes than Monte Carlo
double PutOption::price(const BlackScholesModel& bsm) const {

    const double S = bsm.stockPrice;
    const double K = getStrike();
    const double sigma = bsm.volatility;
    const double r = bsm.riskFreeRate;
    const double T = getMaturity() - bsm.date;

    const double numerator =
        std::log(S / K) + (r + 0.5 * sigma * sigma) * T;

    const double denominator =
        sigma * std::sqrt(T);

    const double d1 = numerator / denominator;
    const double d2 = d1 - denominator;

    return K * std::exp(-r * T) * normcdf(-d2)
         - S * normcdf(-d1);
}
