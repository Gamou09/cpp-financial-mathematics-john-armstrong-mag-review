//
//  main.cpp
//  unit_testing
//
//  Created by Martial Aguessi on 22/05/2025.
//

#include <iostream>

using namespace std ;

// define MACRO
#define MAX(a,b) ( ( (a) >(b) ) ? (a) : (b) )

// ASSERT Macro in function
#include <cassert>

double safeSqrt(double x){
    assert (x >= 0) ;
    return sqrt(x) ;
}

// test ASSERT_APPROX_EQUAL
static void testNormInv(){
    assert
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //    test macro max
    cout  << MAX(7, 5) << "\n";
    
    //    test safe sqrt
    cout  << safeSqrt(100) << "\n";
//    cout  << safeSqrt(-100) << "\n"; // test fail when uncommented
    cout  << safeSqrt(25) << "\n\n";
    
    return 0;
}
