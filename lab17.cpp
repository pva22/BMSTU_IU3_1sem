/*В тех местах где требуется использовать функции Input для ввода массива, я использую
функции Zero, присваивая всем элементам массива значение 0. Это связанно с большим количеством
одновременно выполняющихся функций в программе, и для того чтобы при проверке работоспособности программы не тратить время на ввод значений
элементов массивов, я просто их обнуляю*/
#include <iostream>
using namespace std;

const int ARRAY_LENGTH = 100;
const int ARRAY_HEIGHT = 10;
const int ARRAY_WIDTH = 20;
const int ARRAY_DEPTH = 3;

//Функция обнуления одномерного статического и одномерного динамического массивов,
//работает с массивами произвольной длины(универсальна)
void Zero1DArray(int my_1d_array[], int length) {
	for (int index = 0; index < length; ++index) {
		my_1d_array[index] = 0;
	}
}

//Функция обнуления двумернго статического массива, работает с массивом ширины ARRAY_WIDTH
void Zero2DStaticArray(int my_2d_array[][ARRAY_WIDTH], int length, int width) {
	for (int row_index = 0; row_index < length; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			my_2d_array[row_index][column_index] = 0;
		}
	}
}

//Функция обнуления двумерного статического массива,
//работает с массивами произвольных размеров(универсальна)
void Zero2DStaticArrayUniversal(int my_2d_array[], int length, int width) {
	for (int row_index = 0; row_index < length; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			my_2d_array[row_index * width + column_index] = 0;
		}
	}
}

//Функция обнуления двумерного динамического массива(принимает на вход массив указателей на числа)
//, работает с массивами произвольных размеров 
void Zero2DDynamicArrray(int** my_2d_array, int length, int width) {
	for (int row_index = 0; row_index < length; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			my_2d_array[row_index][column_index] = 0;
		}
	}
}

//Функция обнуления трехмерного статического массива, работает с массивами произвольных размеров
void Zero3DStaticArray(int my_3d_array[], int height, int width, int depth) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			for (int depth_index = 0; depth_index < depth; ++depth_index) {
				my_3d_array[(row_index * width + column_index) * depth + depth_index] = 0;
			}
		}
	}
}
//Функция ввода трехмерного статического массива, работает с массивами произвольных размеров
void Input3DStaticArray(int my_3d_array[], int height, int width, int depth) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			for (int depth_index = 0; depth_index < depth; ++depth_index) {
				cin >> my_3d_array[(row_index * width + column_index) * depth + depth_index];
			}
		}
	}
}
//Функция выделения памяти для техмерного динамического массива
int*** AllocateMemory3DArray(int height, int width, int depth) {
	int*** my_3d_array = new int** [height];
	for (int row_index = 0; row_index < height; ++row_index) {
		my_3d_array[row_index] = new int* [width];
		for (int column_index = 0; column_index < width; ++column_index) {
			my_3d_array[row_index][column_index] = new int[depth];
		}
	}
	return my_3d_array;
}

//Функция обнуления трехмерного динамического массива
void Zero3DDynamicArray(int*** my_3d_array, int height, int width, int depth) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			for (int depth_index = 0; depth_index < depth; ++depth_index) {
				my_3d_array[row_index][column_index][depth_index] = 0;
			}
		}
	}
}

//Функция ввода трехмерного динамического массива
void Input3DDynamicArray(int*** my_3d_array, int height, int width, int depth) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			for (int depth_index = 0; depth_index < depth; ++depth_index) {
				cin >> my_3d_array[row_index][column_index][depth_index];
			}
		}
	}
}

//Функция очистки памяти для трехмерного динамического массива
void FreeMemory3DArray(int*** my_3d_array, int height, int width, int depth) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			delete[] my_3d_array[row_index][column_index];
		}
		delete[] my_3d_array[row_index];
	}
	delete[] my_3d_array;
}

//Функция выделения памяти для трехмерного динамического массива одним блоком памяти
int*** AllocateLargeMemoryBlockFor3DArray(int height, int width, int depth) {
	int* large_memory_block = new int[height * width * depth];
	int*** my_3d_array = new int** [height];
	for (int row_index = 0; row_index < height; ++row_index) {
		my_3d_array[row_index] = new int* [width];
		for (int column_index = 0; column_index < width; ++column_index) {
			my_3d_array[row_index][column_index] = &large_memory_block[(row_index * width + column_index) * depth];
		}
	}
	return my_3d_array;
}

//Функция очистки памяти для трехмерного динамического массива заданного одним блоком памяти
void FreeLargeMemoryBlockFor3DArray(int*** my_3d_array, int height, int width, int depth) {
	int* large_memory_block = &my_3d_array[0][0][0];
	delete[] large_memory_block;
	for (int row_index = 0; row_index < height; ++row_index) {
		delete[] my_3d_array[row_index];
	}
	delete[] my_3d_array;
}

