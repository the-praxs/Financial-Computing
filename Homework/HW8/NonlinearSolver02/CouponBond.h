#pragma once
#include "Function02.h"

namespace fre {
	class CouponBond:public Function {
	private:
		double C;
		double F;
		double T;

	public:
		CouponBond(double C_, double F_, double T_) : C(C_), F(F_), T(T_) {}
		double Value(double x);
		double Deriv(double x);
	};
}