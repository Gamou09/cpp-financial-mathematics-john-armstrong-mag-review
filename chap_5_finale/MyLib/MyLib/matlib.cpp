//
//  matlib.cpp
//  MyLib
//
//  Created by Martial Aguessi on 21/05/2025.
//

//#include <stdio.h> // default xcode line

// Associated header file
// don't forgot the use convention to gather all header in a stdafx.h header file
//#include "matlib.h"

// include built in library
//#include <cmath>

// using the windows convention
#include "stdafx.h"

using namespace std ;

// 4.8.5 - Improved norminv

// the horner function will not be declared in the header file as helper function
// no benefit to be exposed to user
// we are static this to hide from outside user
// we are inline this code to fasten execution by avoid CALL cost in assembly
//
static inline double hornerFunction( double x, double a0, double a1) {
    return a0 + x*a1;
}

static inline double hornerFunction( double x, double a0, double a1, double a2) {
    return a0 + x*hornerFunction( x, a1, a2);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3) {
    return a0 + x*hornerFunction( x, a1, a2, a3);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4, double a5) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                      double a5, double a6, double a7) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                      double a5, double a6, double a7, double a8) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7, a8);
}

static const double a0 = 2.50662823884;
static const double a1 = -18.61500062529;
static const double a2 = 41.39119773534;
static const double a3 = -25.44106049637;
static const double b1 = -8.47351093090;
static const double b2 = 23.08336743743;
static const double b3 = -21.06224101826;
static const double b4 = 3.13082909833;
static const double c0 = 0.3374754822726147;
static const double c1 = 0.9761690190917186;
static const double c2 = 0.1607979714918209;
static const double c3 = 0.0276438810333863;
static const double c4 = 0.0038405729373609;
static const double c5 = 0.0003951896511919;
static const double c6 = 0.0000321767881768;
static const double c7 = 0.0000002888167364;
static const double c8 = 0.0000003960315187;

#include <stdexcept>

double norminv( double x ) {
    
    // add a throw error if x outside of [0,1]
    if (x > 1 || x < 0) {
        throw logic_error("X must be between 0 and 1") ;
    }
    // using the Moro's algorithm
    double y = x - 0.5;
    if (y<0.42 && y>-0.42) {
        double r = y*y;
        return y*hornerFunction(r,a0,a1,a2,a3)/hornerFunction(r,1.0,b1,b2,b3,b4);
    } else {
        double r;
        if (y<0.0) {
            r = x;
        } else {
            r = 1.0 - x;
        }
        double s = log( -log( r ));
        double t = hornerFunction(s,c0,c1,c2,c3,c4,c5,c6,c7,c8);
        if (x>0.5) {
            return t;
        } else {
            return -t;
        }
    }
}

double norminv( double x , bool throw_exception ) {
        
    // add a throw error if x outside of [0,1]
    if (throw_exception && (x > 1 || x < 0)) {
        throw logic_error("X must be between 0 and 1") ;
    }
    // using the Moro's algorithm
    double y = x - 0.5;
    if (y<0.42 && y>-0.42) {
        double r = y*y;
        return y*hornerFunction(r,a0,a1,a2,a3)/hornerFunction(r,1.0,b1,b2,b3,b4);
    } else {
        double r;
        if (y<0.0) {
            r = x;
        } else {
            r = 1.0 - x;
        }
        double s = log( -log( r ));
        double t = hornerFunction(s,c0,c1,c2,c3,c4,c5,c6,c7,c8);
        if (x>0.5) {
            return t;
        } else {
            return -t;
        }
    }
}

double normcdf(double x) {
    const double a1 = 0.319381530;
    const double a2 = -0.356563782;
    const double a3 = 1.781477937;
    const double a4 = -1.821255978;
    const double a5 = 1.330274429; // Note: last digit correction

    const double k = 1.0 / (1.0 + 0.2316419 * abs(x));
    const double poly = ((((a5 * k + a4) * k + a3) * k + a2) * k + a1) * k;
    const double gauss = exp(-0.5 * x * x) / sqrt(2.0 * PI);
    
    double cdf = 1.0 - gauss * poly;
    return (x >= 0) ? cdf : 1.0 - cdf;
}




