#include <iostream>
using namespace std;

/*Составить программу, которая в каждой строке матрицы D(m, n), m≤10,
n≤12, находит элемент, для которого модуль разности этого элемента и
среднего геометрического модулей всех элементов строки максимален.
Предполагается, что матрица нулевых элементов не содержит.Вывести
матрицу в виде матрицы, располагая рядом с каждой строкой найденный
элемент и модуль искомой разности.*/

int main(){
	int n, m;
	double candidate_magm;
	cin >> m >> n;

	int **matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
	//среднее геометрическое n чисел равно корню n-ной степени из их произведения
	int iter = 0;

	double magm_array[1000];
	double magm_val_array[1000];

	for (int i = 0; i < m; i++) {

		double multip = 1;
		double max_abs_geom_mean = 1.;
		double magm_val = 1.;
		for (int j = 0; j < n; j++) {multip *= matrix[i][j];}

		for (int g = 0; g < n; g++) {
			candidate_magm = abs( (double)matrix[i][g] - (double)pow(multip, (1/(double)n)));
			//cout<< "mult "<< multip << " " << matrix[i][g] << "-" << pow(multip,(1/(double)n)) << "=" << candidate_magm << "\n";
			if (candidate_magm > max_abs_geom_mean ) {
				max_abs_geom_mean = candidate_magm;
				magm_val = matrix[i][g];
			}
		}
		magm_array[iter] = max_abs_geom_mean;
		magm_val_array[iter] = magm_val;
		iter += 1;
		//cout << "max_abs_geom_mean: " << max_abs_geom_mean << " magm_val: " << magm_val << "\n";
	} 
	cout << "\n";
	int iter_1 = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout<< " | Absolute diffrence: " << magm_array[iter_1]<< " | "<< " Value when absolute diffrence is max: " << magm_val_array[iter_1];
		cout << "\n";
		iter_1 += 1;
	}

	for (int i = 0; i < m; i++) delete[] matrix[i];
	delete[] matrix;
}