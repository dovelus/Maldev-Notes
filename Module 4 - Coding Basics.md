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

Some time we want that the enumeration starts from a precise  number to do so we can just initialize the first value with the start value of the Enum:

```c
enum Weekdays {
    Monday = 1,         // 1 This will start from 1 not 0
    Tuesday,        // 2
    Wednesday,      // 3
    Thursday,       // 4
    Friday,         // 5
    Saturday,       // 6
    Sunday          // 7
  };
```

## Union

In the C programming language, a [Union](https://learn.microsoft.com/en-us/cpp/cpp/unions?view=msvc-170) is a data type that permits the storage of various data types in the same memory location. Unions provide an efficient way to use a single memory location for multiple purposes. Unions are not commonly used but can be seen in Windows-defined structures. The code below illustrates how to define a union in C:

```c
union ExampleUnion {
   int    IntegerVar;
   char   CharVar;
   float  FloatVar;
};
```

`ExampleUnion` can store `char`, `int` and `float` data types in the same memory location. To access the members of a union in C, one can use the dot operator, similar to that used for structures.

> [!tip]
> Imagine a union to a variable that can hold a varied type of var, this is usefull for example when we accept a user input that can have multiple formats 


## Bitwise operators
Bitwise operators are operators that manipulate the individual bits of a binary value, performing operations on each corresponding bit position. The bitwise operators are shown below:
- Right shift (`>>`)
- Left shift (`<<`)
- Bitwise OR (`|`)
- Bitwise AND (`&`)
- Bitwise XOR (`^`)
- Bitwise NOT (`~`)

To see and on field example refer to [[Intro to C - Part 1#Bit wise operations use cases|This]]

### Right and Left Shift
The right shift (`>>`) and left shift (`<<`) operators are used to shift the bits of a binary number to the right and left by a specified number of positions, respectively.

Shifting right discards the rightmost number of bits by the specified value and zero bits of the same amount are inserted into the left. For example, the image below shows `10100111` shifted right by `2`, to become `00101001`.

![image](https://user-images.githubusercontent.com/111295429/233790472-9782abea-7104-4f8f-b927-5ee0e74e8424.png)

On the other hand, shifting left discards the leftmost bits and the same number of zero bits are inserted from the right handside. For example, the image below shows `10100111` shifted left by `2`, to become `10011100`.

![image](https://user-images.githubusercontent.com/111295429/233791839-6d230e61-7f27-43f3-95a2-dbd1ead75b6f.png)

---

## Passing By Value
Passing by value is a method of passing arguments to a function where the argument is a copy of the object's value. This means that when an argument is passed by value, the value of the object is copied and the function can only modify its local copy of the object's value, not the original object itself.

```c
int add(int a, int b)
{
   int result = a + b;
   return result;
}

int main()
{
   int x = 5;
   int y = 10;
   int sum = add(x, y); // x and y are passed by value

   return 0;
}
```

## Passing By Reference
Passing by reference is a method of passing arguments to a function where the argument is a pointer to the object, rather than a copy of the object's value. This means that when an argument is passed by reference, the memory address of the object is passed instead of the value of the object. The function can then access and modify the object directly, without creating a local copy of the object.

```c
void add(int *a, int *b, int *result)
{
  
  int A = *a; // A is now the same value of a passed in from the main function
  int B = *b; // B is now the same value of b passed in from the main function
  
  *result = B + A;
}

int main()
{
   int x = 5;
   int y = 10;
   int sum = 0;

   add(&x, &y, &sum);
  
   // 'sum' now is 15
   
   return 0;
}
```