//Функция выделения памяти для трехмерного динамического массива
//одним блоком памяти с отдельным выделением места под массив указателей
int*** AllocateDataAndFirstLevelPointersMemoryBlocksFor3DArray(int height, int width, int depth) {
	int* data_memory_block = new int[height * width * depth];
	int** first_level_pointers_memory_block = new int* [height * width];
	int*** my_3d_array = new int** [height]; 
	for (int row_index = 0; row_index < height; ++row_index) {
		my_3d_array[row_index] = &first_level_pointers_memory_block[row_index * width];
		for (int column_index = 0; column_index < width; ++column_index) {
			my_3d_array[row_index][column_index] = &data_memory_block[(row_index * width + column_index) * depth];
		}
	}
	return my_3d_array;
}

//Функция очистки памяти для трехмерного динамического массива заданного
//одним блоком памяти с отдельным выделением места под массив указателей
void FreeDataAndFirstLevelPointersMemoryBlocksFor3DArray(int*** my_3d_array, int height, int width, int depth) {
	int* data_memory_block = &my_3d_array[0][0][0];
	int** first_level_pointers_memory_block = &my_3d_array[0][0];
	delete[] data_memory_block;
	delete[] first_level_pointers_memory_block;
	delete[] my_3d_array;
}



int main() {

	//Объявление и обнуление одномерного статического массива
	int Array1DS[ARRAY_LENGTH];
	Zero1DArray(Array1DS, ARRAY_LENGTH);

	//Объявление и обнуление одномерного динамического массива
	int variable_length = 100;
	int* Array1DD = new int[variable_length];
	Zero1DArray(Array1DD, variable_length);
	//Очистка памяти 
	delete[] Array1DD;

	//Объявление и обнуление двумерного статического массива
	int Array2DS[ARRAY_HEIGHT][ARRAY_WIDTH];
	Zero2DStaticArray(Array2DS, ARRAY_HEIGHT, ARRAY_WIDTH);

	//Объявление и обнуление двумерного динамического массива
	int variable_width = 100;
	int variable_height = 200;
	int** Array2DD = new int* [variable_height];
	for (int row_index = 0; row_index < variable_height; ++row_index) {
		Array2DD[row_index] = new int[variable_width];
	}
	Zero2DDynamicArrray(Array2DD, variable_height, variable_width);
	//Очистка памяти
	for (int row_index = 0; row_index < variable_height; ++row_index) {
		delete[] Array2DD[row_index];
	}
	delete[] Array2DD;

	//Передача двумерного статического в функцию обработки динамического
	int* row_pointers[ARRAY_HEIGHT];
	for (int row_index = 0; row_index < ARRAY_HEIGHT; ++row_index) {
		row_pointers[row_index] = Array2DS[row_index];
	}
	Zero2DDynamicArrray(row_pointers, ARRAY_HEIGHT, ARRAY_WIDTH);

	//Передача двумерного статического массива как одномерного
	Zero2DStaticArrayUniversal((int*)Array2DS, ARRAY_HEIGHT, ARRAY_WIDTH);

	//Объявление и обнуление трехмерного статического массива
	int Array3DS[ARRAY_HEIGHT][ARRAY_WIDTH][ARRAY_DEPTH];
	Zero3DStaticArray((int*)Array3DS, ARRAY_HEIGHT, ARRAY_WIDTH, ARRAY_DEPTH);

	//Объявление и обнуление трехмерного динамического массива
	int my_3d_height = 2;
	int my_3d_width = 3;
	int my_3d_depth = 4;
	int*** Array3DD;
	Array3DD = AllocateMemory3DArray(my_3d_height, my_3d_width, my_3d_depth);
	Zero3DDynamicArray(Array3DD, my_3d_height, my_3d_width, my_3d_depth);
	FreeMemory3DArray(Array3DD, my_3d_height, my_3d_width, my_3d_depth);

	//6 Задание:
	Array3DD = AllocateLargeMemoryBlockFor3DArray(my_3d_height, my_3d_width, my_3d_depth);
	Zero3DDynamicArray(Array3DD, my_3d_height, my_3d_width, my_3d_depth);
	FreeLargeMemoryBlockFor3DArray(Array3DD, my_3d_height, my_3d_width, my_3d_depth);
	Array3DD = AllocateLargeMemoryBlockFor3DArray(my_3d_height, my_3d_width, my_3d_depth);
	Zero3DStaticArray(&Array3DD[0][0][0], my_3d_height, my_3d_width, my_3d_depth);
	FreeLargeMemoryBlockFor3DArray(Array3DD, my_3d_height, my_3d_width, my_3d_depth);

	//7 Задание:
	Array3DD = AllocateDataAndFirstLevelPointersMemoryBlocksFor3DArray(my_3d_height, my_3d_width, my_3d_depth);
	Zero3DDynamicArray(Array3DD, my_3d_height, my_3d_width, my_3d_depth);
	FreeDataAndFirstLevelPointersMemoryBlocksFor3DArray(Array3DD, my_3d_height, my_3d_width, my_3d_depth);
	Array3DD = AllocateDataAndFirstLevelPointersMemoryBlocksFor3DArray(my_3d_height, my_3d_width, my_3d_depth);
	Zero3DStaticArray(&Array3DD[0][0][0], my_3d_height, my_3d_width, my_3d_depth);
	FreeDataAndFirstLevelPointersMemoryBlocksFor3DArray(Array3DD, my_3d_height, my_3d_width, my_3d_depth);
	return 0;
}
