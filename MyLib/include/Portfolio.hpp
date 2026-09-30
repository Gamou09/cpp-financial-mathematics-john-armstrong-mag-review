//
//  Portfolio.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 30/09/2026.
//

#ifndef Portfolio_hpp
#define Portfolio_hpp

#include <stdio.h>
#include <memory>

#include "Priceable.h"

class BlackScholesModel ;

class Portfolio: public Priceable {

    
public:
    /* Virtual destructor */
    // = default provides the implementation directly in the header.
    // Destructors have a special rule: even a pure virtual destructor requires a definition:
    virtual ~Portfolio() = default ;
    
    /* Returns the number of items in the portfolio */
    virtual int size() const = 0 ;
    
    /* Add a new security to the portfolio,
      returns the index at which it was added */
    virtual int add( double quantity, std::shared_ptr<Priceable> security) = 0 ;
    
    /* Update the quantity at given index */
    virtual void setQuantity (int index, double quantity) = 0 ;
    
    /* Compute the current price */
    virtual double price(const BlackScholesModel& model ) const = 0;
    
    /* Create a Portfolio
     This is a create approach as it allows to hide all information about how Portfolio is store to user
     To create a Portfolio a user of this class must call the factory method newInstance
     
     Returning a pointer to a Portfolio helps hid the member variables of the portfolio
     */
    static std::shared_ptr<Portfolio> newInstance() ;
};

#endif /* Portfolio_hpp */
