#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double x, y_1, y_2, t, d;
	cin >> x;
	y_1 = (pow(pow((x + 1.), 2.), 1/3.) * (x + 2.) * log(x + 1.)) / (pow((x + 2.), 3.) - pow((x + 2.), 2.) + pow((x + 1.), 2.));
	t = (x + 1.);
	d = (x + 2.);
	y_2 = (pow(pow(t, 2.), 1/3.) * d * log(t)) / (pow(d, 3.) - pow(d, 2.) + pow(t, 2.));
	cout << "y_1 = " << y_1 << "\n" << "y_2 = " << y_2;
	return 0;
}