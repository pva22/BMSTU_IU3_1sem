#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, y, s1, s2, s3, d1, d2;
	cin >> x;
	y = (1. - sqrt(abs(log(x) / log(2))) + 25. * pow(10, -5) * log10(x)) / ((log(x) / log(2)) + 0.00025 * log10(x));

	s1 = sqrt(abs(log(x) / log(2)));
	s2 = log10(x);
	s3 = log(x) / log(2);

	d1 = 1. - s1 + 25. * pow(10, -5) * s2;
	d2 = s3 + 0.00025 * s2;

	cout << "y1 = " << y << endl << "y2 = " << d1 / d2;
	return 0;
}
