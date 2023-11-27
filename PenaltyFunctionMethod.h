#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "GradientDescent.h"

class PenaltyFunctionMethod
{
public:
	vector<double> x;
	double eps1, eps2, r, C;
	int k = 0;
	size_t dim;

	double(*f)(vector<double>);
	double(*g1)(vector<double>);
	double(*g2)(vector<double>);

	PenaltyFunctionMethod(size_t, double(*)(vector<double>), double(*)(vector<double>),
		double(*)(vector<double>), vector<double>, double, double, double, double);
	//double VspFunction(vector<double>);
	vector<double> Calculate();
	void Print();
};

