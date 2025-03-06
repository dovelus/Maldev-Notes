#include <Windows.h>
#include <stdio.h>
#include <string.h>

enum Weekdays {
    Monday = 1,         // 1
    Tuesday,        // 2
    Wednesday,      // 3
    Thursday,       // 4
    Friday,         // 5
    Saturday,       // 6
    Sunday          // 7
  };

INT main (VOID){

    enum Weekdays EnumName = Tuesday;       // 4
    printf("Val: %i\n", EnumName);
    // Check the value of "EnumName"
    switch (EnumName){
        case Monday:
            printf("Today Is Monday !\n");
            break;
        case Tuesday:
            printf("Today Is Tuesday !\n");
            break;
        case Wednesday:
            printf("Today Is Wednesday !\n");
            break;
        case Thursday:
            printf("Today Is Thursday !\n");
            break;
        case Friday:
            printf("Today Is Friday !\n");
            break;
        case Saturday:
            printf("Today Is Saturday !\n");
            break;
        case Sunday:
            printf("Today Is Sunday !\n");
            break;
        default:
        break;
    }

    return ERROR_SUCCESS;
}