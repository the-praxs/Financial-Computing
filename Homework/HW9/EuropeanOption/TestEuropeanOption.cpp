// TestEuropeanOption.cpp
// Test program for the exact solutions of European options.
// (C) Datasim Component Technology BV 2003-2006
//

#include "EuropeanOption.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	char optType;

	double rc = 0.08;
	double sigc = 0.30;
	double Kc = 65.0;
	double Tc = 0.25;
	double Uc = 60.0;
	double bc = rc;

	EuropeanOption callOption(rc, sigc, Kc, Tc, Uc, bc);
	
	optType = callOption.GetOptType();
	cout << "European Option Type: " << optType << endl;
	cout << "Q1: Call option on a stock: " << fixed << setprecision(5) << callOption.Price() << endl << endl;

	double rp = 0.1;
	double sigp = 0.30;
	double Kp = 50.0;
	double Tp = 0.25;
	double Up = 50.0;
	double bp = rp;

	EuropeanOption putOption(rp, sigp, Kp, Tp, Up, bp);
	putOption.toggle();

	optType = putOption.GetOptType();
	cout << "European Option Type: " << optType << endl;
	cout << "Q2: Put option on a stock: " << fixed << setprecision(5) << putOption.Price() << endl << endl;

	double q = 1.5;
	double Ud = Up - 1.50*exp(-0.1667*0.1);

	EuropeanOption putOptionWithDividend(rp, sigp, Kp, Tp, Ud, bp);
	putOptionWithDividend.toggle();

	optType = putOptionWithDividend.GetOptType();
	cout << "European Option Type: " << optType << endl;
	cout << "Q3: Put option with dividend: " << fixed << setprecision(5) << putOptionWithDividend.Price() << endl << endl;

	return 0;
}

/* Output:
Q1: Call option on a stock: 2.13293
Q2: Put option on a stock: 2.37561
Q3: Put option with dividend: 3.03039
*/