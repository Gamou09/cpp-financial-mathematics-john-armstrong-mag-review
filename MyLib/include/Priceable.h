//
//  Priceable.h
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 17/09/2026.
//

#ifndef Priceable_h
#define Priceable_h

class BlackScholesModel ;

// Interface class that will be extended by ContinuousTimeOption
class Priceable {
    
public:
    
    /* Compute the price of the security in the Black-Scholes world */
    virtual double price(const BlackScholesModel& model) const = 0;
    
};

#endif /* Priceable_h */
