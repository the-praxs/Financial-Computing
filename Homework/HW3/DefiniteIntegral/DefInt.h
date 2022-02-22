#pragma once

namespace fre {
	class DefInt {
	private:
		double a;
		double b;
		double(*f) (double x);

	public:
		DefInt(double A, double B, double(*F)(double x)) : a(A), b(B), f(F) {}
		double ByTrapzoid(int N);
		double BySimpson(int N);
		~DefInt() {}
	};
}