#include <stdio.h>

/*
    Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. 
    Объявить два массива из четырёх элементов типа humen. 
    Ввести с консоли или из фай-ла элементы одного массива и построить на их основе другой, 
    упорядочив элементы по годам рождения. Вывести результат.
*/

struct Human {
    char name[25];
    char sername[25];
    int birthyear;
};

int main()
{
    struct Human people[4];
    struct Human fltdPeople[4];

    //ввод данных структуры people
    for (int i = 0; i < 4; i++) {
        printf("********\n** #%i **\n********\n", (i + 1));
        printf("Введите имя:");
        scanf("%s", &people[i].name, 25);
        printf("Введите фамилию:");
        scanf("%s", &people[i].sername, 25);
        printf("Введите год рождения:");
        scanf("%i", &people[i].birthyear);
    }

    //создадим массив отфильтрованный по году рождения
    int ind = 0, ind_ = 0;
    for (int i = 0; i < 4; i++) {
        int by = 0;
        for (int j = 0; j < 4; j++)
        { //1 - найдем последний максимальный элемент
            if (i == 0) {
                if (people[j].birthyear >= by) {
                    by = people[j].birthyear;
                    ind = j;
                }
            } //2 - найдем повторы если таковые есть, или перейдем к элементу меньше макс.
            else if (((people[j].birthyear == fltdPeople[i - 1].birthyear) && (j < ind_)) || 
                    ((people[j].birthyear >= by) && (people[j].birthyear < fltdPeople[i - 1].birthyear))
                    )  
            {
                 by = people[j].birthyear;
                 ind = j;
            }
        }
        fltdPeople[i] = people[ind];
        ind_ = ind;
    }

    for (int i = 0; i < 4; i++) {
        printf("\n\n********\n** #%i **\n********\n", (i + 1));
        printf("Имя: %s\nФамилия: %s\nГод рождения: %i", fltdPeople[i].name, fltdPeople[i].sername, fltdPeople[i].birthyear);
    }

    return 0;
}
