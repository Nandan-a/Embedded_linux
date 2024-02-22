#include <stdio.h>
#include "addfunction.h"
int main()
{
    int result = add(10,20);
    printf("%d\t",result);
    return 0;
}
/*

BHIoT$ gcc addfunctiondef.c -c
BHIoT$ gcc main_function.c -c
BHIoT$ gcc addfunctiondef.o main_function.o -o all.out
BHIoT$ ./all.out 
30	BHIoT$ 


*/