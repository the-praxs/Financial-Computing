#pragma once
#include "MCModel02.h"

namespace fre {
	class PathDepOption {
	protected:
		double Price;
		int m;
		double K;
		double T;
		Vector delta;

	public:
		PathDepOption(double T_, double K_, int m_) : Price(0.0), T(T_), K(K_), m(m_) {}
		double PriceByMC(const MCModel& Model, long N, double epsilon);
		virtual ~PathDepOption() {}
		virtual double Payoff(const SamplePath& S) const = 0;
		Vector GetDelta() { return delta; }
	};

	class ArthmAsianCall : public PathDepOption {
	public:
		ArthmAsianCall(double T_, double K_, int m_) : PathDepOption(T_, K_, m_) {}
		double Payoff(const SamplePath& S) const;
	};
}
