#include "Option01.h"
#include "BinomialTreeModel.h"
#include <iostream>
#include <cmath>

using namespace std;

namespace fre {
	double PriceByCRR(double S0, double U, double D, double R, int N, double K) {
		double q = RiskNeutProb(U, D, R);
		double Price = 0.0;
		int NFactorial = Factorial(N);

		for (int i = 0; i <= N; i++) {
			Price += (NFactorial / (Factorial(i) * Factorial(N - i))) * pow(q, i) * pow(1 - q, N - i) *
				CallPayoff(CalculateAssetPrice(S0, U, D, N, i), K);
		}

		Price = Price / pow(R, N);

		return Price;
	}

	double CallPayoff(double z, double K) {
		if (z > K)
			return z - K;
		return 0.0;
	}

	int Factorial(int N) {
		if (N == 0 || N == 1)
			return 1;

		return N * Factorial(N - 1);
	}

}