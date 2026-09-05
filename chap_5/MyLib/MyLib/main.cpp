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
#include "matlib.h"

using namespace std ;

int main() {
    
    // insert code here...
    cout << "Hello, World!\n\n";
    
    // testing header file function
    cout << " --- Test of the functions normcdf and norminv ---\n";
    cout << "normcdf(1.96) = " << normcdf(1.96) << "\n";
    cout << "norminv(0.975) = " << norminv(0.975) << "\n";
    cout << "norminv(norminv(0.975)) = " << normcdf(norminv(0.975)) << "\n";
    cout << "norminv(norminv(0.775)) = " << normcdf(norminv(0.775)) << "\n";
    cout << "\n" ;
    
    // Test
    cout << " --- Test of the static variable ---\n";
    cout << "SQRT_2_PI = " <<SQRT_2_PI << "\n\n" ;
    
    return 0;
}
