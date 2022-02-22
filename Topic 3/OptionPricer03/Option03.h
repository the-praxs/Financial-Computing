#pragma once
#include "BinomialTreeModel02.h"

namespace fre {
	// Inputting and displaying option data
	int GetInputData(int& N, double& K);

	// Pricing Europen Option
	double* PriceByCRR(const BinomialTreeModel& Model, int N, double K, double (*PayOff)(double z, double K));

	// Computing Call Payoff
	double CallPayoff(double z, double K);

	// Computing Put Payoff
	double PutPayoff(double z, double K);
}