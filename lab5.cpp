#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b, x, y;
	cin >> a >> b;
	y = ((2 * a) - pow(a, 2) + b) / 2;
	x = a - y;
	cout << "y = " << y << "\n" << "x = " << x;
	return 0;
}