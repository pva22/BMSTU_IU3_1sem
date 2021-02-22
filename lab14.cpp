#include <iostream>
using namespace std;
#include <cmath>

//метод простых итераций и половинного деления
//находит один корень, при первом приближении
double func(double x) {
	return exp(x / 2) - x - 3;
}

double func_g(double x) {
	return exp(x / 2) - 3;
}

double derivative_g(double x) {
	return  exp(x / 2) / 2;
}

double func_h(double x) {
	return 1 / (exp(x / 2) - 3); 
}

int main()
{
	double x1, x2, eps, x_last, delta, x, a, b;
	cout << "Input initial approximations: ";
	cin >> x1 >> x2;
	cout << "Input accuracy eps: ";
	cin >> eps;

	cout << "Solution by the method of simple iteration" << endl;
	if (abs(derivative_g(x1)) < 1) {
		delta = 1;
		cout << "|g'(x1)| < 1" << endl;
		while (delta > eps) {
			x_last = x1;
			x1 = func_g(x_last);
			delta = x1 - x_last;
			cout << "x: " << x1 << " " << "delta: " << delta << endl;
		}
		cout << x1 << endl;
	}
	if (abs(derivative_g(x2)) < 1) {
		delta = 1;
		cout << "|g'(x2)| < 1" << endl;
		while (delta > eps) {
			x_last = x2;
			x2 = func_g(x_last);
			delta = x2 - x_last;
			cout << "x: " << x2 << " " << "delta: " << delta << endl;
		}
		cout << x2 << endl;
	}
	cout << "Solution by the method of half division" << endl;

	if (func(1) * func(x2) < 0) {
		delta = 1;
		while (delta > eps) {
			x = (x1 + x2) / 2;
			if ((func(x) * func(x1)) < 0) {
				x2 = x;
			}
			else {
				x1 = x;
			}
			delta = abs(x1 - x2);
		}
		cout << x1 << endl;
	}
	return 0;
}