#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.h"
#include "Option05.h"

using namespace std;
using namespace fre;

int main()
{
	int N = 8;
	double U = 1.15125, D = 0.86862, R = 1.00545;
	double S0 = 106.00, K = 100.00;
	double K1 = 100, K2 = 110;

	BinomialTreeModel Model(S0, U, D, R);

	Call call(N, K);
	OptionCalculation callCalculation(&call);
	cout << "European call = " << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;

	Put put(N, K);
	OptionCalculation putCalculation(&put);
	cout << "European put = " << fixed << setprecision(2) << putCalculation.PriceByCRR(Model) << endl;

	BullSpread Bull(N, K1, K2);
	OptionCalculation bullSpreadCalculation(&Bull);
	cout << "European bull spread option price = " << fixed << setprecision(2) << bullSpreadCalculation.PriceByCRR(Model) << endl;

	BearSpread Bear(N, K1, K2);
	OptionCalculation bearSpreadCalculation(&Bear);
	cout << "European bear spread option price = " << fixed << setprecision(2) << bearSpreadCalculation.PriceByCRR(Model) << endl;

	return 0;
}

/*
European call option price = 21.68
European put option price = 11.43
European bull spread option price = 4.72
European bear spread option price = 4.86
*/