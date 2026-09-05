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

#endif /* geometry_hpp */
