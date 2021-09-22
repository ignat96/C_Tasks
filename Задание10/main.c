#include <stdio.h>
#include <string.h>

#define MAX_VAL(_array_size, _array) { \
	int max_num = 0;\
	for (int i = 0; i < _array_size; i++) { \
		if (_array[i] > max_num) { max_num = _array[i]; } \
	} \
	printf("Maximum: %i", max_num);\
}

int main()
{
        int flag = 1;
    do
    {
        printf("Введите до 50 любых целых цифр через пробел: \n");
        char _str_nums[100];
        char* cttr;
        int _nums[50];
        int idx = 0;
        //ввод значений
        fflush(stdin); //отчистим буфер
        fgets(_str_nums, 126, stdin);

        cttr = strtok(_str_nums, " ");
        
        while (cttr != NULL){
            _nums[idx] = atoi(cttr);
            cttr = strtok(NULL, " ");
            idx++;
        }
		
		MAX_VAL(idx, _nums);

        printf("\nПродолжить? (да - 1/нет - 0)\n");
        scanf("%i", &flag);

    } while (flag == 1);

    return 0;
}
