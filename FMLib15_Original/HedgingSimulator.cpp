#include "HedgingSimulator.h"
#include "testing.h"
#include "matlib.h"

using namespace std;

HedgingSimulator::HedgingSimulator() {
	// Choose default models and options
	shared_ptr<BlackScholesModel> model(
		new BlackScholesModel());
	model->stockPrice = 1;
	model->date = 0;
	model->riskFreeRate = 0.05;
	model->volatility = 0.2;
	model->drift = 0.10;

	shared_ptr<CallOption> option(new CallOption());
	option->setStrike(model->stockPrice);
	option->setMaturity(1);

	setToHedge(option);
	setSimulationModel(model);
	setPricingModel(model);

	nSteps = 10;
}

/*  Runs a number of simulations and returns
a vector of the profit and loss */
std::vector<double>
  HedgingSimulator::runSimulations(int nSimulations)
		    const {
	std::vector<double> ret(nSimulations);
	for (int i = 0; i < nSimulations; i++) {
		ret[i] = runSimulation();
	}
	return ret;
}
/*  Run a simulation and compute the profit and loss */
double HedgingSimulator::runSimulation() const {
    const double T = toHedge->getMaturity();
    const double S0 = simulationModel->stockPrice;

    const std::vector<double> pricePath =
        simulationModel->generatePricePath(T, nSteps);

    const double dt = T / nSteps;
    const double growthFactor =
        std::exp(simulationModel->riskFreeRate * dt);

    const double charge = chooseCharge(S0);
    double stockQuantity = selectStockQuantity(0.0, S0);

    // Initial premium finances the stock purchase and bank account.
    double bankBalance = charge - stockQuantity * S0;

    // Rebalance at each intermediate date, excluding maturity.
    for (int i = 0; i < nSteps - 1; ++i) {
        bankBalance *= growthFactor;

        const double S = pricePath[i];
        const double date = dt * (i + 1);

        const double newStockQuantity =
            selectStockQuantity(date, S);

        // Buying stock reduces cash; selling stock increases it.
        const double costs =
            (newStockQuantity - stockQuantity) * S;

        bankBalance -= costs;
        stockQuantity = newStockQuantity;
    }

    // Accrue the bank account over the final interval.
    bankBalance *= growthFactor;

    const double finalPrice = pricePath[nSteps - 1];
    const double stockValue = stockQuantity * finalPrice;
    const double payout = toHedge->payoff(finalPrice);

    // Terminal hedging P&L for the option seller.
    return bankBalance + stockValue - payout;
}

/*  How much should we charge the customer */
double HedgingSimulator::chooseCharge(
		double stockPrice) const {
	// create a copy of the pricing model
	BlackScholesModel pm = *pricingModel;
	pm.stockPrice = stockPrice;
	return toHedge->price(pm);
}

/*  How much stock should we hold */
double HedgingSimulator::selectStockQuantity(
		double date,
		double stockPrice) const {
	// create a copy of the pricing model
	BlackScholesModel pm = *pricingModel;
	pm.stockPrice = stockPrice;
	pm.date = date;
	return toHedge->delta(pm);
}



//
//
//   Tests
//
//


static void testDeltaHedgingMeanPayoff() {
	rng("default");
	HedgingSimulator simulator;
	simulator.setNSteps(1000);
	vector<double> result
		= simulator.runSimulations(1);
	ASSERT_APPROX_EQUAL(result[0], 0.0, 0.01);
}

static void testPlotDeltaHedgingHistogram() {
	rng("default");
	HedgingSimulator simulator;
	simulator.setNSteps(100);
	vector<double> result =
		simulator.runSimulations(10000);
	hist("deltaHedgingPNL.html", result, 20);
}
void testHedgingSimulator() {
	TEST(testDeltaHedgingMeanPayoff);
	TEST(testPlotDeltaHedgingHistogram);
}
