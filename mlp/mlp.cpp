#include "mlp.h"
#include <iostream>
#include <cmath>
#include <array>

using namespace std;

double SumMult(array<double, 3> x, double (&w)[3]){
	double res = 0;
	for (int i = 0; i < 3; i++) {
		res += x[i]*w[i];
	}
	return res;
}

double activationFunction(double x) {
	return x > 0 ? x:0.1*x;
}

array<double,3> hiddenLayer(double x, double(&w)[3]) {
	array <double, 3> fRes;
	for (int i = 0; i < 3; i++) {
		fRes[i] = activationFunction(x * w[i]);
	}
	return fRes;
}

double outputNeuron(double vOut) {
	return activationFunction(vOut);
}

int diff(double x) {
	return x >= 0 ? 1 : 0.1;
}

void testing(double (&x)[4], double (&ans)[4], double (&wIn)[3], double (&wOut)[3], double lambda, int epoch){
	double vOut;
	double fOut;
	double delta;
	double cur_delta;
	array<double, 3> fHidden;
	for (int j = 0; j < epoch; j++) {
		for (int i = 0; i < 4; i++) {
			fHidden = hiddenLayer(x[i], wIn);
			vOut = SumMult(fHidden, wOut);
			fOut = outputNeuron(vOut);
			double delta = (ans[i] - fOut) * diff(vOut);
			for (int k = 0; k < 3; k++) {
				wOut[k] = wOut[k] - lambda * delta * fHidden[k];
			}
			for (int k = 0; k < 3; k++) {
				cur_delta = delta * wOut[k] * diff(x[i] * wIn[k]);
				wIn[k] = wIn[k] - lambda * cur_delta * x[i];
			}
		}
	}
}

double use(int x, double(&wIn)[3], double(&wOut)[3]) {
	array<double, 3> fHidden = hiddenLayer(x, wIn);
	double vOut = SumMult(fHidden, wOut);
	double fOut = outputNeuron(vOut);
	return fOut;
}

int main()
{
	double x[] = {1, 10, 53, 100};
	double ans[] = { 39.37, 393.7,2086.6,3937};
	double wIn[3];
	double wOut[3];

	for (int i = 0; i < 3; i++) {
		wIn[i] = (double)(rand()%1000)/1000;
		wOut[i] = (double)(rand() % 1000) / 1000;
	}

	cout << use(1, wIn, wOut) << endl;
	testing(x, ans, wIn, wOut, 0.1, 10000);
	cout << use(1, wIn, wOut) << endl;
	return 0;
}
