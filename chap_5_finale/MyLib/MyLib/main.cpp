//
//  main.cpp
//  MyLib
//
//  Created by Martial Aguessi on 21/05/2025.
//

// Angle bracket vs double quote when importing
// Anlge brackets tell the compiler that this file won't have changed since last compilation
// thus no need to compile again thefere compiler runs faster
#include <iostream>

// one by one addition of header files
//#include "matlib.h"
//#include "geometry.hpp" // same as h file but h for c++

// simplified addition of header file using the windows convention
#include "stdafx.h"

using namespace std ;

int main() {
    
    // insert code here...
    cout << "Hello, World!\n\n";
    
    // testing matlib header file function
    cout << " --- Test of the functions normcdf and norminv ---\n";
    cout << "normcdf(1.96) = " << normcdf(1.96) << "\n";
    cout << "norminv(0.975) = " << norminv(0.975) << "\n";
    cout << "norminv(norminv(0.975)) = " << normcdf(norminv(0.975)) << "\n";
    cout << "norminv(norminv(0.775)) = " << normcdf(norminv(0.775)) << "\n";
    cout << "\n" ;
    
    // Test of static variable definition
    cout << " --- Test of the static variable ---\n";
    cout << "SQRT_2_PI = " <<SQRT_2_PI << "\n\n" ;
    
    // Ex 5.5.1 - testing geometric header file function
    cout << " --- Test of the geometric cpp functions ---\n";
    cout << "Area of circle with radiu 5 is " <<areaCircle(5.0) << "\n" ;
    cout << "Circumference of circle with radiu 5 is " <<circumferenceCircle(5.0) << "\n\n" ;
    
    return 0;
}
