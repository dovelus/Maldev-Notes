#include <Windows.h>
#include <stdio.h>

#define FlagOn( Flags, TheFlag )		( (Flags) & (TheFlag) ) //TESTS A FLAG
#define SetFlag( Flags, TheFlag )		( (Flags) |= (TheFlag) ) //SETS A FLAG FOR AN INPUT
#define ClearFlag( Flags, TheFlag )		( (Flags) &=  ~(TheFlag) ) //The ~ is used to clear a value in item passed

#define MULTIPLE_OF_16 0x10
#define ODD_NUMBER 0x1

#define PAGE_EXECUTE 0x10
#define PAGE_EXECUTE_READ 0x20
#define PAGE_EXECUTE_READWRITE 0x40

#define MEM_COMMIT 0x00001000
#define MEM_RESERVE 0x00002000

INT 
main(VOID)
{
	INT min = -1;
	UINT max = 4294967295;

	UINT nextClass = 770;

	printf("is min == max? %s \n", (min == max) ? "YES" : "NO"); // This will print YES why becase -1 in usigned is the value of max
	printf("is max > min? %s \n", (max > min) ? "YES" : "NO"); // This will print NO

	printf("is 770 a multiple of 16? %s \n", FlagOn(nextClass, MULTIPLE_OF_16) ? "YES" : "NO");
	printf("is 770 an odd number? %s \n", FlagOn(nextClass, ODD_NUMBER) ? "YES" : "NO");

	SetFlag(nextClass, ODD_NUMBER);

	printf("is 771 and odd number? %s \n", FlagOn(nextClass, ODD_NUMBER) ? "YES" : "NO");

	ClearFlag(nextClass, ODD_NUMBER);

	printf("ClearFlag(nextClass, ODD_NUMBER) = %i (0x%08x) \n", nextClass, nextClass);

	ULONG memory = MEM_COMMIT | MEM_RESERVE;

	/// VirtualAlloc(nullptr, 0x1000, memory, PAGE_EXECUTE_READ) Example usage in virtualAlloc

	printf("Is memory being committed? %s \n", FlagOn(memory, MEM_COMMIT) ? "YES" : "NO");

	return ERROR_SUCCESS;

}

