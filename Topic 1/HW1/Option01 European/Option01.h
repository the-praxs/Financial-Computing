#pragma once

namespace fre {
	// pricing European option
	double PriceByCRR(double S0, double U, double D, double R, int N, double K);

	// computing call payoff
	double CallPayoff(double z, double K);

	// calculate the factorial
	int Factorial(int N);
}