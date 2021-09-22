#include <stdio.h>
#include <stdlib.h>

/*

    Создать текстовый файл с записями, включающие имя/фамилию человека, год рожде-ния, пол и рост (в метрах). 
    Упорядочить элементы по году рождения, имени/фамилии, полу или росту. 
    Вывести результат. Указать элемент, по которому следует упорядо-чить, через консоль. 
    А также реализовать возможность задавать несколько полей для упорядочивания.

*/


struct Person {
    char name[25];
    char sername[25];
    char thrdname[25];
    int birthyear;
    char gender;
    double growth;
};


char flts[6]; //фильтр условий

//функция форматированного вывода списка структур
void printbd(struct Person* p_list, int* p_length);

//проверка на вхождение символа в заданную строку
int containsChar(char* _formatStr, char chr);

//компаратор условий
int compare(const void *a, const void *b);



int main() {
    
    struct Person* peoples;

    FILE* database = fopen("BD.txt", "rt");

    int rwcnt = -1; int rslt = 6;
    peoples = malloc(1 * sizeof(*peoples));

    do{
        rwcnt++;
        peoples = realloc(peoples, (rwcnt + 1) * sizeof(struct Person));
        
        rslt = fscanf(database, "%s %s %s %i %c %lf", 
            (peoples + rwcnt)->name,
            (peoples + rwcnt)->thrdname,
            (peoples + rwcnt)->sername,
            &(peoples + rwcnt)->birthyear,
            &(peoples + rwcnt)->gender,
            &(peoples + rwcnt)->growth
        );
    }while (rslt == 6);
    
    fclose(database);
    printbd(peoples, &rwcnt);
    
    int flag = 1;

    do
    {
        printf("\n\nДля сортировки перечислите имена фильтров в строку без пробелов.\n");
        printf("*            ФИЛЬТРЫ          *\n");
        printf("* <---  s - фамилия      ---> *\n");
        printf("* <---  n - имя          ---> *\n");
        printf("* <---  p - отчество     ---> *\n");
        printf("* <---  b - год рождения ---> *\n");
        printf("* <---  g - пол          ---> *\n");
        printf("* <---  h - рост         ---> *\n\n");
        printf("[ВВОД]: ");
        scanf("%s", &flts);
        //sort_op(flts, people, &rwcnt);
        
        qsort(peoples, rwcnt, sizeof(struct Person), compare);
        
        printbd(peoples, &rwcnt);
        printf("\nПродолжить :( да -  1/ нет - 0)\n");
        scanf("%i", &flag);

    } while (flag == 1);

    free(peoples);

    return 0;
}



/// ВСПОМ. ФУНКЦИИ

void printbd(struct Person* p_list, int* p_length) {
    printf("| #  |\tИмя \t|\tОтчество \t|\tФамилия \t| Год рождения | Пол | Рост |\n");
    for (int i = 0; i < *(p_length); i++) {
        printf("|%4i| %-14s\t %-20s\t %-16s\t %-8i %-3c %.2lf \n",
            (i + 1),
            (p_list + i)->name,
            (p_list + i)->thrdname,
            (p_list + i)->sername,
            (p_list + i)->birthyear,
            (p_list + i)->gender,
            (p_list + i)->growth
        );
    }
}

int compare(const void *a, const void *b) {

    const struct Person *x = a;
    const struct Person *y = b;
    int comp = 0;
    
    //порядок фильтраци полей установлен в соответствии с приоритетом         
    
    //пол
    if (containsChar(flts, 'g') == 1) {
        comp =  x->gender - y->gender;
        if (comp > 0) { return 1; } if (comp < 0) { return -1; }
    }
    
    //рост
    if (containsChar(flts, 'h') == 1) {
        comp =  (x->growth / 0.01) - (y->growth / 0.01);
        if (comp < 0) { return 1; } if (comp > 0) { return -1; }
    }
    
    //день рождения
    if (containsChar(flts, 'b') == 1) {
        comp =  x->birthyear - y->birthyear;
        if (comp < 0) { return 1; } if (comp > 0) { return -1; }
    }
    
    //отчество
    if (containsChar(flts, 'p') == 1) {
        comp =  x->thrdname[0] - y->thrdname[0];
        if (comp > 0) { return 1; } if (comp < 0) { return -1; }
    }
    
    //имя
    if (containsChar(flts, 'n') == 1) {
        comp =  x->name[0] - y->name[0];
        if (comp > 0) { return 1; } if (comp < 0) { return -1; }
    }
    
    //фамилия
    if (containsChar(flts, 's') == 1) {
        comp =  x->sername[0] - y->sername[0];
        if (comp > 0) { return 1; } if (comp < 0) { return -1; }
    }
    
    return comp;
}

int containsChar(char* _formatStr, char chr) {
    
    int i = 0;
    while(_formatStr[i] != '\0'){
        if (_formatStr[i] == chr)
            return 1;
        i++;
    }
    return 0;
}

