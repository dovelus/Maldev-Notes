## Structures
Strucs are user defined data types that allow the programmer to group related data items of different data types into a single unit. Structs can be used to store data related to a particular object and make the easier to access and manipulate. Each item in a struct is called a "member" or "element", these term are interchangeable.

A common occurrence one will see when working with windows API is that some APIs require populated structure as input, while others will take a declared structs and populate it. Hers and example of the `THREADENTRY32` struct:

```c
typedef struct tagTHREADENTRY32 {
  DWORD dwSize; // Member 1
  DWORD cntUsage; // Member 2
  DWORD th32ThreadID;
  DWORD th32OwnerProcessID;
  LONG  tpBasePri;
  LONG  tpDeltaPri;
  DWORD dwFlags;
} THREADENTRY32; 
```

### Declaring a Struct
Structures used in this course are generally declared with the use of `typedef` keyword to give a structure an alias. For example, the structure below is created with the name `_STRUCTURE_NAME` but `typedef` adds two other names, `STRUCTURE_NAME` and `*PSTRUCTURE_NAME`.

```c
typedef struct _STRUCTURE_NAME {

  // structure elements

} STRUCTURE_NAME, *PSTRUCTURE_NAME;
```

The `STRUCTURE_NAME` alias refers to the structure name, whereas `PSTRUCTURE_NAME` represents a pointer to that structure. Microsoft generally uses the `P` prefix to indicate a pointer type.

### Initializing a Structure
Initializing a structure will vary depending on whether one is initializing the actual structure type or a pointer to the structure. Continuing the previous example, initializing a structure is the same when using `_STRUCTURE_NAME` or `STRUCTURE_NAME`, as shown below.

```c
STRUCTURE_NAME    struct1 = { 0 };  // The '{ 0 }' part, is used to initialize all the elements of struct1 to zero
// OR
struct _STRUCTURE_NAME   struct2 = { 0 };  // The '{ 0 }' part, is used to initialize all the elements of struct2 to zero
```

This is different when initializing the structure pointer, `PSTRUCTURE_NAME`.

```c
PSTRUCTURE_NAME structpointer = NULL;
```

Full code example:

```c
#include <Windows.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    CHAR name[20];
    UINT age;
} USER, *PUSER;

INT 
main(VOID)
{  
    USER user = {0};
    PUSER userpointer = &user;
    strcpy(user.name, "Dovelus");
    user.age = 15;
    
    printf("The user name is: %s \n", user.name);
    printf("The user age is: %i \n", user.age);
    
    printf("The same but using a pointer:\n\n");
    
    printf("The user name is: %s \n", userpointer->name);
    printf("The user age is: %i \n", userpointer->age);

    return ERROR_SUCCESS;

}
```

---

## Enumeration
The enum or enumeration data type is used to define a set of named constants. To create an enumeration, the `enum` keyword is used, followed by the name of the enumeration and a list of identifiers, each of which represents a named constant. The compiler automatically assigns values to the constants, starting with 0 and increasing by 1 for each subsequent constant. In this course, enums can be seen representing the state of specific data, error codes or return values.

An example of an enum is the list of "Weekdays" which contains 7 constants. In the example below, Monday has a value of 0, Tuesday has a value of 1, and so on. It's important to note that enum lists cannot be modified or accessed using the dot (.) operator. Instead, each element is accessed directly using its named constant value.
```c
#include <Windows.h>
#include <stdio.h>
#include <string.h>

enum Weekdays {
    Monday ,         // 0
    Tuesday,        // 1
    Wednesday,      // 2
    Thursday,       // 3
    Friday,         // 4
    Saturday,       // 5
    Sunday          // 6
  };

INT 
main (VOID){

    enum Weekdays EnumName = Tuesday;       // 4
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
```

Some time 