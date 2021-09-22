#include <stdio.h>
#include <time.h>
#include <string.h>

/*

Написать программу-календарь. Пользователь может указать даты в формате:
	- гггг.мм.дд – программа вычисляет день недели соответствующий данной дате;
	- гггг.мм – программа выводит календарь за данный месяц;
	- гггг – календарь за год;
	- now – текущую дату.

*/


char* months[]={"Январь","Февраль","Март","Апрель","Май","Июнь","Июль","Август","Сентябрь","Октябрь","Ноябрь","Декабрь"};
char* days[]={"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
int daysCounts[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


// Прототипы
int getDayOfWeek(int _year, int _month, int _day);
int printMonths(int countOfMths);
int printMonth(int _year, int _mth);

int main(){
    
    char _formatStr[32];
    int _flag = 1;
    while(_flag != 0) {
        printf("Для вывода инфорации введите команду в одном из следующих форматов:\n> гггг.мм.дд \n> гггг.мм \n> гггг\n> ");
        scanf("%s", _formatStr);
        
        int idx = 0, cnt = 0;
        while(_formatStr[idx] != '\0'){
            idx++;
            if (_formatStr[idx] == '.') { cnt++; }
        }
        
        
        int _year = atoi(strtok(_formatStr, "."));
        /*
            В конце 1582 года папа Григорий XIII ввёл в католических странах календарь, 
            котором год высокосный, если он кратный 4, но не кратный 100 или кратный 400.
        */
        if ( ((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0) ){
            daysCounts[1] = 29;
        } 
        
        if (cnt > 1) {
            int _month = atoi(strtok(NULL, "."));
            int _day = atoi(strtok(NULL, "."));
            int wday = getDayOfWeek(_year, _month, _day);
            printf("Введенная дата соответствует: %s\n", days[wday]);
        }
        else if (cnt == 1) {
            int _month = atoi(strtok(NULL, "."));
            printMonth(_year, _month);
        }
        else{
            printMonths(_year);
        }
        printf("\nПродолжить? 1 - ДА  0 - НЕТ\n");
        scanf("%d", &_flag);
        fflush(stdin);
    }
    //printf("The day of the week is %d", datetime.tm_hour);
    return 0;
}



// Реализация функций
int getDayOfWeek(int _year, int _month, int _day){
    struct tm datetime;
    
    datetime.tm_hour = 0;
    datetime.tm_min = 0;
    datetime.tm_sec = 0;
    datetime.tm_isdst = -1;
    datetime.tm_year = _year - 1900;
    datetime.tm_mon = _month - 1;
    datetime.tm_mday = _day;
    
    mktime(&datetime);
    if (datetime.tm_wday == 0) {
        return 6;
    }
    return datetime.tm_wday - 1;
}


int printMonths(int _year){
    for(int mth = 0; mth < 12; mth++){
        int daysInMth = daysCounts[mth];
        int frstDay = getDayOfWeek(_year, mth + 1, 1);
        printf("\n\n---------------- %s ----------------\n", months[mth]);
        
        int wkds;
        for(wkds = 0; wkds < 7; wkds++) {
            printf("   %s", days[wkds]);    
        }
        printf("\n");
        for(wkds = 0; wkds < frstDay; wkds++){
            printf("     ");
        }
        
        for(int day = 1; day <= daysInMth; day++){
            printf("%5d", day);
            if (++wkds > 6) {
                printf("\n");
                wkds = 0;
            }
            
        }
    }
}

int printMonth(int _year, int _mth){
    int daysInMth = daysCounts[_mth - 1];
    int frstDay = getDayOfWeek(_year, _mth, 1);
    printf("\n\n---------------- %s ----------------\n", months[_mth - 1]);
    
    int wkds;
    for(wkds = 0; wkds < 7; wkds++) {
        printf("   %s", days[wkds]);    
    }
    printf("\n");
    for(wkds = 0; wkds < frstDay; wkds++){
        printf("     ");
    }
    
    for(int day = 1; day <= daysInMth; day++){
        printf("%5d", day);
        if (++wkds > 6) {
            printf("\n");
            wkds = 0;
        }
        
    }
}