#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double x;
	double y_1, y2;
	cin >> x;

	if (x <= -2) {
		y_1 = 1;
	}
	else if (x == 0) {
		y_1 = 1;
	}
	else if (x < -1) {
		y_1 = x + 1;
	}
	else if (x < 0) {
		y_1 = x + 1;
	}
	else if (x < 1) {
		y_1 = x;
	}
	else if (x < 2) {
		y_1 = x - 1;
	}
	else if (x >= 2) {
		y_1 = 1;
	}
	else if (x == 0) {
		y_1 = 1;
	}

	if (((x < 0) && (x > -1)) || ((x < -1) && (x > -2))) {
		y2 = x + 1;
	}
	if ((x > 0) && (x < 1)) {
		y2 = x;
	}
	//if ((x < -1) && (x > -2)) {
	//	y2 = x + 1;
	//}
	if ((x > 1) && (x < 2)) {
		y2 = x - 1;
	}
	if ((x >= 2) || (x <= -2)  || (x == 0)) {
		y2 = 1;
	}
	if ((x == -1) || (x == 1)) {
		y2 = 0;
	}
	

	cout << "Y1 = " << y_1 << endl << "Y2 = " << y2;
	return 0;
}