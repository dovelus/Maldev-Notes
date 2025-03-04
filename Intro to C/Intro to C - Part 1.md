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

```

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
