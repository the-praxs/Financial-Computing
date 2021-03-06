#include "BinomialTreeModel02.h"
#include "Option08.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace fre;

int main() {
	int N = 8;
	double U = 1.15125, D = 0.86862, R = 1.00545;
	double S0 = 106.00, K = 100.00;

	BinomialTreeModel Model(S0, U, D, R);

	ofstream fout;
	fout.open("Results.txt");

	Call call(N, K);
	OptionCalculation callCalculation(&call);
	BinLattice<double> callPriceTree;
	BinLattice<double> callXTree;
	BinLattice<double> callYTree;

	fout << "European call prices by PriceByCRR:" << fixed << setprecision(3) << callCalculation.PriceByCRR(Model) << endl << endl;
	fout << "European call prices by HW6 PriceByCRR:" << fixed << setprecision(3) << callCalculation.PriceByCRR(Model, callPriceTree, callXTree, callYTree) << endl << endl;

	fout << "Stock positions in replicating strategy:" << endl << endl;
	callXTree.Display(fout);

	fout << "Money market account positions in replicating strategy:" << endl << endl;
	callYTree.Display(fout);

	Put put(N, K);
	OptionCalculation putCalculation(&put);
	BinLattice<double> putPriceTree;
	BinLattice<double> putXTree;
	BinLattice<double> putYTree;

	fout << "European put prices by PriceByCRR:" << fixed << setprecision(3) << putCalculation.PriceByCRR(Model) << endl << endl;
	fout << "European put prices by HW6 PriceByCRR:" << fixed << setprecision(3) << putCalculation.PriceByCRR(Model, putPriceTree, putXTree, putYTree) << endl << endl;

	fout << "Stock positions in replicating strategy:" << endl << endl;
	putXTree.Display(fout);

	fout << "Money market account positions in replicating strategy:" << endl << endl;
	putYTree.Display(fout);

	fout.close();
	return 0;
}

/*
 int N = 8;
double U = 1.15125, D = 0.86862, R = 1.00545;
double S0 = 106.00, K = 100.00;

The output is written to Results.txt.
*/