#pragma once
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Marquardt
{
private:
	double(*func)(vector<double>) = NULL;
	double(*g1)(vector<double>) = NULL;
	double(*g2)(vector<double>) = NULL;
	vector<vector<double>> H;
	vector<double> x, grad, d;
	double lambda, eps, h = 1e-3, r, M;
	int k = 0;
	size_t dim;

public:
	Marquardt(size_t, double(*)(vector<double>), double(*)(vector<double>), 
		double(*)(vector<double>), vector<double>, double, double, double, double);
	double Function(vector<double>);
	void Gradient();
	void Hessian();
	void Find_d();
	vector<double> Calculate();
	void Print();
};

