#include <stdio.h>
#include <math.h>

/*
    Объявить вещественные переменные a, b и с и задать их значения. 
    Предполагая, что a, b, c есть коэффициенты квадратного уравнения вывести на консоль значения  их корней х1, х2. 
    Следует подобрать такие значения коэффициентов, при которых корни бу-дут существовать.
*/

int main()
{
    double a=4, b=5, c=6; // коэф-енты ур-я
    double dis, x1, x2;
    printf("Введите коэфииценты a b c:\n"); 
    

    if (dis < 0) { printf("Корней нет."); }
    else if (dis == 0) { 
        x1 = -1 * (b / (2 * a)); 
        printf("X1 = %lf\n", x1); 
    }
    else if (dis > 0)
    {
        x1 = (-b + sqrt(dis)) / (2 * a); printf("X1 = %lf;\n", x1);
        x2 = (-b - sqrt(dis)) / (2 * a); printf("X2 = %lf;\n", x2);
    }  

    return 0;
}