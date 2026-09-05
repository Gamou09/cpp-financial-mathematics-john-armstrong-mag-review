//
//  geometry.hpp
//  MyLib
//
//  Created by Martial Aguessi on 21/05/2025.
//


#ifndef geometry_hpp
#define geometry_hpp

#include "stdafx.h"

// we need to redefine PI here since no link between matlib header/.cpp and geometry header/.cpp
//static const double PI = 3.141592653589 ; // need to comment to avoid redefintion

double areaCircle(double radius) ;

double circumferenceCircle(double radius) ;

// test function

void testGeometry() ;

// Class declaration
// similar to other variable, or function when you declare in header you want other to be able to use it
// Intentionally left without member initializers (constructors) to demonstrate compiler warnings for uninitialized fields
class CartesianPoint {
    
// allow bellow member variables to be accessible outside of the class
// by defaut it's private
public:
    // member variables
    double x;
    double y;
    double distanceTo( const CartesianPoint& p) const ;
    double perimeterTriangle (const CartesianPoint& p1, const CartesianPoint& p2, const CartesianPoint& p3) const ;
};

void useCartesianClass() ;

class PolarPoint {
    
public:
    double r;
    double theta;
    
    // default constructor
    PolarPoint() ;
    
    // Alternative constructor
    PolarPoint(double r_, double theta_) ;
};

CartesianPoint polarToCartesian( const PolarPoint& p) ;

class Circle{
    
public:
    /// we declare member variable and  some class methods
    double radius;
    double area() ; // notice that the declaration of the method doesn't take any paremeters
    double circumference() const; // As seen before, we can add a const keyword but it has to be consistent
    // here we use const for circumference implying that measure the circumference doesn't change the circle
    
    // default constructor
    Circle() ;
    
    // Alternative constructor
    // using explicit keywords to avoid undesirable type convertion since one arg
    explicit Circle(double radius_) ;
} ;

double perimeterTriangle (const CartesianPoint& p1,
                          const CartesianPoint& p2,
                          const CartesianPoint& p3) ;

// New class with  constructor
class Point {
    
// allow bellow member variables to be accessible outside of the class
// by defaut it's private
public:
    // declare default constructor
    // No parameter for default constructor
    // key difference with normal function: Name is same as Class and no return type
    // Think of the a constructor as a function that is automatically called before anyone is allowed to see the object
    // Technically is not a function as only called when the object is being initialised and doesn't have a return value
    Point() ;
    
    // member variables
    double x;
    double y;
    
};

#endif /* geometry_hpp */
