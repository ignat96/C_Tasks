#include <stdio.h>

/*
    Создать текстовый файл с записями следующего вида:
    
        Иванов Петр Сергеевич 1975
        Сидоров Николай Андреевич 1981
        …
        Воробьянинов Ипполит Матвеевич 1978

	Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года.

*/

int main()
{
    
    char row[128];
    
    FILE* txt_file  = fopen("Списки.txt", "rt");
    FILE* fltd_file = fopen("СпискиФильтрГода.txt", "w");

    while ((fgets(row, 128, txt_file)) != NULL) {

        int sepcount = 0; //счетчик пробелов в строке
        
        for (int i = 0; i < 128; i++) {

            if (sepcount == 3) {
                char sNum[4];
                int iNum = 0;
                for (int j = 0; j < 4; j++) {
                    sNum[j] = row[i];
                    i++;
                }
                iNum = atoi(sNum);

                if (iNum > 1980) {
                    fputs(row, fltd_file);
                }
                break;
            }

            if (row[i] == ' ')
                sepcount++;
        }
    }

    fclose(txt_file);
    fclose(fltd_file);

    return 0;
}

