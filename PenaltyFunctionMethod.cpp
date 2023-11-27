#include "PenaltyFunctionMethod.h"

PenaltyFunctionMethod::PenaltyFunctionMethod(size_t dim, double(*f)(vector<double>),
	double(*g1)(vector<double>), double(*g2)(vector<double>), vector<double> x,
	double eps1, double eps2, double r, double C)
{
	this->dim = dim;
	this->f = f;
	this->g1 = g1;
	this->g2 = g2;
	this->x = x;
	this->eps1 = eps1;
	this->eps2 = eps2;
	this->r = r;
	this->C = C;
}

vector<double> PenaltyFunctionMethod::Calculate()
{
	while (k < 1000)
	{
		GradientDescent VspFuncMin(x.size(), f, g1, g2, x, 1, eps2, r, 1000);
		x = VspFuncMin.Calculate();
		VspFuncMin.Print();

		//if (g1(x) <= 0 && g2(x) <= 0) cout << "OK" << endl;
		//else cout << "Wrong x_0" << endl;

		P = -r * (log(-g1(x)) + log(-g2(x)));

		if (abs(P) <= eps1)
		{
			break;
		}
		else
		{
			r /= C;
		}

		k++;
	}

	return x;
}

void PenaltyFunctionMethod::Print()
{
	cout << "PenaltyFunctionMethod:\t\t" << "k = " << k << ";\t\tx = " << '(';
	for (int i = 0; i < dim; i++)
	{
		cout << x[i];
		if (i != dim - 1)
			cout << ", ";
	}
	cout << ')' << endl;
}
