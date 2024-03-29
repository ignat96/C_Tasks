/******************************************************************************

Вариант 2.

Создать файл input.txt в который поместить  N случайных чисел, размера, заданного пользователем с консоли. 
N- это размер вектора. Отчистить массивы. Закрыть файл.

1)Открыть input.txt файл и прочитать значения, все числа которые делятся на 5 заменить на слово «ПЯТЬ», на 7 на слово «СЕМЬ». 
А которые делятся на 7 и 5 на слово «ПЯТЬСЕМЬ». вывести результат в файл output.txt.

2)Из фала input.txt сформировать матрицу путем преобразования вектора N в M столбцов 
(лишние цифры не брать, если не получается квадратная матрица). 
Посчитать сумму строк и столбцов. Вывести матрицу на экран и результаты сложения.

Замерить время работы программы и вывести на экран.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main()
{
    // переменные точек времени
    clock_t start, end;
	
	//начало работы
	start = clock();
	
    //переменная задаваемого вектора
    int N = 0;
    
    //seed для ГСЧ
    srand(time(0));
    
    printf("Введите размер вектора:\n");
    scanf("%i", &N);
    printf("\n");
    
    FILE* input = fopen("input.txt", "w"); // файл для исходных данных
    
    int* nums = (int*)malloc(N * sizeof(int));
    
    // генерация чисел с последующей записью в файл
    for (int i = 0; i < N; i++)
    {
        nums[i] = rand() % 99;
        fprintf(input, "%i", nums[i]);
        //записываем пробел в качестве разделителя
        if (i != N - 1)
            fprintf(input, " ");
    }
    
    fclose(input); //закрываем файл для записи
    
    free(nums); //чистим массив
    
    
    /*********************************************************************
    
    1)Открыть input.txt файл и прочитать значения, все числа которые делятся на 5 заменить на слово «ПЯТЬ», на 7 на слово «СЕМЬ». 
    А которые делятся на 7 и 5 на слово «ПЯТЬСЕМЬ». вывести результат в файл output.txt.
    
    *********************************************************************/
    
    
    input = fopen("input.txt", "r"); // файл с исходными данными
    FILE* output = fopen("output.txt", "w"); // файл с результатом
    
    char r[128];
    
    fgets(r, 128, input); // считаем сроку значений из файла input.txt
    char* cstr = strtok(r, " ");
    while(cstr != NULL) {
        
        //проверяем каждое число по условию
        if ((atoi(cstr) % 7 == 0) && (atoi(cstr) % 5 == 0)) {
            fprintf(output, " ПЯТЬСЕМЬ");
        }
        else if (atoi(cstr) % 7 == 0) {
            fprintf(output, " СЕМЬ");
        }
        else if (atoi(cstr) % 5 == 0) {
            fprintf(output, " ПЯТЬ");
        }
        else {
            fprintf(output, " %s", cstr);
        }
        
        cstr = strtok(NULL, " ");
    }
    
    fclose(output);
    fclose(input);
    
    
    /*********************************************************************
    
    2)Из фала input.txt сформировать матрицу путем преобразования вектора N в M столбцов 
    (лишние цифры не брать, если не получается квадратная матрица). 
    Посчитать сумму строк и столбцов. Вывести матрицу на экран и результаты сложения.
    
    *********************************************************************/
    
    //рассчет размера матрицы
    int sz;
    for(int i = N; i > 0; i--) {
        double sq = sqrt(i);
        if ((sq - (int)sq) == 0) { 
            sz = (int)sqrt(i);
            break;
        }
    }
    
    input = fopen("input.txt", "r"); 
    fgets(r, 128, input); // считаем строку значений из файла input.txt
    cstr = strtok(r, " ");
    
    //выделим память под массив
    int** _nums = (int**)malloc(sz * sizeof(int*));
    for(int i = 0; i < sz; i++)
        _nums[i] = (int*)malloc(sz * sizeof(int));
    
    //запишем значения в матрицу (массив)
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            _nums[i][j] = atoi(cstr);
            cstr = strtok(NULL, " ");
        }
    }

    //выведем полученную матрицу
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            printf("%i ", _nums[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    //выведем результаты сумм строк и столбцов
    for (int i = 0; i < sz; i++) {
        int sum_r = 0, sum_c = 0;
        for (int j = 0; j < sz; j++) {
            sum_r += _nums[i][j];
            sum_c += _nums[j][i];
        }
        printf("Сумма строки %i: %i \n", i + 1, sum_r);
        printf("Сумма столбца %i: %i \n", i + 1, sum_c);
    }
    
    end = clock();
    
    printf("Program was executed in %.3f s", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
