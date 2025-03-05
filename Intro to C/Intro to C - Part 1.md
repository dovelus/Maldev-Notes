### Why i need to user X64 and not X86 ?
Windows allows the execution of windows x86 executable thanks to an emulation layers added but if for example you want to inject code into a process that is a x86 (32bit) you need to able to speak it's language witch is a 32bit executable.

### What is the main difference between Windows C and Other OSs C ?
The main difference is that windows introduces a list of custom **Datatypes** that are easy to identify cause they are all in CAPS to have the full list of type refer to this: [Windows Data Types List](https://learn.microsoft.com/en-us/windows/win32/winprog/windows-data-types) 
To use widows data type is pretty straight forward for example this code:
```c
#include <Windows.h>
#include <stdio.h>


int main()
{
    int baseClass;
    unsigned int netClass = 770;
    unsigned long long thirdClass = 0x870;

    printf("Welcome to the workshop \n");

    return 0;
}
```
Will turn into this:
```c
#include <Windows.h>
#include <stdio.h>


INT main()
{
    INT baseClass;
    UINT netClass = 770;
    ULONGLONG thirdClass = 0x870;

    printf("Welcome to the workshop \n");

    return ERROR_SUCCESS;
}
```

> [!info]
> `ERROR_SUCCESS` is the same as `0` for windows operating system this list is very extensive and cover almost all types of error windows has

#### Why use this Datatypes and not the C native one ?
The main reason is that Microsoft likes to sometime change it's header files, for example if the underline code changes and we didn't use the same Datatypes our code may break on some windows machines, this will prevent this and will ensure compatibility.

---

> [!tip]
> Any time a function has no input variable required to run inside the parentesis in the function declaration you can use `VOID`: 
```c
INT main(VOID) // USED VOID INSTEAD OF EMPTY ()
{
    int baseClass;
    unsigned int netClass = 770;
    unsigned long long thirdClass = 0x870;

    printf("Welcome to the workshop \n");

    return 0;
}
```

---
> [!warning]
> When doing math operations its suggested to not mix and match fundamentally different Datatypes

### Bit wise operations use cases:
A bit shift operation is the operation of sifting the bytes a of a variable hers an example:

```c
// BIT SHIFT
// 0000 0010 1001 1110      // 670
// 0000 0001 0100 0111      // 
printf("bestClass >> 1: %d\n", bestClass >> 1); // 327
```

This operation shifter the Bytes by one position to the right, but why use this ? 
In windows some times processes, handles have a series of flags specified but how we can check if that flag is present ? With a bit shift operation hers a theorical example:

```c
// Lets imagine that the number 770 is a process informations
INT procInfo = 770;
// To check if for example a flag on a specific position that we know is related to some info we do this
(770 >> 8) & 1;
// This will return true if on the 8th postion the value is 1
```
