#include <iostream>
#include <cmath>
using namespace std;

//номер 2
int main() {
	int a, b, c;
	double x1, x2;
	double d;

	cin >> a >> b >> c;

	if ((a == 0) && (b == 0) && (c == 0)) {
		cout << "any value";
	}

	if (a) {
		d = pow(b, 2) - (4 * a * c);

		if (d == 0) {
			x1 = -b / (2 * a);
			cout << x1;
		}
		if (d < 0) {
			cout << "no solution";
		}
		if (d > 0) {
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			cout << x1 << endl << x2;
		}
	}
	else if (b) {
		x1 = -c / b;
		cout << x1;
	}
	return 0;
}