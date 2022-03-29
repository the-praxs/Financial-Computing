// EuropeanOption2.hpp
//
// Class that represents  solutions to European options. This is
// an implementation using basic C++ syntax only. It has been 
// written for pedagogical reasons
//
// (C) Datasim Component Technology BV 2003-2006
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp


#include <string>
using namespace std;

class EuropeanOption
{
private:
	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double U;		// Current underlying price (e.g. stock, forward)
	double b;		// Cost of carry

	//string optType;	// Option name (call, put)
	char* optType = new char;
	//string unam;	// Name of underlying asset

	// Gaussian functions
	double n(double x) const;
	double N(double x) const;


public:	// Public functions
	EuropeanOption(double r_, double sig_, double K_, double T_, double U_, double b_) {	// Default call option
		r = r_;
		sig = sig_;
		K = K_;
		T = T_;
		U = U_;		// U == stock in this case
		b = b_;			// Black and Scholes stock option model (1973)

		*optType = 'C';			// European Call Option (this is the default type)
	}
	
	EuropeanOption(const EuropeanOption& option2) {		// Copy constructor
		r = option2.r;
		sig = option2.sig;
		K = option2.K;
		T = option2.T;
		U = option2.U;
		b = option2.b;

		optType = option2.optType;
	}

	//EuropeanOption (const string& optionType);	// Create option type
	virtual ~EuropeanOption();	

	//EuropeanOption& operator = (const EuropeanOption& option2);

	// Functions that calculate option price and sensitivities
	double Price() const;
	double Delta() const;

	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)
	const char GetOptType();	// Get the value of optType

	// 'Kernel' functions for option calculations
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;
};

#endif
