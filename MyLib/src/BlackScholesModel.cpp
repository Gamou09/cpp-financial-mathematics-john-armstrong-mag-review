//
//  BlackScholesModel.cpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#include "BlackScholesModel.hpp"

// Default constructor.
//
// Initialise all model parameters.
// This is especially important for built-in types such as double:
// if they are not explicitly initialised, they contain indeterminate values.
BlackScholesModel::BlackScholesModel()
    : stockPrice(0.0),
      volatility(0.0),
      riskFreeRate(0.0),
      date(0.0),
      drift(0.0) {
}

// Alternative constructor with an initial stock price.
//
// The other model parameters are still initialised explicitly
// so that the object is always created in a well-defined state.
BlackScholesModel::BlackScholesModel(double stockPrice_)
    : stockPrice(stockPrice_),
      volatility(0.0),
      riskFreeRate(0.0),
      date(0.0),
      drift(0.0) {
}

// Definition of the internal generatePricePath member function.
//
// This is the general implementation where we can choose the drift.
// The public versions below simply call this function with either
// the real-world drift or the risk-free rate.
std::vector<double> BlackScholesModel::generatePricePath(
    double toDate,
    int nSteps,
    double drift
) const {

    std::vector<double> path(nSteps, 0.0);

    std::vector<double> epsilon = randn(nSteps);

    double dt = (toDate - date) / nSteps;

    double a = (drift - 0.5 * volatility * volatility) * dt;

    double b = volatility * std::sqrt(dt);

    double currentLogS = std::log(stockPrice);

    for (int i = 0; i < nSteps; i++) {

        double dLogS = a + b * epsilon[i];

        double logS = currentLogS + dLogS;

        path[i] = std::exp(logS);

        currentLogS = logS;
    }

    return path;
}

// Generate a price path using the model's real-world drift.
std::vector<double> BlackScholesModel::generatePricePath(
    double toDate,
    int nSteps
) const {

    return generatePricePath(toDate, nSteps, drift);
}

// Generate a price path under the risk-neutral measure.
//
// Under the risk-neutral measure, the drift is replaced
// by the risk-free interest rate.
std::vector<double> BlackScholesModel::generateRiskNeutralPricePath(
    double toDate,
    int nSteps
) const {

    return generatePricePath(toDate, nSteps, riskFreeRate);
}

// Simulate the stock price S_T under the risk-neutral measure.
//
// Black-Scholes dynamics:
//
// S_T = S_0 * exp(
//          (r - 0.5 * sigma^2) * T
//          + sigma * sqrt(T) * Z
//       )
//
// where Z follows a standard normal distribution.
double BlackScholesModel::simulateSt() const {

    std::mt19937 rng(std::random_device{}());

    std::normal_distribution<> normal(0.0, 1.0);

    double Z = normal(rng);

    return stockPrice * std::exp(
        (riskFreeRate - 0.5 * volatility * volatility) * date
        + volatility * std::sqrt(date) * Z
    );
}
