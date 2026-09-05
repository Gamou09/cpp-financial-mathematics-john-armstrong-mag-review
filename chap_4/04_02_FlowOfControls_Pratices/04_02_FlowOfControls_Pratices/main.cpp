//
//  main.cpp
//  04_02_FlowOfControls_Pratices
//
//  Created by Martial Aguessi on 16/05/2025.
//

#include <iostream>
#include <cmath>

using namespace std ;

// 4.8.1 - factorial with
// while loop

int factorial(int n){
    if(n == 0) return 1 ;
    else return n * factorial(n-1) ;
}

int factorial_while(int n){
    int res = 1 ;
    while (n > 0){
        res *=n ;
        n-- ;
    }
    
    return res ;
}

int factorial_for(int n){
    int res = 1 ;
    for (int i = 1; i <= n; i++) {
        res *= i ;
    }
    return res ;
}

int factorial_dowhile(int n){
    int res = 1 ;
    do {
        res *=n ;
        n-- ;
    }
    while (n > 0) ;
    
    return res ;
}

// 4.8.3  - rectangle rule

double rectangleRule_sin(double a, double b, int n){
    
    double res = 0 ;
    double h = (b - a)/n ;
    
    for (int i=0; i <= n-1; i++) {
        res += sin(a + i*h + 0.5*h);
    }
    
    return res / n ;
    
}

double lamba_function_for_rectangleRule(double s) {
    return (1/s*s)*exp(-0.5 * pow(s + 1 - 1/s,2)) ;
}

double rectangleRule_exp(double a, double b, int n){
    
    double res = 0 ;
    double h = (b - a)/n ;
    
    for (int i=0; i <= n-1; i++) {
        res += lamba_function_for_rectangleRule(a + i*h + 0.5*h);
    }
    
    return res / n ;
    
}

// 4.8.4  - Fibonacci loop
int fibo_loop(int n){
    
    int x_n_minus_1 = 1 ;
    int x_n_minus_2 = 1 ;
    int x_n = 1 ;
    
    if (n <= 1) {
        return x_n ;
    }
    
    for (int i = 2; i <= n; i++) {
        x_n = x_n_minus_1 + x_n_minus_2 ;
        x_n_minus_2 = x_n_minus_1 ;
        x_n_minus_1 = x_n ;
    }
    
    return x_n ;
}


// 4.8.5 - Improved norminv

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

void printIntegerAtoB(int a, int b){
    int max_a_b = (a > b) ? a:b ;
    int min_a_b = (a > b) ? b:a ;
    for (int i = min_a_b; i <= max_a_b; i++) {
        cout << i << " " ;
    }
    cout << "\n" ;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    // Test function factorial
    cout << "\n -- Exercice 4.8.1 -- \n";
    cout << "Expected output --> 5! = 120\n" ;
    cout << "Test factorial --> 5! = " << factorial(5) << "\n" ;
    cout << "Test factorial_while --> 5! = " << factorial_while(5) << "\n" ;
    cout << "Test factorial_for --> 5! = " << factorial_for(5) << "\n" ;
    cout << "Test factorial_dowhile --> 5! = " << factorial_dowhile(5) << "\n" ;
    
    // Test function rectangle rule - sin(x)
    cout << "\n -- Exercice 4.8.2 -- \n";
    cout << "Expected output --> sin(x) = 0.5\n" ;
    cout << "Test Rectangle Rule --> sin(x) = " << rectangleRule_sin(0, 1, 100000) << "\n" ;
    
    // Test function rectangle rule
    cout << "\n -- Exercice 4.8.3 -- \n";
    cout << "Test rectangleRule --> integral 0 to 1 of f(x) = " << rectangleRule_exp(0, 1, 100000) << "\n" ;
    
    // Test function rectable rule
    cout << "\n -- Exercice 4.8.4 -- \n";
    cout << "Test Fibo loop --> Fibo(0) = " << fibo_loop(0) << "\n" ;
    cout << "Test Fibo loop --> Fibo(1) = " << fibo_loop(1) << "\n" ;
    cout << "Test Fibo loop --> Fibo(2) = " << fibo_loop(2) << "\n" ;
    cout << "Test Fibo loop --> Fibo(3) = " << fibo_loop(3) << "\n" ;
    cout << "Test Fibo loop --> Fibo(4) = " << fibo_loop(4) << "\n" ;
    cout << "Test Fibo loop --> Fibo(10) = " << fibo_loop(10) << "\n";
    
    // Test function improved norminv 1
    cout << "\n -- Exercice 4.8.5 -- \n";
    cout << "Test norminv --> norminv(0) = " << norminv(0) << "\n" ;
    cout << "Test norminv --> norminv(0.1) = " << norminv(0.1) << "\n" ;
    // cout << "Test norminv --> norminv(10) = " << norminv(10) << "\n" ; // when uncommented throw an error
    cout << "Test norminv --> norminv(0.99) = " << norminv(0.99) << "\n" ;
    cout << "Test norminv --> norminv(1) = " << norminv(1) << "\n" ;
    
    // Test function improved norminv 2
    cout << "\n -- Exercice 4.8.6 -- \n";
    cout << "Test norminv v2--> norminv(0) = " << norminv(0, true) << "\n" ;
    cout << "Test norminv v2--> norminv(0.1) = " << norminv(0.1, true) << "\n" ;
    cout << "Test norminv --> norminv(10) = " << norminv(10, false) << "\n" ; // when uncommented doesn't an error because bool false
//    cout << "Test norminv --> norminv(10) = " << norminv(10, true) << "\n" ; // when uncommented throw an error because bool false
    cout << "Test norminv v2--> norminv(0.99) = " << norminv(0.99, true) << "\n" ;
    cout << "Test norminv v2--> norminv(1) = " << norminv(1, true) << "\n" ;

    // Test function print integer 0 to 9
    cout << "\n -- Exercice 4.8.7 -- \n";
    printIntegerAtoB(0, 119);
    return 0;
    
}
