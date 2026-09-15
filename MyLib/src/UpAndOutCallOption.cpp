//
//  UpAndOutOption.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 15/09/2026.
//


#include "UpAndOutCallOption.hpp"
#include <algorithm>   // std::max

#include "MonteCarloPricer.hpp"

// constructor
UpAndOutCallOption::UpAndOutCallOption(double strike, double barrier, double maturity)
    : strike(strike), barrier(barrier), maturity(maturity) {
}

double UpAndOutCallOption::getMaturity() const {
    return maturity;
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

    return std::max(finalSpot - strike, 0.0);
}


double UpAndOutCallOption::price(const BlackScholesModel& model) const {

    MonteCarloPricer pricer ;

    // we can also use *this to obtain the reference to the current object
    return pricer.price(*this, model) ;
}
