#pragma once

#include "BinomialTreeModel02.h"
namespace fre {
	class EurOption {
	protected:
		int N;

	private:
		EurOption() : N(0) {}
		EurOption(const EurOption& option) : N(option.N) {}
	public:
		EurOption(int N_) : N(N_) {}
		int GetN() const { return N; }
		virtual double PayOff(double z) const = 0;
		virtual ~EurOption() = 0;
	};

	class Call : public EurOption {
	private:
		double K;

	public:
		Call(int N_, double K_) : EurOption(N_), K(K_) {}
		~Call() {}
		double PayOff(double z) const;
	};

	class Put : public EurOption {
	private:
		double K;

	public:
		Put(int N_, double K_) : EurOption(N_), K(K_) {}
		~Put() {}
		double PayOff(double z) const;
	};

	class OptionCalculation {
	private:
		EurOption* pOption;
		OptionCalculation() : pOption(0) {}
		OptionCalculation(const OptionCalculation& optionCalculation) : pOption(optionCalculation.pOption) {}

	public:
		OptionCalculation(EurOption* pOption_) : pOption(pOption_) {}
		~OptionCalculation() {}
		double PriceByCRR(const BinomialTreeModel& model);
	};
}