#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MyFuncs.h"
/*******************************************************************************

Вариант 1.

Создать файл input.txt в который поместить 2 случайные квадратные матрицы, размера, заданного пользователем с консоли. 
Закрыть файл. Отчистить массивы.

Открыть input.txt файл и прочитать матрицы, произвести их перемножение и сложение (с помощью своих функций), 
вывести результат в файл output.txt.

Замерить время работы программы и вывести на экран.

*******************************************************************************/
int main() {

	// переменные точек времени
	clock_t start, end;
	
	//начало работы
	start = clock();

	// задаём мин. и макс. значение для ГСЧ
	int min = -20, max = 20;

	// инициализируем стартовое значение для ГСЧ
	srand(time(0));
    
    
    
	//--------------------------------------------------------
	//-----------------BEGIN OF MAIN BLOCK--------------------
    //--------------------------------------------------------
    
    
	// размер матрицы 
	printf("Введите размер матрицы: ");
	int mtx_size;
	scanf("%i", &mtx_size);

	// открываем файл для записи
	FILE* txt_file = fopen("input.txt", "w");

	//запишем размер матриц в конец файл
	fprintf(txt_file, "%i\n", mtx_size);

	//запись случайных значений первой матрицы в файл
	for (int i = 0, j = mtx_size - 1; i < (mtx_size * mtx_size); i++, j--)
	{
		int num = (rand() % (max - min + 1) + min);
		fprintf(txt_file, "%i ", num);
		if (j == 0) {
			fprintf(txt_file, "\n");
			j = mtx_size;
		}
	}

	//запись случайных значений второй матрицы в файл
	for (int i = 0, j = mtx_size - 1; i < (mtx_size * mtx_size); i++, j--)
	{
		int num = (rand() % (max - min + 1) + min);
		fprintf(txt_file, "%i ", num);
		if (j == 0) {
			fprintf(txt_file, "\n");
			j = mtx_size;
		}
	}

	//закрываем файл
	fclose(txt_file);
    
    /*********************************************************************
    
    Открыть input.txt файл и прочитать матрицы, произвести их перемножение и сложение (с помощью своих функций), 
    вывести результат в файл output.txt.
    
    **********************************************************************/
    
	//открываем файл для чтения
	txt_file = fopen("input.txt", "r");

	//считаем размер матрицц
	int m;
	fscanf(txt_file, "%i", &m);

	//////создаем массивы и выделяем под них память
	int **_M1, **_M2, **_MR;
	_M1 = (int**)malloc(m * sizeof(int*));
	_M2 = (int**)malloc(m * sizeof(int*));
	_MR = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		_M1[i] = (int*)malloc(m * sizeof(int));
		_M2[i] = (int*)malloc(m * sizeof(int));
		_MR[i] = (int*)malloc(m * sizeof(int));
	}

	char _row[128];
	int k= 0, i = 0, j = 0;
	//считываем значения в матрицы
	while (fgets(_row, 128, txt_file) != NULL) {
		if (k == 0) { //пропускаем строку с значением размера матриц
			k++;
			continue;
		}
		if (k == m+1) i = 0; //сбрасываем счетик при переходе на новую строку

		if (_row != "\0") {
			j = 0;//сбрасываем счетик при переходе к новому элементу строки
			char* ctdstr = strtok(_row, " "); 

			while (ctdstr != NULL) {
				if (k < m + 1) // условие для переключения на следующую матрицу
					_M1[i][j] = atoi(ctdstr);
				else
					_M2[i][j] = atoi(ctdstr);
				ctdstr = strtok(NULL, " ");
				j++;
			}
			i++;
		}
		k++;
	}

	fclose(txt_file);
    
    
    //открываем файл для дозаписи
	txt_file = fopen("input.txt", "a");
    
    //ВЫЧЕСЛЯЕМ И ЗАПИСЫВАЕМ В ФАЙЛ СУММУ МАТРИЦ
    fprintf(txt_file, "СУММА:\n");
	_MR = matrixSumDiff(_M1, _M2, '+', m, m, m);
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < m; j++) {
			fprintf(txt_file, "%i ", _MR[i][j]);
		}
		fprintf(txt_file, "\n");
	}
	fprintf(txt_file, "\n");
    
    
    //ВЫЧЕСЛЯЕМ И ЗАПИСЫВАЕМ В ФАЙЛ РАЗНОСТЬ МАТРИЦ
    fprintf(txt_file, "РАЗНИЦА:\n");
	_MR = matrixSumDiff(_M1, _M2, '-', m, m, m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++) {
			fprintf(txt_file, "%i ", _MR[i][j]);
		}
		fprintf(txt_file, "\n");
	}
	fprintf(txt_file, "\n");
    
    
    //ВЫЧЕСЛЯЕМ И ЗАПИСЫВАЕМ В ФАЙЛ ПРОИЗВЕДЕНИЕ МАТРИЦ
    fprintf(txt_file, "ПРОИЗВЕДЕНИЕ:\n");
	_MR = matrixSumDiff(_M1, _M2, '*', m, m, m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++) {
			fprintf(txt_file, "%i ", _MR[i][j]);
		}
		fprintf(txt_file, "\n");
	}
	fprintf(txt_file, "\n");

	fclose(txt_file);
	
	//--------------------------------------------------------
	//---------------END OF MAIN BLOCK------------------------
	//--------------------------------------------------------
    
    end = clock();
    
    printf("Program was executed in %.3f s", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}

	