#include "DoubDigitOpt.h"

namespace fre {
	double DoubDigitOpt::PayOff(double z) const {
		if (K1 < z && z < K2) return 1.0;
		return 0.0;
	}
}