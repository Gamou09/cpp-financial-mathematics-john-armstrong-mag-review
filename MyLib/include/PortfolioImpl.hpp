//
//  PortfolioImpl.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 30/09/2026.
//

#ifndef PortfolioImpl_hpp
#define PortfolioImpl_hpp

#include <stdio.h>
#include <memory>
#include <vector>

#include "Portfolio.hpp"

class BlackScholesModel ;

class Priceable;  // Forward declaration is sufficient here.

class PortfolioImpl: public Portfolio {
    
public:
    /* Returns the number of items in the portfolio */
    int size() const override;
    
    /* Add a new security to the portfolio
       returns the index at which it was added */
    int add(double quantity,
            std::shared_ptr<Priceable> security) override;
    
    /* Update the quantity at a given index */
    void setQuantity( int index, double quantity) override;
    
    /* Compute the current price */
    double price(const BlackScholesModel& model) const override;
    
    std::vector<double> quantities ;
    std::vector< std::shared_ptr<Priceable> > securities ;
};

#endif /* PortfolioImpl_hpp */
