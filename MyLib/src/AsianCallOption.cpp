//
//  AsianCallOption.cpp
//  MyLibStaticTrue
//
//  Created by Martial Aguessi on 16/09/2026.
//

#include "AsianCallOption.hpp"

#include <algorithm> // preferred to cmatch
#include <stdexcept> // usefull for robusness

// Asian call option specific payoff.
//
// Unlike a standard European call, an Asian call is path-dependent:
// its payoff is based on the average stock price observed along the path,
// rather than only on the final stock price.
double AsianCallOption::payoff(
    const std::vector<double>& stockPrices
) const {

    // An Asian payoff requires at least one observed stock price.
    if (stockPrices.empty()) {
        throw std::invalid_argument(
            "AsianCallOption::payoff requires a non-empty stock price path."
        );
    }

    double totalStockPrices = 0.0;

    // Sum all stock prices observed along the simulated path.
    for (double spot : stockPrices) {
        totalStockPrices += spot;
    }

    // Calculate the arithmetic average stock price over the path.
    // TODO: Consider using std::accumulate for cleaner and more idiomatic C++.
    // This is mainly a readability improvement rather than a performance optimization.
    const double averageStockPrice =
        totalStockPrices / stockPrices.size();

    // Arithmetic-average Asian call payoff:
    // max(average stock price - strike, 0).
    return std::max(averageStockPrice - getStrike(), 0.0);
}
