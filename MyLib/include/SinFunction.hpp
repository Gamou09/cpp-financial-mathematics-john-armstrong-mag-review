//
//  SinFunction.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 12/09/2026.
//

#ifndef SinFunction_hpp
#define SinFunction_hpp

#include "RealFunction.h"
#include <cmath>


// Simple sine function.
class SinFunction : public RealFunction {

public:

    // Evaluate sin(x).
    double evaluate(double x) const override;
};


// Sine function that also counts how many times evaluate() has been called.
//
// numCalls is declared static because the counter belongs to the class
// as a whole and is therefore shared by every CallCountedSin object.
class CallCountedSin : public RealFunction {

public:

    // Return the total number of calls to evaluate()
    // across all CallCountedSin objects.
    static int getNumberOfCalls();

    // Evaluate sin(x) and increment the shared call counter.
    //
    // const is required because evaluate() overrides the const
    // virtual function declared in RealFunction.
    double evaluate(double x) const override {

        numCalls++;

        return std::sin(x);
    }

private:

    // Declaration of the static class variable.
    //
    // Because it is static, there is only one numCalls shared by
    // all CallCountedSin objects.
    //
    // This declaration does not allocate storage for the variable.
    // The actual definition must therefore appear once in a .cpp file.
    static int numCalls;
};

#endif /* SinFunction_hpp */
