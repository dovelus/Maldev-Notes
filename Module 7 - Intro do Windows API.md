
### Windows Data Types

The Windows API has many data types outside of the well-known ones (e.g. int, float). The data types are documented and can be viewed [here](https://learn.microsoft.com/en-us/windows/win32/winprog/windows-data-types).

Some of the common data types are listed below:

- `DWORD` - A 32-bit unsigned integer, on both 32-bit and 64-bit systems, used to represent values from 0 up to (2^32 - 1).

```c
DWORD dwVariable = 42;
```

- `size_t` - Used to represent the size of an object. It's a 32-bit unsigned integer on 32-bit systems representing values from 0 up to (2^32 - 1). On the other hand, it's a 64-bit unsigned integer on 64-bit systems representing values from 0 up to (2^64 - 1).

```c
SIZE_T sVariable = sizeof(int);
```

- `VOID` - Indicates the absence of a specific data type.

```c
void* pVariable = NULL; // This is the same as PVOID
```

- `PVOID` - A 32-bit or 4-byte pointer of any data type on 32-bit systems. Alternatively, a 64-bit or 8-byte pointer of any data type on 64-bit systems.

```c
PVOID pVariable = &SomeData;
```

- `HANDLE` - A value that specifies a particular object that the operating system is managing (e.g. file, process, thread).

```c
HANDLE hFile = CreateFile(...);
```

- `HMODULE` - A handle to a module. This is the base address of the module in memory. An example of a MODULE can be a DLL or EXE file.

```c
HMODULE hModule = GetModuleHandle(...);
```

- `LPCSTR/PCSTR` - A pointer to a constant null-terminated string of 8-bit Windows characters (ANSI). The "L" stands for "long" which is derived from the 16-bit Windows programming period, nowadays it doesn't affect the data type, but the naming convention still exists. The "C" stands for "constant" or read-only variable. Both these data types are equivalent to `const char*`.

```c
LPCSTR  lpcString   = "Hello, world!";
PCSTR   pcString    = "Hello, world!";
```

- `LPSTR/PSTR` - The same as `LPCSTR` and `PCSTR`, the only difference is that `LPSTR` and `PSTR` do not point to a constant variable, and instead point to a readable and writable string. Both these data types are equivalent to `char*`.

```c
LPSTR   lpString    = "Hello, world!";
PSTR    pString     = "Hello, world!";
```

- `LPCWSTR\PCWSTR` - A pointer to a constant null-terminated string of 16-bit Windows Unicode characters (Unicode). Both these data types are equivalent to `const wchar*`.

```c
LPCWSTR     lpwcString  = L"Hello, world!";
PCWSTR      pcwString   = L"Hello, world!";
```

- `PWSTR\LPWSTR` - The same as `LPCWSTR` and `PCWSTR`, the only difference is that 'PWSTR' and 'LPWSTR' do not point to a constant variable, and instead point to a readable and writable string. Both these data types are equivalent to `wchar*`.

```c
LPWSTR  lpwString   = L"Hello, world!";
PWSTR   pwString    = L"Hello, world!";
```

- `wchar_t` - The same as `wchar` which is used to represent wide characters.

```c
wchar_t     wChar           = L'A';
wchar_t*    wcString        = L"Hello, world!";
```

- `ULONG_PTR` - Represents an unsigned integer that is the same size as a pointer on the specified architecture, meaning on 32-bit systems a `ULONG_PTR` will be 32 bits in size, and on 64-bit systems, it will be 64 bits in size. Throughout this course, `ULONG_PTR` will be used in the manipulation of arithmetic expressions containing pointers (e.g. PVOID). Before executing any arithmetic operation, a pointer will be subjected to type-casting to `ULONG_PTR`. This approach is used to avoid direct manipulation of pointers which can lead to compilation errors.

```c
PVOID Pointer = malloc(100);
// Pointer = Pointer + 10; // not allowed
Pointer = (ULONG_PTR)Pointer + 10; // allowed
```
### Data Types Pointers

The Windows API allows a developer to declare a data type directly or a pointer to the data type. This is reflected in the data type names where the data types that start with "P" represent pointers to the actual data type while the ones that don't start with "P" represent the actual data type itself.

This will become useful later when working with Windows APIs that have parameters that are pointers to a data type. The examples below show how the "P" data type relates to its non-pointer equivalent.

- `PHANDLE` is the same as `HANDLE*`.
    
- `PSIZE_T` is the same as `SIZE_T*`.
    
- `PDWORD` is the same as `DWORD*`.