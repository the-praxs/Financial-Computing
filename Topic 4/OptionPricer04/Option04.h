#pragma once
#include "BinomialTreeModel02.h"

namespace fre {
	class Call {
	private:
		int N;
		double K;

	public:
		Call() : N(0), K(0) {}
		Call(int N_, double K_) : N(N_), K(K_) {}
		Call(const Call& call) : N(call.N), K(call.K) {}
		~Call() {}
		int GetN() const { return N; }
		double PayOff(double z) const;
	};

	class OptionCalculation {
	private:
		Call* pOption;
		OptionCalculation() : pOption(0) {}
		OptionCalculation(const OptionCalculation& optionCalculation) : pOption(optionCalculation.pOption) {}
	public:
		OptionCalculation(Call* pOption_) : pOption(pOption_) {}
		~OptionCalculation() {}
		double PriceByCRR(const BinomialTreeModel& Model);
	};
}