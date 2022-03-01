#include "BinomialTreeModel02.h"
#include "Option04.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace fre;

int main() {
	int N = 8;
	double U = 1.15125, D = 0.86862, R = 1.00545;
	double S0 = 106.00, K = 100.00;
	BinomialTreeModel Model(S0, U, D, R);
	Call* pCall = new Call(N, K);
	OptionCalculation callCalculation(pCall);
	cout << "European call option price = " << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;
	delete pCall;
	pCall = NULL;
	return 0;
}

// European call option price = 21.68