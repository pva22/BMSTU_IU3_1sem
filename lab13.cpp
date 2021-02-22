#include <iostream>
using namespace std;


/*Дано натуральное число A > 1. Определите, каким по счету числом
Фибоначчи оно является,то есть выведите такое число n, что φn=A.
Если А не является числом Фибоначчи, выведите число -1.*/
int main()
{
	int a, fub, buf, last=0, curr=1, iter=1;
	int fub_series[10000]; 
	fub_series[0] = 0;
	fub_series[1] = 1;
	cin >> a;

	for (int i = 2; i < 10000; i++) {
		fub_series[i] = fub_series[i - 1] + fub_series[i - 2];
		if (fub_series[i] == a) {
			cout << "fib(" << i << ")=" << a;
			iter = 0;
		}
 	}
	if (iter == 1) {
		cout << "-1";
	} 

	/*cin >> a;асчв
	while (curr != a) {
		buf = curr;
		curr = last + curr;
		last = buf;
		iter += 1;
	}
	cout << "fib(" << iter << ")=" << a;*/
}