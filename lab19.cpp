#include <iostream>
using namespace std;
// По определению простым называется число, делящееся без остатка на 1 и на само себя
bool isPrime(int n, int divider = 2) {
	//if (n == 1) return true;
	if (n == divider) return true;
	if (n % divider == 0) return false;
	if (n > divider) return isPrime(n, divider + 1);
}
bool isPrime1(int n) {
	for (int divider = 2; divider < n / 2; ++divider) {
		if (n % divider == 0) {
			return false;
		}
	}
	return true;
}
int main()
{
	setlocale(LC_ALL, "ru");
	// Проверка работоспособности рекурсивного алгоритма
	for (int i = 2; i < 100; ++i) {
		if (isPrime(i)) {
			cout << i << " ";
		}
	}
	cout << endl;
	// Проверка работоспособности нерекурсивного алгоритма
	for (int i = 2; i < 100; ++i) {
		cout << "Число: " << i << (isPrime1(i) ? " Простое" : " Составное") << endl;
	}
	return 0;
}
