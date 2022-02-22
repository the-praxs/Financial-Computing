#include "DefInt.h"

namespace fre {
	double DefInt::ByTrapzoid(int N) {
		double h, sum;

		h = (b - a) / N;
		sum = f(a);

		for (int i = 0; i < N; i++) {
			sum += 2 * f(a + h * i);
		}

		sum += f(b);
		return ((b - a) * sum) / (2 * N);
	}

	double DefInt::BySimpson(int N) {
		return ((b - a) * (f(a) + 4 * f((a + b) / 2) + f(b))) / 6;
	}
}