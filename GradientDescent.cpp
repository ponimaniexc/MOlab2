#include "GradientDescent.h"

GradientDescent::GradientDescent(size_t dim, double(*f)(vector<double>), double(*g1)(vector<double>), double(*g2)(vector<double>),
	vector<double> x, double t, double eps, double r, double M)
{
	this->dim = dim;
	this->f = f;
	this->g1 = g1;
	this->g2 = g2;
	this->x = x;
	this->t = t;
	this->eps = eps;
	this->r = r;
	this->M = M;
}

double GradientDescent::Function(vector<double> u)
{
	//return f(u) - r * (1 / g1(u) + 1 / g2(u));
	return f(u) - r * (log(-g1(u)) + log(-g2(u)));
}

void GradientDescent::Gradient()
{
	grad.resize(dim);

	for (int i = 0; i < dim; i++)
	{
		vector<double> x_i_next = x, x_i_prev = x;
		x_i_next[i] += h;
		x_i_prev[i] -= h;
		grad[i] = (Function(x_i_next) - Function(x_i_prev)) / (2 * h);
	}
}

bool GradientDescent::StopCriteria(vector<double> next)
{
	double x_norma = 0.;
	double max_grad = 0.;
	double f_norma = 0.;

	for (int i = 0; i < dim; i++)
	{
		x_norma += (next[i] - x[i]) * (next[i] - x[i]);

		if (max_grad < abs(grad[i])) max_grad = abs(grad[i]);

		f_norma += grad[i] * grad[i];
	}

	if (sqrt(x_norma) <= eps * eps)
		return true;

	if (abs(Function(next) - Function(x)) <= eps)
		return true;

	if (max_grad < eps)
		return true;

	if (f_norma < eps)
		return true;

	return false;
}

vector<double> GradientDescent::Calculate()
{
	vector<double> x_next(dim);

	while (true)
	{
		Gradient();

		for (int i = 0; i < dim; i++)
			x_next[i] = x[i] - t * grad[i];

		if (Function(x_next) < Function(x))
		{
			if (k + 1 > M || StopCriteria(x_next))
			{
				x = x_next;
				break;
			}
			else
			{
				x = x_next;
				k++;
			}
		}
		else
		{
			t /= 2.;
		}
	}

	return x;
}

void GradientDescent::Print()
{
	cout << "GradientDescent:\t" << "k = " << k << ";\tx = " << '(';
	for (int i = 0; i < dim; i++)
	{
		cout << x[i];
		if (i != dim - 1)
			cout << ", ";
	}
	cout << ')' << endl;
}
