//
//  chap_7_classes.cpp
//  MyLib
//
//  Created by Martial Aguessi on 28/05/2025.
//

#include "stdafx.h"

using namespace std ;

vector<double> createVector(){
    
    //    create a vector
        vector<double> myVector ;
        
    //  add three elements to the end
        myVector.push_back(12.0) ;
        myVector.push_back(13.0) ;
        myVector.push_back(14.0) ;
        
    //    read the first, second and third
        cout << " --- Start reading on the vector element --- \n" ;
        cout << myVector[0] << "\n" ;
        cout << myVector[1] << "\n" ;
        cout << myVector[2] << "\n" ;
    
    //    change the values of a vector
        myVector[0] = 1 ;
        myVector[1] = 2 ;
        myVector[2] = 3 ;
        
    //    looping through a vector
        cout << " \n--- Start looping on the vector element --- \n" ;
        int n = (int) myVector.size() ;
        for (int i = 0; i < n-1; i++) {
            cout << myVector[i] << "\n" ;
        }
    
    return myVector;
}

void vectorInitialization(){
    
    //        Create a vector of length 10
    //        consisting entirely of 3.0's
            vector<double> ten3s(10, 3.0) ;
    
    // Create a vector which is a copy of another
    vector<double> copy (ten3s) ;
    ASSERT(ten3s.size() == copy.size()) ;
    cout << "The assert ten3s and copy being of the same size do not throw any error\n" ;
    
    // Replace it with myvector
    vector<double> myVector = createVector() ;
    
    copy = myVector ;
    ASSERT( myVector.size() == copy.size() ) ;
}

double sumVector(const vector<double> &v){
    double total = 0.0 ;
    int n = (int) v.size() ;
    
    for (int i=0; i <n; i++) {
        total += v[i] ;
    }
    return total ;
}

static void testSumVector(){
    
    DEBUG_PRINT("sumVector");
    
// Initialization
    vector<double> myVector ({1.0, 2.0, 3.0}) ;
    
    ASSERT(sumVector(myVector) == 6.0) ;
}

// pass by value
static void printNextValue(int x){
    x = x + 1 ;
    cout << "B1: Value of x is " << x << "\n" ;
}

// using a pass by ref (with the & sign) makes that the pointer of x is pass to the function
// the modification of the input actually affect the original vairable
// to be aboid unless necessary (e.g when passing large object as not copy is needed just the reference)
// never forget that the data is modified is situ here
static void printNextValueWithRef(int& y){
    y = y + 1 ;
    cout << "B2: Value of y is " << y << "\n" ;
}

// we can use pass by ref and force the compiler to prove that the function doesn't modify the parameters pass in
// using the const key word
static void printNextValueWithRefAndConst( const int& z){
//    z = z + 1 ; // when uncommented this code won't compile since we are change the value of the const variable pass by ref
    cout << "B3: Value of z is " << z << "\n" ;
}

// Pass by reference without const
void polarToCartesian( double r, double theta, double& x, double& y){
    DEBUG_PRINT( "polarToCartesian" );
    x = r*cos(theta) ;
    y = r*sin(theta) ;
};

static void testPolarToCartesian(){
    double r = 2.0 ;
    double theta = PI / 2 ;
    double x = 0.0, y = 0.0 ;
    polarToCartesian(r, theta, x, y) ;
    ASSERT_APPROX_EQUAL(x, 0.0, 0.001) ;
    ASSERT_APPROX_EQUAL(y, 2.0, 0.001) ;
}

void testVector(){
    
    createVector() ;
    cout << "\n" ;
    
    vectorInitialization() ;
    cout << "\n" ;
    
    setDebugEnabled(true) ;
    TEST( testSumVector ); // should not be called witht he parenthesis
    setDebugEnabled(false) ;
    
}

void testPassRef(){
    cout << "\n-- Testing the passing by not ref -- \n" ;
    int x = 10 ;
    cout << "A: Value of x is " << x << "\n" ;
    printNextValue(x) ;
    cout << "C: Value of x is " << x << "\n" ;
    
    cout << "\n-- Testing the passing by ref -- \n" ;
    int y = 100 ;
    cout << "A: Value of y is " << y << "\n" ;
    printNextValueWithRef(y) ;
    cout << "C: Value of y is " << y << "\n" ;
    
    cout << "\n-- Testing the passing by ref -- \n" ;
    int z = 100 ;
    cout << "A: Value of z is " << z << "\n" ;
    printNextValueWithRefAndConst(z) ;
    cout << "C: Value of z is " << z << "\n" ;
    
    cout << "\n-- Testing the Polar to cartesian -- \n" ;
    setDebugEnabled(true) ;
    TEST( testPolarToCartesian ); // should not be called witht he parenthesis
    setDebugEnabled(false) ;
}
