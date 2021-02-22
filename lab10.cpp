#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
	int arr[4];
	int arr_num[10]{ 0,1,2,3,4,5,6,7,8,9 };
	int arr_num_without[6];
	int a,b;

	cin >> a >> b;

	arr[0] = a / 10;
	arr[1] = a % 10;
	arr[2] = b / 10;
	arr[3] = b % 10;
	int iter = 0;
	for (int i = 0; i < 10; i++) {
		if ((arr_num[i] != arr[0]) & (arr_num[i] != arr[1]) & (arr_num[i] != arr[2]) & (arr_num[i] != arr[3])) {
			arr_num_without[iter] = arr_num[i];
			iter += 1;
		}
	}
	for (int j = 0; j < 6; j++) {
		cout << arr_num_without[j] << endl;
	}
	if (arr_num_without[0] != 0) {
		cout << arr_num_without[0] << arr_num_without[0] << " " << arr_num_without[5] << arr_num_without[5];
	}
	else {
		cout << arr_num_without[1] << arr_num_without[0] << " " << arr_num_without[5] << arr_num_without[5];
	}
}