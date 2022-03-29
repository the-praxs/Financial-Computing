#include <iostream>
#include <iomanip>
#include "CouponBond.h"
#include "NonlinearSolver02.h"

using namespace std;
using namespace fre;

int main() {
	double F = 100.0;
	double T = 3.0;
	double C = 1.2;
	double P = 98.56;

	double Acc = 0.0001;
	double LEnd = 0.0;
	double REnd = 1.0;
	double Guess = 0.2;

	NonlinearSolver solver(P, LEnd, REnd, Acc, Guess);
	CouponBond Bond(C, F, T);

	cout << "Yield by Bisection method: " << fixed << setprecision(4) << solver.SolveByBisect(&Bond) << endl;
	cout << "Yield by Newton-Raphson method: " << fixed << setprecision(4) << solver.SolveByNR(&Bond) << endl;

	return 0;
}

/*
Yield by Bisection method: 0.0168
Yield by Newton-Raphson method: 0.0168
*/