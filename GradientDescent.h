#pragma once
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class GradientDescent
{
private:
	vector<double> x, grad;
	double t, eps, h = 1e-5, M;
	int k = 0;
	size_t dim;

public:
	GradientDescent(size_t, vector<double>, double, double, double);
	double Function(vector<double>);
	void Gradient();
	bool StopCriteria(vector<double>);
	vector<double> Calculate();
	void Print();
};

