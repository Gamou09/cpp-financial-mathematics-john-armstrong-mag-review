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
    return PI*radius*radius;
}

double circumferenceCircle(double radius) {
    return 2*PI*radius;
}
