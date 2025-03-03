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


