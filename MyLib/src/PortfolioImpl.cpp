//
//  PortfolioImpl.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 30/09/2026.
//

#include "PortfolioImpl.hpp"
#include "BlackScholesModel.hpp"

/*
 With the implementation in the .cpp, we can define a name space
 which won't apply outside of this file
 
 Whearas namespace defined in header are made available to other program
 increasing risk of names conflicts
 */
using namespace std ;

shared_ptr<Portfolio> Portfolio:: newInstance(){
    
    shared_ptr<Portfolio> ret = make_shared<PortfolioImpl>() ;
    return  ret;
    
}

int PortfolioImpl::add(double quantity, shared_ptr<Priceable> security){
    
    quantities.push_back( quantity ) ;
    securities.push_back( security ) ;
    
    return quantities.size() ;
    
}

int PortfolioImpl:: size() const {

    return quantities.size() ;
    
}

void PortfolioImpl:: setQuantity(int index, double quantity) {

    quantities[index] = quantity ;
    
}

double PortfolioImpl:: price(const BlackScholesModel& model) const {
    
    double ret = 0 ;
    int n = size() ;
    for (int i = 0; i < n ; i++) {
        ret += quantities[i] * securities[i]->price( model ) ;
    }
    
    return ret ;
}


