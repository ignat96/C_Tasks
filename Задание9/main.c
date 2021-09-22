#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Реализовать программу-калькулятор с возможностью выполнения арифметических действий (+, -), унарный и бинарный вариант. 
У пользователя запрашивается выраже-ние, например, "-123,5 + 4 - 456+56", программа должна решить выражение. 
Для раз-бора входной строки использовать функцию strok.

*/

int main()
{
    //массив чисел
    char nums[50];

    printf("Введите выражение: ");
    fflush(stdin);
    fgets(nums, 128, stdin);

    char* cttr = strtok(nums, " ");
    double rslt = atof(cttr);
    
    do{
        if (strcmp(cttr,"+") == 0) { 
            cttr = strtok(NULL, " ");
            rslt += atof(cttr);
        }
        else if (strcmp(cttr,"-") == 0) { 
            cttr = strtok(NULL, " ");
            rslt -= atof(cttr);
        }
        cttr = strtok(NULL, " ");
        //printf("%.3lf ", rslt);
    }while(cttr);

    printf("Результат: %lf", rslt);
    
    return 0;
}