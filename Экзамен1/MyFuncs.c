#include <stdlib.h>
#include <stdio.h>

int** matrixSumDiff(int** matrix_A, int** matrix_B, char operand, int m, int n, int k) {

	int** matrix_C;


	matrix_C = (int**)calloc(m, sizeof(int*));
	for (int i = 0; i < m; i++) {
		matrix_C[i] = (int*)calloc(k, sizeof(int));
	}

	if (operand != '*') {

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (operand == '+')
					matrix_C[i][j] = (matrix_A[i][j] + matrix_B[i][j]);
				if (operand == '-')
					matrix_C[i][j] = (matrix_A[i][j] - matrix_B[i][j]);
			}
		}
	}

	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int currVal = 0;
				for (int k = 0; k < n; k++) {
					currVal += (matrix_A[i][k]) * (matrix_B[k][j]);
				}
				matrix_C[i][j] = currVal;
			}
		}
	}

	return matrix_C;
}