//
//  UpAndOutOption.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 15/09/2026.
//


#include "UpAndOutCallOption.hpp"
#include <algorithm>   // std::max


// constructor
UpAndOutCallOption::UpAndOutCallOption(double strike_, double barrier_, double maturity_)
    : barrier(barrier_){
        setStrike(strike_), setMaturity(maturity_) ;
}

double UpAndOutCallOption::payoff(const std::vector<double>& path) const{

    // Check the entire stock-price path.
    // If the stock ever touches or exceeds the barrier,
    // the option is knocked out and becomes worthless.
    for (double spot : path) {

        if (spot >= barrier) {
            return 0.0;
        }
    }

    // If the barrier was never reached, the option behaves
    // like an ordinary European call at maturity.
    const double finalSpot = path.back();

    return std::max(finalSpot - getStrike(), 0.0);
}
