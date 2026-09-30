//
//  ZeroCouponBond.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 18/09/2026.
//

#ifndef ZeroCouponBond_hpp
#define ZeroCouponBond_hpp

#include "Priceable.h"

class ZeroCouponBond : public Priceable {

private:
    
    // you cannot provide setters for them. Once constructed, they cannot be modified.
    // they must be initialized in the constructor initializer list:
    const double notional;
    const double tenor;

public:
    // Constructor
    ZeroCouponBond(double notional_, double tenor_);

    // Getters
    double getNotional() const { return notional; }
    double getTenor() const { return tenor; }

    // No setters:
    // notional and tenor are const and therefore fixed after construction.

    // Implement the virtual pricing function from Priceable.
    double price(const BlackScholesModel& model) const override;
};

#endif /* ZeroCouponBond_hpp */
