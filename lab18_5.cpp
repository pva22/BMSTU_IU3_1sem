#include "iostream"
#include "conio.h"
using namespace std;

typedef int(*CompareFunctionType) (void*, void*);


template < class T >
void input(T* arr, int le){
	for (int i = 0; i < le; i++) {
		cin >> arr[i];
	}
}

template< class N >
void output(N* arr, int le){
	for (int i = 0; i < le; i++) {
		cout << arr[i] << " ";
	}
}

int CompareCharAtoZ(void* first_pointer, void* second_pointer)
{
	char* first_element_int_pointer = (char*)first_pointer;
	char* second_element_int_pointer = (char*)second_pointer;
	return *first_element_int_pointer - *second_element_int_pointer;
}

int CompareInt0to9(void* first_pointer, void* second_pointer)
{
	int* first_element_int_pointer = (int*)first_pointer;
	int* second_element_int_pointer = (int*)second_pointer;
	return *first_element_int_pointer - *second_element_int_pointer;
}

void SwapChar(char* first_pointer, char* second_pointer){
	char temp = *first_pointer;
	*first_pointer = *second_pointer;
	*second_pointer = temp;
	return;
}
void Swap(void* first_pointer, void* second_pointer, int width){
	for (int byte_number = 0; byte_number < width; byte_number++){
		SwapChar((char*)first_pointer + byte_number, (char*)second_pointer + byte_number);
	}
	return;
}


int FindMinimumIndex(char* z, int l, int width, CompareFunctionType compare_function_pointer, int j)
{
	int k = 0;
	char* t;
	t = z;
	for (int i = width; i < l * width - width * j; i++){
		if (compare_function_pointer(&z[i], t) < 0){
			t = &z[i];
			k = i;
		}
		i = i + width - 1;
	}
	return j + (k / width);
}

void SelectionSort(void* input_data, int length, CompareFunctionType compare_function_pointer, int width)
{
	int i;
	int sa;
	for (i = 0; i < length - 1; i++){
		char* z = (char*)input_data;
		char* ad = (char*)input_data;
		z = &z[i * width];
		sa = i;
		sa = FindMinimumIndex(z, length, width, compare_function_pointer, sa);
		Swap(&ad[i * width], &ad[sa * width], width);
	}
}

void main()
{
	int intarr[5];
	char chararr[5];
	int length = 5, n;
	const int N = 2;

	CompareFunctionType compareFunctionPointers[N];
	compareFunctionPointers[0] = &CompareInt0to9;
	compareFunctionPointers[1] = &CompareCharAtoZ;

	cout << "Input kind of array: " << endl;
	cout << "0: Integer type array" << endl << "1: Char type array" << endl;
	cin >> n;
	cout << "Input array elements" << endl;

	if (n == 0)
	{
		input(intarr, length);
		int width = sizeof(intarr[0]);
		SelectionSort(&intarr, length, compareFunctionPointers[n], width);
		output(intarr, length);
	}
	else
	{
		input(chararr, length);
		int width = sizeof(chararr[0]);
		SelectionSort(&chararr, length, compareFunctionPointers[n], width);
		output(chararr, length);
	}
	_getch();
}