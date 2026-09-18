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

private:

    // The member variables are only those associated with the model,
    // not the financial contract.
    // Very important for the class integrity.
    //
    // We keep them private so that external classes cannot directly
    // modify the internal state of the model.
    // Access should instead go through getters and setters.
    double stockPrice;
    double volatility;
    double riskFreeRate;

    // Date will be measured in years since 0 A.D.
    // Example: 01/01/2014 will be represented approximately as 2014.0.
    // For real production code, consider using a proper date type.
    double date;

    double drift;

    // Helper function to generate a price path where we can choose the drift.
    //
    // This overload is private because it is an implementation detail of
    // BlackScholesModel and should not be called directly by external classes.
    std::vector<double> generatePricePath(
        double toDate,
        int nSteps,
        double drift
    ) const;

public:

    // Default constructor.
    // OK, no need for explicit.
    BlackScholesModel();

    // Alternative constructor with one input.
    //
    // Use explicit on constructors with a single argument unless you
    // specifically want implicit conversion.
    //
    // It prevents implicit conversions from double to BlackScholesModel,
    // which can lead to confusing or unintended behaviour in larger systems.
    //
    // Do not use explicit on multi-argument constructors for this reason,
    // since they cannot normally be used for this kind of implicit conversion.
    explicit BlackScholesModel(double stockPrice);

    // The std::string class is different:
    //
    // std::string allows implicit conversions for practical and historical
    // reasons.
    //
    // std::string has one clear and common implicit conversion:
    //
    //      const char* -> std::string
    //
    // For our quant classes, prefer explicit constructors when a single
    // argument could otherwise create hidden or unclear conversions.

    // Getters.
    //
    // The const at the end means these functions do not modify the model.
    double getStockPrice() const { return stockPrice; }
    double getVolatility() const { return volatility; }
    double getRiskFreeRate() const { return riskFreeRate; }
    double getDate() const { return date; }
    double getDrift() const { return drift; }

    // Setters.
    //
    // These provide controlled access to modify the model parameters
    // without exposing the member variables directly.
    void setStockPrice(double value) { stockPrice = value; }
    void setVolatility(double value) { volatility = value; }
    void setRiskFreeRate(double value) { riskFreeRate = value; }
    void setDate(double value) { date = value; }
    void setDrift(double value) { drift = value; }

    // Member function to generate a price path.
    std::vector<double> generatePricePath(
        double toDate,
        int nSteps
    ) const;

    // Member function to generate a risk-neutral price path.
    std::vector<double> generateRiskNeutralPricePath(
        double toDate,
        int nSteps
    ) const;

    // Simulate stock price at T (S_T).
    double simulateSt() const ;
};

void testBlackScholesModel();

#endif /* BlackScholesModel_hpp */
