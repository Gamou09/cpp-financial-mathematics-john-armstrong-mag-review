//
//  Stock.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 18/09/2026.
//

#include "Stock.hpp"
#include "BlackScholesModel.hpp"

// A stock's current value is its spot price.
double Stock::price(const BlackScholesModel& model) const {
    
    return model.getStockPrice();
    
}
