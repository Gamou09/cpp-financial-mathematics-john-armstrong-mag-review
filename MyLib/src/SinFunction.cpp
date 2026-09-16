//
//  SinFunction.cpp
//  MyLIbStaticTrue
//
//  Implementation of SinFunction and CallCountedSin.
//
//  Created by Martial Aguessi on 12/09/2026.
//

#include "SinFunction.hpp"


// Definition and initialization of the static class variable.
//
// The declaration
//
//      static int numCalls;
//
// appears inside CallCountedSin in the header.
//
// Because numCalls is a static data member, it must also be defined
// once outside the class. Without this definition, the linker reports:
//
//      Undefined symbol: CallCountedSin::numCalls
//
int CallCountedSin::numCalls = 0;


// Evaluate the standard sine function.
double SinFunction::evaluate(double x) const {

    return std::sin(x);
}


// Return the number of times CallCountedSin::evaluate()
// has been called.
//
// Because this function is static, it belongs to the class
// and can be called without creating a CallCountedSin object:
//
//      CallCountedSin::getNumberOfCalls();
//
int CallCountedSin::getNumberOfCalls() {

    return numCalls;
}
