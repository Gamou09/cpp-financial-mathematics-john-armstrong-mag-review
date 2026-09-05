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

double areaCircle(double radius){
    DEBUG_PRINT( "areaCircle(" << radius <<")" );
    return PI*radius*radius;
}

double circumferenceCircle(double radius) {
    DEBUG_PRINT( "circumferenceCircle(" << radius <<")" );
    return 2*PI*radius;
}

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
}

static void testCircumferenceCircle() {
    ASSERT_APPROX_EQUAL(circumferenceCircle(5), 31.4159, 0.001 );
}

void testGeometry() {
//    switch on the DEBUG_PRINT statements
    setDebugEnabled(true) ;
    TEST( testAreaCircle ); // should not be called witht he parenthesis
    setDebugEnabled(false) ;
    TEST( testCircumferenceCircle ); // should not be called witht he parenthesis
}
