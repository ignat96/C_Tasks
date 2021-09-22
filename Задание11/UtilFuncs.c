#include <stdarg.h>
int sum(int n, ...){
    int result = 0;
    va_list smmtr;
    
    va_start(smmtr, n);    // устанавливаем указатель
    
    for(int i = 0; i < n; i++)
    {
        result += va_arg(smmtr, int);  // получаем значение текущего параметра типа int
    }
    va_end(smmtr); // завершаем обработку параметров
    return result;
}

int min(int n, ...){
    int result = 0, _num = 0;
    va_list smmtr;
    
    va_start(smmtr, n);
    
    for(int i = 0; i < n; i++)
    {
        _num = va_arg(smmtr, int);
        if (_num < result) {
            result = _num;
        }
    }
    
    va_end(smmtr);
    return result;
}

int max(int n, ...){
    int result = 0, _num = 0;
    va_list smmtr;
    
    va_start(smmtr, n);
    
    for(int i = 0; i < n; i++)
    {
        _num = va_arg(smmtr, int);
        if (_num > result) {
            result = _num;
        }
    }
    
    va_end(smmtr);
    return result;
}

double mean(int n, ...){
    int mid_result = 0;
    va_list smmtr;
    
    va_start(smmtr, n);
    
    for(int i = 0; i < n; i++)
    {
        mid_result += va_arg(smmtr, int);
    }
    
    va_end(smmtr);
    double result = (double)mid_result / (double)n;
    return result; 
}