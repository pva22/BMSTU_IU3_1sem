#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979
#include <iomanip>

using namespace std;

double fact(double n) {
	if (n == 1) return 1;
	if (n > 1) return n * fact(n - 1);
}

double formula(double k) {
	return k - pow(k, 3) / fact(3) +
		pow(k, 5) / fact(5) -
		pow(k, 7) / fact(7) +
		pow(k, 9) / fact(9);
}
double simple_formula(double l) {
	double u = pow(l, 3) / fact(3);
	double i = pow(l, 5) / fact(5);
	double p = pow(l, 7) / fact(7);
	double y = pow(l, 9) / fact(9);
	return l - u + i - p + y;
}

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Значение аргумента  " << setw(15) <<  "Значение функции Sin (x)  " <<
	setw(15) << "Приближенное значение  " << 
	setw(15) << "Приближенное значение упрощенное  " << 
	setw(15) << "Абсолютная ошибка  " << 
	setw(15)  << "Относительная ошибка  " << endl;
	for (double x = 0.1; x < M_PI / 3; x += 0.05) {
		cout << setw(20) << x << setw(20);
		cout << setw(20) << sin(x) << setw(20);
		cout << setw(20) << formula(x) << setw(20);
		cout << setw(20) << simple_formula(x) << setw(20);
		cout << setw(20) << sin(x) - formula(x) << setw(20);
		cout << setw(20) << (sin(x) - formula(x)) / sin(x) << setw(20);
		cout << endl;
	}
	return 0;
}