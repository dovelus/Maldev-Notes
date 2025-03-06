#include <Windows.h>
#include <stdio.h>
#include <string.h>

union ExampleUnion {
    INT    IntegerVar;
    CHAR   CharVar[20];
    FLOAT  FloatVar;
 };


INT 
main (VOID){
    
    union ExampleUnion test;

    test.IntegerVar = 10;
    printf("IntegerVar: %i\n", test.IntegerVar);

    SIZE_T size = sizeof(test.IntegerVar);
    printf("Size of integer: %i\n", size);

    strcpy(test.CharVar, "Hello World");

    printf("CharVar: %s\n", test.CharVar);

    size = sizeof(test.CharVar);
    printf("Size of CharVar: %i\n", size);

    test.FloatVar = 3.14;

    printf("FloatVar: %f\n", test.FloatVar);

    size = sizeof(test.FloatVar);
    printf("Size of FloatVar: %i\n", size);

    return ERROR_SUCCESS;
}