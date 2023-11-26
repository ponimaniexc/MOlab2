#pragma once
#include <iostream>
#include <vector>
#include "Marquardt.h"

class PenaltyFunctionMethod
{
public:
	vector<double> x;
	double eps1, eps2, r, C, M;
	int k = 0;
	size_t dim;

	double(*func)(double);
	double(*g1)(double);
	double(*g2)(double);

	PenaltyFunctionMethod();
	double VspFunction();
};

