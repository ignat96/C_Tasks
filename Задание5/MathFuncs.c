#include <stdlib.h>

double** matrixCalc(double** matrix_A, double** matrix_B, char operand, int m, int n, int k) {
	
	double **matrix_C;
	//найдем размеры матриц

	//выделяем память для вычесления результата
	matrix_C = (double**)malloc(m * sizeof(double*));
	for (int i = 0; i < m; i++)	{
		matrix_C[i] = (double*)malloc(k * sizeof(double));
	}

	//рассчет сложения/вычетания
	if (operand != '*') {
		//двигаемся по строкам матриц
		for (int i = 0; i < m; i++) {
			//двигаемся по элементам строки
			for (int j = 0; j < n; j++) {
				if (operand == '+')
					matrix_C[i][j] = (matrix_A[i][j] + matrix_B[i][j]);
				if (operand == '-')
					matrix_C[i][j] = (matrix_A[i][j] - matrix_B[i][j]);
			}
		}
	}
	//рассчет умножения
	else {
		for (int i = 0; i < m; i++) { //строки матрицы А
			for (int j = 0; j < n; j++) { //столбцы B
				double currVal = 0;
				for (int k = 0; k < n; k++) { //строки В и столбцы А
					currVal += (matrix_A[i][k]) * (matrix_B[k][j]);
				}
				matrix_C[i][j] = currVal;
			}
		}
	}

	return matrix_C;
}