//
//  main.cpp
//  03_01_FunctionsManipulations
//
//  Created by Martial Aguessi on 13/05/2025.
//

#include <iostream>
#include <cmath>

//test global variable
const double PI = 3.1415922655358 ;
const double sqrt_2pi = sqrt(2.0 * PI) ;

using namespace std ;

// function 3.9.7 - Moro algorithm declaration

double norminv(double x) ;

double blackScholesCallPrice( double strike, double timeToMaturity,
                             double spot, double volatility, double riskFreeRate ) ;

// function 3.9.6

double hornerFunction( double x, double a0, double a1) {
    return a0 + x*a1;
}

double hornerFunction( double x, double a0, double a1, double a2) {
    return a0 + x*hornerFunction( x, a1, a2);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3) {
    return a0 + x*hornerFunction( x, a1, a2, a3);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4, double a5) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                      double a5, double a6, double a7) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                      double a5, double a6, double a7, double a8) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7, a8);
}

// Multiple same function name

double hornerFunction_0(double x, double a4 = 0.319381530){
    return a4 ;
}

double hornerFunction_1(double x, double a3 = -1.821255978, double a4 = 1.330274429){
    
    return a3  + x * hornerFunction_0(x, a4) ;
}

double hornerFunction_2(double x, double a2 = 1.781477937,
                        double a3 = -1.821255978, double a4 = 1.330274429){
    
    return a2  + x * hornerFunction_1(x, a3, a4) ;
}

double hornerFunction_3(double x, double a1 = -0.356563782, double a2 = 1.781477937,
                        double a3 = -1.821255978, double a4 = 1.330274429){
    
    return a1  + x * hornerFunction_2(x, a2, a3, a4) ;
}

double hornerFunction_4(double x, double a0 = 0.319381530,
                        double a1 = -0.356563782,
                        double a2 = 1.781477937,
                        double a3 = -1.821255978,
                        double a4 = 1.330274429){
    
    return a0  + x * hornerFunction_3(x, a1, a2, a3, a4) ;
}


double normcdf_approx_v4(double x) {
    
    const double k = 1.0 / (1.0 + 0.2316419 * abs(x));
    const double poly = hornerFunction_4(k) * k;
    const double gauss = exp(-0.5 * x * x) / sqrt_2pi;
    
    double cdf = 1.0 - gauss * poly;
    return (x >= 0) ? cdf : 1.0 - cdf;
}



// function 3.9.5
double normcdf_approx_v3(double x) {
    const double a1 = 0.319381530;
    const double a2 = -0.356563782;
    const double a3 = 1.781477937;
    const double a4 = -1.821255978;
    const double a5 = 1.330274429; // Note: last digit correction

    const double k = 1.0 / (1.0 + 0.2316419 * abs(x));
    const double poly = ((((a5 * k + a4) * k + a3) * k + a2) * k + a1) * k;
    const double gauss = exp(-0.5 * x * x) / sqrt_2pi;
    
    double cdf = 1.0 - gauss * poly;
    return (x >= 0) ? cdf : 1.0 - cdf;
}


// function 3.9.4

// I mplementation of a widely-used numerical approximation for the cumulative distribution function (CDF) of the standard normal distribution,
// often attributed to the algorithm by Abramowitz and Stegun.

double normcdf_approx(double x){
    
    if (x >= 0) {
        double k = 1 / (1 + 0.231641419*x) ;
        return 1 - 1/sqrt(2*PI)*exp(-pow(x, 2))*k*(0.319381530 +
                                                   k*(-0.356563782 +
                                                      k*(1.781477937 +
                                                        k*(-1.821255978 + 1.3302774429*k)))) ;
    }
    
    else return 1 - normcdf_approx(-x) ;
    
}

