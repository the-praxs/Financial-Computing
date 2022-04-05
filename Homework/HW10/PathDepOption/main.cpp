#include <iostream>
#include "PathDepOption.h"

using namespace std;
using namespace fre;

int main() {
	double S0 = 100.0, r = 0.03, sigma = 0.2;
	MCModel Model(S0, r, sigma);
	
	double T = 1.0 / 12.0, K = 100.0;
	int m = 30;
	ArthmAsianCall Option(T, K, m);
	
	long N = 30000;
	double epsilon = 0.001;
	Option.PriceByMC(Model, N, epsilon);
	cout << "Asian Call Price = " << Option.GetPrice() << endl << 
			"Pricing Error = " << Option.GetPricingError() << endl <<
			"delta = " << Option.GetDelta() << endl <<
			"gamma = " << Option.GetGamma();

	return 0;
}

/*
Asian Call Price = 1.41927
Pricing Error = 0.0120013
delta = 0.523105
gamma = 0.119361

Asian Call Price = 1.41796
Pricing Error = 0.0120795
delta = 0.52306
gamma = 0.117813
*/