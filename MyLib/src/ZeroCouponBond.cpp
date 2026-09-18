//
//  ZeroCouponBond.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 18/09/2026.
//

#include "ZeroCouponBond.hpp"
#include "BlackScholesModel.hpp"

#include <cmath>

// Constructor
// const data members must be initialized using the initializer list.
ZeroCouponBond::ZeroCouponBond(double notional_, double tenor_)
    : notional(notional_), tenor(tenor_) {
}

// Price of a zero-coupon bond:
// P(0,T) = N * exp(-rT)
//
// Assuming the BlackScholesModel provides the continuously compounded
// risk-free interest rate.
double ZeroCouponBond::price(const BlackScholesModel& model) const {

    return notional * std::exp(-model.getRiskFreeRate() * tenor);
}
