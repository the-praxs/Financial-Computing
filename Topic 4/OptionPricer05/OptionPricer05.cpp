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
	BinomialTreeModel Model(S0, U, D, R);
	Call call(N, K);
	OptionCalculation callCalculation(&call);
	cout << "European call = " << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;
	Put put(N, K);
	OptionCalculation putCalculation(&put);
	cout << "European put = " << fixed << setprecision(2) << putCalculation.PriceByCRR(Model) << endl;
	return 0;
}

// European call = 21.68
// European put = 11.43