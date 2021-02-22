#include <iostream>
#include <ctime>
using namespace std;

unsigned long long compare_counter = 0;
unsigned long long copy_counter = 0;

struct complexNum {
	double d_part;
	double m_part;
	double n_part;
};

void InputArray(int input_data[], int length) {
	srand(time(NULL));
	for (int i = 0; i < length; ++i) {
		input_data[i] = rand() % 100;
	}
}


void OutputArray(int input_data[], int length) {
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < length; ++i) {
		cout << input_data[i] << " ";
	}
}


void Swap(int& first_element, int& second_element) {
	int temp = first_element;
	first_element = second_element;
	second_element = temp;
}


int FindMinimumIndex(int input_data[], int first_index, int last_index) {
	int min_i = first_index;
	for (int i = first_index; i < last_index; ++i) {
		if (input_data[min_i] > input_data[i]) {
			min_i = i;
		}
	}
	return min_i;
}

void SelectionSort(int input_array[], int length) {
	for (int i = 0; i < length; ++i) {
		int minimum_index = FindMinimumIndex(input_array, i, length);
		Swap(input_array[i], input_array[minimum_index]);
	}
}

void BubbleUp(int input_data[], int start_index, int final_index) {
	for (int i = start_index - 1; i >= final_index; i--) {
		if (input_data[i] > input_data[i + 1])
			Swap(input_data[i], input_data[i + 1]);
	}
}

void BubbleSort(int X[], int N) {
	for (int i = 0; i < N; ++i) {
		BubbleUp(X, N - 1, i);
	}
}

void InsertionSort(int input_array[], int length) {
	int counter = 0;
	for (int i = 1; i < length; i++) {
		for (int j = i; j > 0 && input_array[j - 1] > input_array[j]; j--) {
			int tmp = input_array[j - 1];
			input_array[j - 1] = input_array[j];
			input_array[j] = tmp;
		}
	}
}

void SwapComplex(complexNum& first_element, complexNum& second_element) {
	copy_counter += 3;
	complexNum b;
	b = first_element;
	first_element = second_element;
	second_element = b;
}

double ComplexCompare(double first_element, double second_element) {
	compare_counter += 1;
	return first_element - second_element;
}
void BubbleUpComplex(complexNum input_data[], int start_index, int final_index) {
	for (int i = start_index - 1; i >= final_index; i--) {
		if (ComplexCompare(input_data[i].n_part, input_data[i + 1].n_part) > 0) {
			SwapComplex(input_data[i], input_data[i + 1]);
		}
	}
}

void BubbleUpComplex2(complexNum input_data[], int start_index, int final_index) {
	for (int i = start_index - 1; i >= final_index; i--) {
		if (ComplexCompare(input_data[i].d_part, input_data[i + 1].d_part) > 0) {
			SwapComplex(input_data[i], input_data[i + 1]);
		}
	}
}

void BubbleSort_complex(complexNum X[], int N) {
	for (int i = 0; i < N; ++i) {
		BubbleUpComplex2(X, N - 1, i);
	}
}



int main() {
	const int N = 8;
	setlocale(LC_ALL, "ru");
	int q[N];

	//InputArray(q, N);
	// Выбрать нужный вариант сортировки заранее
	//BubbleSort(q, N); 
	//SelectionSort(q, N);
	//InsertionSort(q, N);
	//OutputArray(q, 8);

	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	srand(time(NULL));
	complexNum* Mas = new complexNum[n];

	cout << "Массив из комплексных чисел: " << endl;
	for (int j = 0; j < n; j++) {
		Mas[j].d_part = rand() % 100;
		Mas[j].m_part = rand() % 100;
		Mas[j].n_part = sqrt(pow(Mas[j].d_part, 2) + pow(Mas[j].m_part, 2));
		cout << "Mas" << "[" << j << "] = " << Mas[j].d_part << " + " << Mas[j].m_part << " * i " << "|n = " << Mas[j].n_part << endl;

	}

	BubbleSort_complex(Mas, n);

	cout << endl << "Отсортированный массив из комплексных чисел:" << endl;
	for (int j = 0; j < n; j++) {
		cout << "Mas" << "[" << j << "] = " << Mas[j].d_part << " + " << Mas[j].m_part << " * i " << "|n = " << Mas[j].n_part << endl;
	}

	cout << endl;
	cout << "Копирований: " << copy_counter << " " << "Сравнений: " << compare_counter;
	delete[] Mas;

	return 0;
}
