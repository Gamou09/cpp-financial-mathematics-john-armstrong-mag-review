//
//  ContinuousTimeOption.h
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 15/09/2026.
//

#ifndef ContinuousTimeOption_h
#define ContinuousTimeOption_h

#include <vector>

// Build an interface for continuous Time Option
// In C++, an interface is usually just a special kind of class.
// A normal class can contain both data and implemented behavior:
// An interface is instead used mainly to say: “Any class of this type must provide these functions.”
// In C++, this is typically written as an abstract class containing pure virtual functions:
// The = 0 means has no implementation here.
// Any concrete derived class must implement it:

// specifically in C++, there is no interface keyword like in Java or C#.
// You normally create one using an abstract base class with pure virtual functions.

// Abstract function: function with no implementation by writing =0
// the subclass MUST provide its own implementation

// these abstracts will then need to be declared as virtual so thay they can be overriden

// Interface class is a class which has ONLY has abstract functions

// An abstract class is a class that contains at LEAST one abstract function

class ContinuousTimeOption {
    
public:
    /* Virtual destructor*/
    virtual ~ContinuousTimeOption() {} ;
    
    /* The maturity of the option*/
    // = 0 makes it interface
    virtual double getMaturity() const = 0 ;
    
    /* Calculate the payoff of the option given a history of prices */
    // = 0 makes it interface
    virtual double payoff (const std::vector<double>& stockPrices) const = 0 ;
    
    /* is the option path-dependent ?*/
    // = 0 makes it interface
    virtual bool isPathDependent() const = 0 ;
};

#endif /* ContinuousTimeOption_h */
