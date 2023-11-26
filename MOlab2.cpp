#include <iostream>
#include <vector>

using namespace std;

double Function(vector<double> u)
{
	return 3 * u[1] * u[1] - 11 * u[0] - 3 * u[1] - u[2];
}

double g_1()

int main()
{
	vector<double> x_0 = {1, 1, 1};
	int m = 2, l = m;
	double eps_1 = 1e-5, eps_2 = 1e-5;

	cout << Function(x_0);

	return 0;
}
