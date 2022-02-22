// OptionPricer03.cpp
#include "BinomialTreeModel02.h"
#include "Option03.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace fre;

int main() {
	int N = 8;
	double U = 1.15125, D = 0.86862, R = 1.00545;
	double S0 = 106.00, K = 100.00;
	BinomialTreeModel BinModel(S0, U, D, R);
	if (BinModel.ValidateInputData() != 0) return -1;
	double* optionPrice = NULL;
	optionPrice = PriceByCRR(BinModel, N, K, CallPayoff);
	cout << "Europena Call option price = " << fixed << setprecision(2) << optionPrice[0] << endl;
	delete[]optionPrice;
	optionPrice = PriceByCRR(BinModel, N, K, PutPayoff);
	cout << "Europena Put option price = " << fixed << setprecision(2) << optionPrice[0] << endl;
	delete[]optionPrice;
	optionPrice = NULL;
	return 0;
}

/*
Input data checked
There is no arbitrage
European Call option price = 21.68
European Put option price = 11.43
*/