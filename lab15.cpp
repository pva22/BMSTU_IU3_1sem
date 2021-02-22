#include <iostream>
#include <vector>
#define M_E 2.7182818284590452353
#define M_PI 3.14159265358979323846
#include <cmath>

using namespace std;

bool change_sing(double last_val, double cur_val) {
	int sign_1;
	int sign_2;
	if (last_val > 0) {
		sign_1 = 1;
	}
	else {
		sign_1 = -1;
	}
	if (cur_val > 0) {
		sign_2 = 1;
	}
	else {
		sign_2 = -1;
	}
	return (sign_1 == sign_2);
}
int main() {
	setlocale(LC_ALL, "Rus");
	double start, end, step;
	cout << "Введите начало интервала, его конец и шаг" << endl;
	cin >> start >> end >> step;
	double Arr[20];
	int arr_len = 0;
	int step_count = (end - start) / step;

	int cout_if = 0;

	double cur_val;
	double last_x = start;
	double last_val = 2 * sin(last_x + 2);


	for (int i = 0; i < step_count; i++){
		double x = start + (i * step);
		cur_val = 2 * sin(x + 2);
		cout << "Current x: " << x << endl;
		cout << "Current val: " << cur_val << endl;
		if (! change_sing(last_val, cur_val)) {
			Arr[cout_if] = last_x;
			cout_if++;
		}

		last_val = cur_val;
		last_x = x;
	}
	cout << "Массив искомый" << endl;
	for (int j = 0; j < cout_if; j++) {
		cout << Arr[j] << endl;
	}
	return 0;
}

