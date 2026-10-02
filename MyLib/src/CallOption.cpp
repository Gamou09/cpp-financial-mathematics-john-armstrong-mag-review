//
//  CallOption.cpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#include "CallOption.hpp"
#include "BlackScholesModel.hpp"
#include "matlib.h"

#include <algorithm>  // Standard library algorithms: std::max for the call payoff.
#include <cmath>      // Standard library math functions: std::log, std::sqrt, std::exp.

// The anonymous namespace keeps calculateD1() local to this source file, so no header change is needed.
// Help avoid repetition
namespace {
    // Used only within this .cpp file.
    double calculateD1(double S, double K, double sigma,
                       double r, double T) {
        return (std::log(S / K) + (r + 0.5 * sigma * sigma) * T)
             / (sigma * std::sqrt(T));
    }
}

double CallOption::payoff(double stockAtMaturity) const {
    // The strike is already stored in the option.
    return std::max(stockAtMaturity - getStrike(), 0.0);
}

// const double means the variable cannot be changed after initialization.
double CallOption::price(const BlackScholesModel& bsm) const {
    const double S = bsm.getStockPrice();
    const double K = getStrike();
    const double sigma = bsm.getVolatility();
    const double r = bsm.getRiskFreeRate();
    const double T = getMaturity() - bsm.getDate();

    const double d1 = calculateD1(S, K, sigma, r, T);
    const double d2 = d1 - sigma * std::sqrt(T);

    return S * normcdf(d1)
         - K * std::exp(-r * T) * normcdf(d2);
}

double CallOption::delta(const BlackScholesModel& bsm) const {
    const double S = bsm.getStockPrice();
    const double K = getStrike();
    const double sigma = bsm.getVolatility();
    const double r = bsm.getRiskFreeRate();
    const double T = getMaturity() - bsm.getDate();

    return normcdf(calculateD1(S, K, sigma, r, T));
}
