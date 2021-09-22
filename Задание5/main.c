#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MathFuncs.h"

int main()
{
    int flag = 1;
    do
    {        
        int _op = 0; // тип операции: 1 - все, 2 - только умножение, 0 - ничего(по умолчанию)
        int m1, m2, n1, n2; // размеры матриц
        double **_A, **_B; // вводимые матрицы А и В. 
        double **_C; // результирующая матрица С
        double vNum; // вводдимые числа
        

       

        printf("\nВведите размер 1ой матрицы (строка столбец): ");
        scanf("%i %i", &m1, &n1);

        printf("Введите размер 2ой матрицы (строка столбец): ");
        scanf("%i %i", &m2, &n2);

        if ((m1 == m2) && (n1 == n2)) {
            _op = 1;
        }
        else if (n1 == m2) {
            _op = 2;
        }
        
        
        // Выполняем ввод значений
        // и действия над матрицам
        // => только если действияствия возможны
        if (_op != 0) {
            
            //----------------Выделяем память----------------
            _A = (double**)malloc(m1 * sizeof(double*));
            for (int i = 0; i < m1; i++)
                _A[i] = (double*)malloc(n1 * sizeof(double));

            _B = (double**)malloc(m2 * sizeof(double*));
            for (int i = 0; i < m2; i++)
                _B[i] = (double*)malloc(n2 * sizeof(double));

            _C = (double**)malloc(m1 * sizeof(double*));
            for (int i = 0; i < m1; i++)
                _C[i] = (double*)malloc(n2 * sizeof(double));
            //-----------------------------------------------
            
            
            //Ввод данных
            printf("Введите значения матриц\n");
            printf("<<Матрица А>>\n");
            //перемещаемся по строкам
            for (int i = 0; i < m1; i++) {
                printf(" <Строка %i>\n", i + 1);
                // вводим значения для каждого элемента строки
                for (int j = 0; j < n1; j++) {
                    printf("   A[%i][%i] = ", (i + 1), (j + 1));
                    scanf("%lf", &vNum);
                    _A[i][j] = vNum;
                }
            }
            
            printf("\n<<Матрица B>>\n");
            for (int i = 0; i < m2; i++) {
                printf(" <Cтрока %i>\n", i + 1);
                for (int j = 0; j < n2; j++) {
                    printf("   B[%i][%i] = ", (i + 1), (j + 1));
                    scanf("%lf", &vNum);
                    _B[i][j] = vNum;
                }
            }
            
            printf("\n <<<РЕЗУЛЬТАТЫ>>> \n");
            
            printf(" <Умножение> \n");
            _C = matrixCalc(_A, _B, '*', m1, n1, n2);

            for (int i = 0; i < m1; i++) {
                for (int j = 0; j < n2; j++) {
                    printf(" %.2lf\t", _C[i][j]);
                }
                printf("\n");
            }
            
            if (_op == 1) {
                printf("\n <Вычетание> \n");
                _C = matrixCalc(_A, _B, '-', m1, n1, n2);

                for (int i = 0; i < m1; i++) {
                    for (int j = 0; j < n2; j++) {
                        printf("%.2lf\t", _C[i][j]);
                    }
                    printf("\n");
                }
                
                printf("\n <Сложение> \n");
                _C = matrixCalc(_A, _B, '+', m1, n1, n2);

                for (int i = 0; i < m1; i++) {
                    for (int j = 0; j < n2; j++) {
                        printf("%.2lf\t", _C[i][j]);
                    }
                    printf("\n");
                }
            }

            //--------------Чистка памяти---------------
            for (int i = 0; i < m1; i++)
                free(_A[i]);
            free(_A);

            for (int i = 0; i < m2; i++)
                free(_B[i]);
            free(_B);
            //------------------------------------------

            printf("\nПродолжить? (да - 1/нет - 0)\n");
            scanf("%i", &flag);

            //--------------Дочистка памяти---------------
            for (int i = 0; i < m1; i++)
                free(_C[i]);
            free(_C);
            //------------------------------------------
        }
        if (flag != 1) {
            printf("\nПродолжить? (да - 1/нет - 0)\n");
            scanf("%i", &flag);
        }
    } while (flag == 1);


    return 0;
}
