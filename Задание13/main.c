#include <stdio.h>
#include <signal.h>
/*

Написать программу, обрабатывающую получение сигналов (SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM). 
Также программа, может возбуждать эти сигна-лы по указанию пользователя. 
В качестве обработчика должно быть реализовано логи-рование (вывод на консоль).

*/

//ОБРАБОТЧИКИ СИГНАЛОВ
void SIG_LISTENER(int sig){
    char* _err_desc;
    
    switch(sig){
        case 2:
            _err_desc = "прерывание";
            break;
        case 4:
            _err_desc = "недопустимая инструкция";
            break;
        case 6:
            _err_desc = "остановка";
            break;
        case 8:
            _err_desc = "исключение с плавающей точкой";
            break;
        case 11:
            _err_desc = "нарушение сегментации";
            break;
        case 15:
            _err_desc = "завершение работы";
            break;
    }
    printf("|-------------------------------------------------|\n");
    printf("|КОД СИГНАЛА: %-35i |\n|ОПИСАНИЕ: %-48s|\n", sig, _err_desc);
    printf("|-------------------------------------------------|\n");
}



int main()
{
    printf("<<<ОБРАБОТКА СИГНАЛОВ>>>");
    int chd_sig = 1;
    
    signal(SIGABRT, SIG_LISTENER);   
    signal(SIGFPE, SIG_LISTENER);    
    signal(SIGILL, SIG_LISTENER);  
    signal(SIGINT, SIG_LISTENER);   
    signal(SIGSEGV, SIG_LISTENER);    
    signal(SIGTERM, SIG_LISTENER);   


    while(chd_sig != 0){
        printf("\nДля возбуждения сигналов укажите его номер:");
        printf("\n 1 - SIGABRT");
        printf("\n 2 - SIGFPE");
        printf("\n 3 - SIGILL");
        printf("\n 4 - SIGINT");
        printf("\n 5 - SIGSEGV");
        printf("\n 6 - SIGTERM\n");

        scanf("%d", &chd_sig);
        
        switch(chd_sig){
            case 1:
                raise(SIGABRT);
                break;
            case 2:
                raise(SIGFPE);
                break;
            case 3:
                raise(SIGILL);
                break;
            case 4:
                raise(SIGINT);
                break;
            case 5:
                raise(SIGSEGV);
                break;
            case 6:
                raise(SIGTERM);
                break;
        }
        
        printf("\n0 - выход из программы; Продолжить любая другая цифра\n\n");
        scanf("%d", &chd_sig);
        if (chd_sig == 0) { return 0; }
    }
    return 0;
}