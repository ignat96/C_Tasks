#include <stdio.h>
#include "UtilFuncs.h"

/*

Создать в отдельном модуле функции с переменным количеством аргументов, 
которая вычисляет их сумму, максимум, минимум, среднее арифметическое.

*/

int main()
{
    
    printf("Для ряда чисел: \n");
    printf("7, 5, 1, 15, -24, 19, 4, -9, 5\n");
    printf("------------------------------\n");
    
    printf("Сумма: %d \n", sum(9, 7, 5, 1, 15, -24, 19, 4, -9, 5));
    printf("Минимум: %d \n", min(9, 7, 5, 1, 15, -24, 19, 4, -9, 5));
    printf("Максимум: %d \n", max(9, 7, 5, 1, 15, -24, 19, 4, -9, 5));
    printf("Среднее: %.3lf \n", mean(9, 7, 5, 1, 15, -24, 19, 4, -9, 5));
    return 0;
}
