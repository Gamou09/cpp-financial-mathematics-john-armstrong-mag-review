//
//  testCallCountedSin.cpp
//  MyTests
//
//  Created by Martial Aguessi on 16/09/2026.
//


#include <stdio.h>

#include "SinFunction.hpp"
#include "Integral.hpp"
#include "testing.hpp"


static void testCallCountedSinNumCalls(){
    
    CallCountedSin instanceSin1 ;
    CallCountedSin instanceSin2 ;
    
    integral(instanceSin1, 0, 1, 1000);
    integral(instanceSin2, 0, 1, 1000);
    
    // How we call a static member function
    int numCalls = CallCountedSin::getNumberOfCalls() ;
    
    
    ASSERT( numCalls == 2000) ;
    
}

void testCallCountedSin() {
    
    std::cout << "\n.... Start of testCallCountedSin ....\n" << std::endl;
    
    setDebugEnabled(true) ;
    TEST( testCallCountedSinNumCalls ) ;
    setDebugEnabled(false) ;
    
    std::cout << "\n ......................................... \n" << std::endl;
}
