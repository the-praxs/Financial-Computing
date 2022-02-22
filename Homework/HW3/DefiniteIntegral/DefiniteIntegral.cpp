#include "DefInt.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace fre;

double f(double x) {
	return pow(x, 3) - pow(x, 2) + 1;
}

int main() {
	int N = 10000;
	DefInt MyInt(1.0, 2.0, *f);
	cout << "Trapezoidal Approximation of Function f: " << fixed << setprecision(4) << MyInt.ByTrapzoid(N) << endl;
	cout << "Simpson Approximation of Function f: " << fixed << setprecision(4) << MyInt.BySimpson(N) << endl;
	return 0;
}

/*
	Trapezoidal Approximation of Function f: 2.4168
	Simpson Approximation of Function f: 2.4167
*/