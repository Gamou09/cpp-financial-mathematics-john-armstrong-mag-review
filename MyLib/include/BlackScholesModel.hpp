//
//  BlackScholesModel.hpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#ifndef BlackScholesModel_hpp
#define BlackScholesModel_hpp

#include "stdafx.h"

class BlackScholesModel {
    
public:
    // the member variables are only those associated with the model not the financial contract
    // very important for the class integrity
    double stockPrice ;
    double volatility;
    double riskFreeRate;
    double date; // date will be measure in year since 0 A.D e.g 01/01/2014 will be 2014.0 - For real prod, consider proper date
    double drift ;
    
    // default constructor
    // OK, no need for explicit
    BlackScholesModel() ;
    
    // Alternative constructor with one input
    // Use explicit on constructors with a single argument unless you specifically want implicit conversion.
    // it prevents implicit conversions from double to BlackScholesModel.
    // which can lead to confusing or unintended behavior in larger systems.
    // Do not use explicit on multi-argument constructors (as they cannot be used for implicit conversions in this way).
    explicit BlackScholesModel(double stockPrice) ;
    
    // The class string is different
    // std::string allows implicit conversions for practical and historical reasons.
    // std::string has one clear, unambiguous implicit conversion (const char* → std::string).
    // For your quant classes, prefer explicit to prevent hidden, unclear behavior.
    
    // member function to generate Price Path
    std::vector<double> generatePricePath(double toDate, int nSteps) const ;
    
    // member function to generate Risk Neutreal Price Path
    std::vector<double> generateRiskNeutralPricePath(double toDate, int nSteps) const ;
    
    // Simulate Stock price at T (S_T)
    double simulateSt() ;
    
private:
    
    // helper function to generate Risk Neutreal Price Path where we can chose the drift
    std::vector<double> generatePricePath(double toDate, int nSteps, double drift) const ;
    
    
};

void testBlackScholesModel() ; 

#endif /* BlackScholesModel_hpp */
