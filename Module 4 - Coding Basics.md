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
Structs are declares using the `typedef`keyword to give