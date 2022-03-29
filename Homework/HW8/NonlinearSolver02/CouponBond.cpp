#include "CouponBond.h"
#include <cmath>

namespace fre {
	double CouponBond::Value(double x) {
		double P = 0;

		for (int i = 1; i <= T; i++) {
			P = P + C * exp(-x * i);
		}

		P = P + F * exp(-x * T);

		return P;
	}

	double CouponBond::Deriv(double x) {
		double P = 0;

		for (int i = 1; i <= T; i++) {
			P = P + C * exp(-x * T) * (-i);
		}

		P = P + F * exp(-x * T) * (-T);

		return P;
	}
}