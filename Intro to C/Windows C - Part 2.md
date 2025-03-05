In windows the operating system a lot of time Check for flags to be set her the macros to Set, check and unset flags:
```c
#define FlagOn( Flags, TheFlag )		( (Flags) & (TheFlag) ) //TESTS A FLAG
#define SetFlag( Flags, TheFlag )		( (Flags) |= (TheFlag) ) //SETS A FLAG FOR AN INPUT
#define ClearFlag( Flags, TheFlag )		( (Flags) &=  ~(TheFlag) ) //The ~ is used to clear a value in item passed
```

Hers an example of usage in this case we simplay manipulate a number making it ODD or not:
```c
UINT nextClass = 770;

printf("is 770 an odd number? %s \n", FlagOn(nextClass, ODD_NUMBER) ? "YES" : "NO");

SetFlag(nextClass, ODD_NUMBER);

printf("is 771 and odd number? %s \n", FlagOn(nextClass, ODD_NUMBER) ? "YES" : "NO");

ClearFlag(nextClass, ODD_NUMBER);

printf("ClearFlag(nextClass, ODD_NUMBER) = %i (0x%08x) \n", nextClass, nextClass);
```

A more realistic example is the usage for checking the permission of a memory space:
```c
#define PAGE_EXECUTE 0x10
#define PAGE_EXECUTE_READ 0x20
#define PAGE_EXECUTE_READWRITE 0x40

#define MEM_COMMIT 0x00001000
#define MEM_RESERVE 0x00002000

ULONG memory = MEM_COMMIT | MEM_RESERVE;

printf("Is memory being committed? %s \n", FlagOn(memory, MEM_COMMIT) ? "YES" : "NO");

return ERROR_SUCCESS;

```