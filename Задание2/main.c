#include <stdio.h>

/*
    Объявить массив данных типа double размером 3 на 3. 
    Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной диагонали и сумму элементов, 
    расположенных на  побочной диагонали.
    
	Объявить массив данных типа int размером 2 на 2. Ввести с консоли его значе-ния, 
	вывести на консоль квадрат данной матрицы.

*/

int main()
{
    //объявления
    double A3[3][3], sum_mdiag = 0, sum_sdiag = 0;
   
    //матрица 3х3
    printf("Введите матрицу 3х3 построчно\n");
    
    for (int i = 0, j = 2; i < 3; i++, j--)
    {
        scanf("%lf %lf %lf", &A3[i][0], &A3[i][1], &A3[i][2]);
        sum_mdiag += A3[i][i];
        sum_sdiag += A3[i][j];
    }

    printf("\n--------\n");
    printf("Гл.диагональ: %lf; \nПоб.диагональ: %lf\n\n", sum_mdiag, sum_sdiag);
    
    int A2[2][2], B[2][2], i, j, k;

    //матрица 2х2
    printf("Введите матрицу A 2х2 построчно\n");

    //ввод матрицы
    for (i = 0; i < 2; i++)
    {
        scanf("%i %i", &A2[i][0], &A2[i][1]);
    }


    //возведение в квадрат
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            B[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                B[i][j] += + A2[i][k] * A2[k][j]; 
            }
        }
    }

    printf("\n--------\nМатрица А в квадрате:\n");

    for (int i = 0; i < 2; i++)
    {
        printf("%i %i\n", B[i][0], B[i][1]);
    }
    return 0;
}
