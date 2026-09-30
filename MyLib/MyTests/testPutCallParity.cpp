//
//  testPutCallParity.cpp
//  MyTests
//
//  Created by Martial Aguessi on 30/09/2026.
//

#include <stdio.h>

#include "PortfolioImpl.hpp"
#include "CallOption.hpp"
#include "PutOption.hpp"
#include "BlackScholesModel.hpp"

using namespace std ;

static void testPutCallParity(){
    
    shared_ptr<Portfolio> portfolio = Portfolio::newInstance() ;
    
    shared_ptr<CallOption> c = make_shared<CallOption>() ;
    c->setStrike(110) ;
    c->setMaturity(1.0) ;
    
    shared_ptr<PutOption> p = make_shared<PutOption> () ;
    p->setStrike(110) ;
    p->setMaturity(1.0) ;
    
    portfolio->add(100, c) ;
    portfolio->add(-100, p) ;
    
    BlackScholesModel bsm ;
    bsm.setVolatility(0.1) ;
    bsm.setStockPrice(100) ;
    bsm.setRiskFreeRate(0) ;
    bsm.setDate(1.0) ;
    
    double expected = bsm.getStockPrice() - exp(-bsm.getRiskFreeRate()*bsm.getDate())*c->getStrike() ;
    double portfolioPrice = portfolio->price( bsm ) ;
    
    ASSERT_APPROX_EQUAL(100*expected, portfolioPrice, 1e-4) ;
    
}

void testPutCallParityWrapper() {
    
    std::cout << "\n.... Start of testPutCallParityWrapper ....\n" << std::endl;
    
    setDebugEnabled(true) ;
    TEST( testPutCallParity ) ;
    setDebugEnabled(false) ;
        
    std::cout << "\n ......................................... \n" << std::endl;
}
