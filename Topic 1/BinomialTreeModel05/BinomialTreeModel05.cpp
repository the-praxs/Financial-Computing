#include "BinomialTreeModel.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace fre;

int main() {
	double u = 1.15125, d = 0.86862, r = 1.00545;
	double s0 = 106.00;

	if (ValidateInputData(s0, u, d, r) == -1)
		return -1;

	// Compute asset price at every node on the Binomial Tree
	for (int n = 0; n <= 8; n++) {
		for (int i = 0; i <= n; i++) {
			cout << "Asset Price at Binomial Tree Node (" << n << "," << i << ") = " << fixed << setprecision(2);
			cout << CalculateAssetPrice(s0, u, d, n, i);
			cout << endl;
		}
	}

	return 0;
}