double normcdf_approx_v2(double x) {
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

// function 3.9.3
double fibo(int n){
    
    if (n <= 1) {
        return 1 ;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

// function 3.9.2
void print_consecutive_a_to_b(int a, int b){
    
    int max_a_b = max(a, b) ;
    int min_a_b = min(a, b) ;
    
    for (int i = min_a_b; i <= max_a_b; i++) {
        cout <<  i ;
        cout << "\n" ;
    }
}


// function 3.9.1
double sum_rec(int n){
    if (n==1) return 1 ;
    else return n + sum_rec(n-1) ;
} ;

// test namespace
namespace my_self_define_namespace {

void print_akdm(){ cout << "Print AKDM!\n" ; }

double table_3_multiplication(double var){
    return 3*var ;
}

}

// function 6 - local and global variable

double computeArea(double r){
    double answer = PI*pow(r, 2) ; // local variable
    return answer ;
}

double computeCircumference(double r){
    return 2.0 * PI * r ;
}

// function 5 - function overload

double average(int a, int b){
    cout << "Using version 1 - with two int\n" ;
    return (a + b)/2 ;
}

double average(double a, double b){
    cout << "Using version 2 - with two double\n" ;
    return (a + b)/2 ;
}

double average(double a, double b, double c){
    cout << "Using version 3 - with three double\n" ;
    return (a + b + c)/3 ;
}

// function 4 - print Hello
void printHello(){
    cout << "Hello, World!\n\n";
}

// function 3 - factorial
double factorial(int n){
    if (n == 0) return 1 ;
    else return n*factorial(n - 1) ;
}

// function 2 - Kinetic Energy
double kineticEnergy(double mass, double speed){
    return 0.5*mass*pow(speed, 2) ;
}


// function 1 - compound interest
double compoundInterest(double principal, double i, int T){
    
    double interest = principal * pow(1 + i / 100, T) - principal ; // interest is a local variable
    return interest ;
}

// function 3.9.7 - Moro algorithm definition

const double a0 = 2.50662823884;
const double a1 = -18.61500062529;
const double a2 = 41.39119773534;
const double a3 = -25.44106049637;
const double b1 = -8.47351093090;
const double b2 = 23.08336743743;
const double b3 = -21.06224101826;
const double b4 = 3.13082909833;
const double c0 = 0.3374754822726147;
const double c1 = 0.9761690190917186;
const double c2 = 0.1607979714918209;
const double c3 = 0.0276438810333863;
const double c4 = 0.0038405729373609;
const double c5 = 0.0003951896511919;
const double c6 = 0.0000321767881768;
const double c7 = 0.0000002888167364;
const double c8 = 0.0000003960315187;

double norminv( double x ) {
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

double blackScholesCallPrice( double strike, double timeToMaturity,
                              double spot, double volatility, double riskFreeRate ) {
    double numerator = log( spot/strike )
                + (riskFreeRate + volatility*volatility*0.5) * timeToMaturity;
    double denominator = volatility * sqrt( timeToMaturity );
    double d1 = numerator/denominator;
    double d2 = d1 - denominator;
    double t1 = normcdf_approx_v2( d1 ) * spot;
    double t2 = normcdf_approx_v2( d2 ) * strike * exp( - riskFreeRate*timeToMaturity);
    return t1 - t2;
}


int main(int argc, const char * argv[]) {
    
    // insert code here...
    cout << "Hello, World!\n\n";
    
//    test constant variable
    cout << "\nTest global variable defintion\n";
    cout << PI ;
    cout << "\n\n" ;
    
// test function 1 - compound interest function
    cout << "\nTest function compound Interest\n";
    double principal = 100 ;
    double interest = 12 ;
    int T = 5 ;
    cout << compoundInterest(principal, interest, T);
    cout << "\n\n" ;
    
// test function 2 - Kinetic Energy
    cout << "\nTest function Kinetic Energy\n";
    double mass = 108 ;
    double speed = 20 ;
    cout << kineticEnergy(mass, speed);
    cout << "\n\n" ;
    
//    test function 3 - factorial
    cout << "\nTest function factorial\n";
    int n = 5 ;
    cout << factorial(n) ;
    cout << "\n\n" ;
    
//    test function 4
    cout << "\nTest function who returns nothing - void\n";
    printHello() ;
    
//    test function 5
    cout << "\nTest function overload\n";
    cout << average(12, 20) ;
    cout << "\n" ;
    cout << average(12.0, 20.0) ;
    cout << "\n" ;
    cout << average(20, 40, 30) ;
    cout << "\n\n" ;
    
//  test function 6
    cout << "\nTest function for Area and circumference\n";
    cout << computeArea(123.5);
    cout << "\n" ;
    cout << computeCircumference(123.5);
    cout << "\n\n" ;
    
//    test function 7
    cout << "\nTest namesapce definition\n";
    my_self_define_namespace::print_akdm() ;
    cout << my_self_define_namespace::table_3_multiplication(23) ;
    
    cout << "\n\n" ;
    
// test function 3.9.1
    cout << "\nExercise 1\n";
    cout << sum_rec(100) ;
    cout << "\n\n" ;
    
//    test function 3.9.2
    cout << "\nExercise 2\n";
    print_consecutive_a_to_b(101, 89) ;
    cout << "\n" ;
    
//    test function 3.9.3
    cout << "\nExercise 3\n";
    cout << fibo(0) ;
    cout << "\n" ;
    cout << fibo(1) ;
    cout << "\n" ;
    cout << fibo(2) ;
    cout << "\n" ;
    cout << fibo(3) ;
    cout << "\n" ;
    cout << fibo(4) ;
    cout << "\n" ;
    cout << fibo(10) ;
    cout << "\n" ;
    cout << fibo(14) ;
    cout << "\n" ;
    cout << "\n" ;
    
//    test 3.9.4 and 3.9.5
    cout << "\nExercise 4 and 5\n";
    cout  << normcdf_approx(0.0) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v3(0.0) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v4(0.0) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v2(0.0) ;
    cout << "\n\n" ;
    
    cout  << normcdf_approx(1.) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v3(1.) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v4(1.) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v2(1.) ;
    cout << "\n\n" ;
    
    cout  << normcdf_approx(-0.7) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v3(-0.7) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v4(-0.7) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v2(-0.7) ;
    cout << "\n\n" ;
    
    cout  << normcdf_approx(1.82) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v3(1.82) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v4(1.82) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v2(1.82) ;
    cout << "\n\n" ;
    
    cout  << normcdf_approx(-1.82) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v3(-1.82) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v4(-1.82) ;
    cout << "\n" ;
    
    cout  << normcdf_approx_v2(-1.82) ;
    cout << "\n\n" ;
    
//    test function 3.9.6
    cout << "\nExercise 6\n";
    cout << hornerFunction_4(0) ;
    cout << "\n" ;
    
    cout << hornerFunction_4(1) ;
    cout << "\n\n" ;
    
// Test function 3.9.7
    cout << "\nExercise 7\n";
    cout << "This should print out approximately 0, 0.1, 0.2, ...., 1.0\n";
    cout << normcdf_approx_v4( norminv( 0.0 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.1 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.2 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.3 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.4 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.5 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.6 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.7 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.8 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.9 )) << "\n";
    cout << normcdf_approx_v4( norminv( 1.0 )) << "\n";
    cout << "This should print out approximately 0.01, 0.02,0.98,0.99\n";
    cout << normcdf_approx_v4( norminv( 0.01 )) << "\n";
    cout << normcdf_approx_v4( norminv( 0.02)) << "\n";
    cout << normcdf_approx_v4( norminv( 0.98)) << "\n";
    cout << normcdf_approx_v4( norminv( 0.99 )) << "\n";
    
//    Test function 3.9.8
    double strike = 100.0;
    double spot = 110.0;
    double vol = 0.1;
    double riskFreeRate = 0.03;
    double timeToMaturity = 0.5;
    cout << "\nExercise 8\n";
    cout << "The call price calculated is ";
    cout << blackScholesCallPrice( strike, timeToMaturity, spot, vol, riskFreeRate );
    cout << "\nExpected the value 11.677\n";
    // I simply used an online calculator to get this value
    
//    Test - exercice 3.9.11
    
//    documentation --> https://cplusplus.com/reference/cmath/erfc/
    cout << "\nExercise 11\n";
    cout << "erfc(0) = " <<erfc(0) << "\n";
    
    double param, result;
    param = 1.0;
    result = erfc (param);
    printf ("erfc(%f) = %f\n", param, result );
    
    return 0;
}
