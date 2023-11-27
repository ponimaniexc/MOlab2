#include <iostream>
#include <vector>
#include "PenaltyFunctionMethod.h"

using namespace std;

double f(vector<double> u)
{
	return 3 * u[1] * u[1] - 11 * u[0] - 3 * u[1] - u[2];
}

double g_1(vector<double> u)
{
	return u[0] - 7 * u[1] + 3 * u[2] + 1;
}

double g_2(vector<double> u)
{
	return 5 * u[0] + 2 * u[1] - u[2] - 2;
}

int main()
{
	vector<double> x_0 = {0, 2, 3};
	int m = 2, l = m;
	double eps_1 = 1e-5, eps_2 = 1e-5, r = 10, C = 10;

	if (g_1(x_0) <= 0 && g_2(x_0) <= 0)
	{
		PenaltyFunctionMethod result(x_0.size(), f, g_1, g_2, x_0, eps_1, eps_2, r, C);
		result.Calculate();
		//result.Print();
	}else
		cout << "Wrong x_0";

	return 0;
}
