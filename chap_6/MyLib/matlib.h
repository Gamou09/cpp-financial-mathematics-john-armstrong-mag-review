//
//  matlib.h
//  MyLib
//
//  Created by Martial Aguessi on 21/05/2025.
//

// default lines from xcode for include guard aka avoid a file to be include twice
// this strictly as C++ work around but we can use a non C++ comand line #pragma once to do the trick
// ps: xcode by default used the name of the file as identified but you can use whatever unique combination you want
//#ifndef matlib_h
//#define matlib_h

// below include guard is not a pure C++ command but well understood by most compiler so works fine
#pragma once // this prevent the same file to be included twice or more


#include "stdafx.h"


const double PI = 3.141592653589 ;

// using static as way to hide information - in addition to not mention that in the header file
// by making the function static that it can only be used in the current source code
static const double SQRT_2_PI = 2.507 ;

/**
 * Compute the cumulative
 * distribution function of the
 * normal distribution
 */
double normcdf(double x) ;


/**
 * Computes the inverse of the normcdf
 */
double norminv(double x) ;


/**
 *  Test function
 */

void testMatlib();

// below line is need if pure C++ include guard solution is preferred
// #endif /* matlib_h */ // default line from xcode
