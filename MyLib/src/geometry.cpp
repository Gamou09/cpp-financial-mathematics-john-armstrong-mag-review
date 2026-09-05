//
//  geometry.cpp
//  MyLib
//
//  Created by Martial Aguessi on 21/05/2025.
//

//#include "matlib.h" // include to use the PI definition since we can't redefine it
//#include "geometry.hpp"
// using the windows convention
#include "stdafx.h"

// using namespace
using namespace std ; 

double areaCircle(double radius){
    DEBUG_PRINT( "areaCircle(" << radius <<")" );
    return PI*radius*radius;
}

double circumferenceCircle(double radius) {
    DEBUG_PRINT( "circumferenceCircle(" << radius <<")" );
    return 2*PI*radius;
}

CartesianPoint polarToCartesian( const PolarPoint& p){
    
    CartesianPoint c;
    c.x = p.r * cos(p.theta) ;
    c.x = p.r * cos(p.theta) ;
    
    return c;
}

void useCartesianClass(){
    
    cout << "-- Testing the use of our self-defined class/Type --- \n" ;
    CartesianPoint p ;
    p.x = 100 ;
    p.y = 150 ;
    cout << "Coordinates (";
    cout << p.x ;
    cout << ", " ;
    cout << p.y ;
    cout << ")\n" ;
    
    p.x *= 2 ;
    p.y *= 2 ;
    cout << "Rescaled coordinates (";
    cout << p.x ;
    cout << ", " ;
    cout << p.y ;
    cout << ")\n" ;
    
    cout << "\n-- Testing the function polarToCartesian --- \n" ;
    PolarPoint z ;
    z.r = 10 ;
    z.theta = 2*PI ;
    
    p = polarToCartesian(z) ;
    cout << "New coordinates after polar (10, 2*PI) transforn (";
    cout << p.x ;
    cout << ", " ;
    cout << p.y ;
    cout << ")\n" ;
    
}

// definition of area and circumference method of class Circle
// declaration done inside class Circle declaration
// no need for argument as radius is already known from the class with the usage of the Circle namespace Circle::
// a member function or method can reach local class variable - radius or global variable - PI
double Circle::area(){
    DEBUG_PRINT( "areaCircle(" << radius <<")" );
    return PI*radius*radius;
}

double Circle::circumference() const{
    DEBUG_PRINT( "circumferenceCircle(" << radius <<")" );
    return 2*PI*radius;
}


// Polar point constructor
// default constructor with better syntax
PolarPoint::PolarPoint(): r(0.0), theta(0.0){}

// Alternative constructor with good syntax
PolarPoint::PolarPoint(double r_, double theta_){
    r = r_ ;
    theta = theta_;
}

// Cirle class constructor
// default constructor with better syntax
Circle::Circle(): radius(0.0){}

// Alternative constructor with better syntax
Circle::Circle(double radius_): radius(radius_){}

///////////////////////////////////////////////
//
//   TESTS
//
///////////////////////////////////////////////
///
static void testAreaCircle() {
    
    // test bounds
    ASSERT(areaCircle(5)>0);

    // test increasing
    ASSERT(areaCircle(5)>areaCircle(0.5));
        
    // test well known value
    ASSERT_APPROX_EQUAL(areaCircle(10), 314.1592653589, 0.001);
        
    // New implementation using the class
    Circle c ;
    c.radius = 4 ;
    ASSERT_APPROX_EQUAL(c.area(), 16*PI, 1e-2) ;
}

static void testCircumferenceCircle() {
    ASSERT_APPROX_EQUAL(circumferenceCircle(5), 31.4159, 0.001 );
    
    // New Implementation using the Circle class
    Circle c ;
    c.radius = 2 ;
    ASSERT_APPROX_EQUAL(c.circumference(), 4*PI, 1e-2) ;
}

static void testPolarToCartesian(){
    
    PolarPoint p ;
    p.r = 2 ;
    p.theta = PI ;
    
    CartesianPoint c = polarToCartesian( p ) ;
    ASSERT_APPROX_EQUAL(c.x, -2.0, 1e-3) ;
    ASSERT_APPROX_EQUAL(c.y, 0.0, 1e-3) ;
}

// Implementation of distanceTo and Test

double CartesianPoint::distanceTo(const CartesianPoint& p) const {
    
    return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y)) ;
    
}

static void testDistanceTo(){
    CartesianPoint p1 ;
    p1.x = 1 ;
    p1.y = 1 ;
    CartesianPoint p2 ;
    p2.x = 4 ;
    p2.y = 5 ;
    
    double d = p1.distanceTo(p2) ;
    ASSERT_APPROX_EQUAL(d, 5.0, 1e-4) ;
}

// Implement of perimeter fucntion
double perimeterTriangle (const CartesianPoint& p1,
                          const CartesianPoint& p2,
                          const CartesianPoint& p3){
    
    double d_p1_p2 = p1.distanceTo(p2) ;
    double d_p2_p3 = p2.distanceTo(p3) ;
    double d_p3_p1 = p3.distanceTo(p1) ;
    
    double perimeter_of_p1_p2_p3 = d_p1_p2 + d_p2_p3 + d_p3_p1 ;
    
    return perimeter_of_p1_p2_p3 ;
    
}

static void testPerimeterTriangle(){
    
    CartesianPoint p1 ;
    p1.x = 0 ;
    p1.y = 0 ;
    CartesianPoint p2 ;
    p2.x = 3 ;
    p2.y = 0 ;
    CartesianPoint p3 ;
    p3.x = 3 ;
    p3.y = 4 ;
    
    double example_perimeter = perimeterTriangle(p1, p2, p3) ;
    ASSERT_APPROX_EQUAL(example_perimeter, 12, 1e-3) ;
}

// Implement default constructor
// Constructor do not have return type
// good syntax
//Point::Point(){
//    x = 0.0 ;
//    y = 0.0 ;
//}
// superior syntax
// using initialisation list
// Marginal faster than the good syntax since we are using the default of each variable
// when familiar with the syntax, it's more readable because it is immediately obvious that there is nothing clever going on
Point::Point(): x(0.0),y(0.0) {}

void testGeometry() {
//    switch on the DEBUG_PRINT statements
    setDebugEnabled(true) ;
    TEST( testAreaCircle ); // should not be called witht he parenthesis
    setDebugEnabled(false) ;
    TEST( testCircumferenceCircle ); // should not be called witht he parenthesis
    TEST( testPolarToCartesian ) ;
    TEST( testDistanceTo ) ;
    TEST( testPerimeterTriangle) ;
}

