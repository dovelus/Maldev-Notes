#include <Windows.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    CHAR name[20];
    UINT age;
} USER, *PUSER; 

INT main(VOID)
{   
    USER user = {0};
    PUSER userpointer = &user;
    strcpy(user.name, "Youness");
    user.age = 15;

    printf("The user name is: %s \n", user.name);
    printf("The user age is: %i \n", user.age);

    printf("The same but using a pointer:\n\n");

    printf("The user name is: %s \n", userpointer->name);
    printf("The user age is: %i \n", userpointer->age);

    return ERROR_SUCCESS;
}