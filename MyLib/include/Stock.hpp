//
//  Stock.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 18/09/2026.
//

#ifndef Stock_hpp
#define Stock_hpp

#include "Priceable.h"

// A stock is a directly tradable asset.
// Under the Black-Scholes model, its current price is simply
// the current spot price stored in the model.
class BlackScholesModel ;

class Stock: public Priceable {

    
public:
    
    // implementing the virtual function from interface
    double price(const BlackScholesModel& model) const override ;
    
};

#endif /* Stock_hpp */
