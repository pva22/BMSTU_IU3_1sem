#include <iostream>
using namespace std;

//сравнение

//2. нет, потому что ограничение на int памяти хватит на значения не привышаюшие |2 147 000 000| 
int Compare(void* first_pointer, void* second_pointer) {
	int* first_element_int_pointer = (int*)first_pointer;
	int* second_element_int_pointer = (int*)second_pointer;
	return *first_element_int_pointer - *second_element_int_pointer;
}

//3.
typedef int (*CompareFunctionType) (void*, void*);
int (*compare_function_pointer) (void*, void*) = Compare;

//4. 
int CompareInt0to9(void* first_pointer, void* second_pointer) {
	int* first_element_int_pointer = (int*)first_pointer;
	int* second_element_int_pointer = (int*)second_pointer;
	return *first_element_int_pointer - *second_element_int_pointer;
}

int CompareInt9to0(void* first_pointer, void* second_pointer) {
	int* first_element_int_pointer = (int*)first_pointer;
	int* second_element_int_pointer = (int*)second_pointer;
	return *second_element_int_pointer - *first_element_int_pointer;
}

int CompareInt0to9(void* first_pointer, void* second_pointer);
int CompareInt9to0(void* first_pointer, void* second_pointer);


//ввод массива
void InputArray(int input_data[], int length) {
	for (int i = 0; i < length; i++) {
		cin >> input_data[i];
	}
}

//поиск индекса минимального элемента в подмассиве
int FindMinimumIndex(int input_data[], int lenght, int first_index, int last_index, CompareFunctionType compare_function_pointer) {
	int min_index = first_index;
	for (first_index; first_index < last_index; first_index++) {
		//if (input_data[min_index] > input_data[first_index]) {
		//if(Compare(&input_data[min_index], &input_data[first_index]) > 0 ){
		if ((*compare_function_pointer) (&input_data[min_index], &input_data[first_index]) > 0){
			min_index = first_index;
		}
	}
	return min_index;
}

//обмен элементами массива
void Swap(int* first_element, int* second_element) {
	int buffer;
	buffer = *first_element;
	*first_element = *second_element;
	*second_element = buffer;
}

//сортировка
void SelectionSort(int input_data[], int length, CompareFunctionType compare_function_pointer) {
	for (int i = 0; i < length; i++) {
		int min_index2 = FindMinimumIndex(input_data, length, i , length, compare_function_pointer);
		Swap((input_data + i), (input_data + min_index2));
	}
}

//вывод элементов 
void OutputArray(int input_data[], int length) {
	for (int a = 0; a < length; a++) {
		cout << input_data[a] << " ";
	}
}

int main()
{
	int len;
	cin >> len;
	int* arr = new int[len];

	int Compare(void* first_pointer, void* second_pointer);

	const int N = 2;
	CompareFunctionType compareFunctionPointers[N];
	compareFunctionPointers[0] = &CompareInt0to9;
	compareFunctionPointers[1] = &CompareInt9to0;

	InputArray(arr, len);
	SelectionSort(arr, len, compareFunctionPointers[0]);
	cout << "Sorted array: ";
	OutputArray(arr, len);


	cout << endl;
	SelectionSort(arr, len, compareFunctionPointers[1]);
	cout << "Sorted array: ";
	OutputArray(arr, len);

	delete [] arr;
}
