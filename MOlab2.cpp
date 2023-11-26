#include <iostream>
#include <vector>

using namespace std;

double Function(vector<double> u)
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
	vector<double> x_0 = {1, 1, 1};
	int m = 2, l = m;
	double eps_1 = 1e-5, eps_2 = 1e-5, r = 10, C = 10;

	cout << Function(x_0);

	return 0;
}
