#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float x;
	cin >> x;

	if (abs(x) < 3) {
		cout << 0;
	}
	else if (((int(floor(abs(x))) % 2) % 2) == 0) {
		cout << 1;
	}
	else if (((int(floor(abs(x))) % 2) % 2) != 0) {
		cout << -1;
	}

}