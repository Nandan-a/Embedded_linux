#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("hello\n");
    fork();
    printf("hi\n");
    fork();
    exit(0);
    printf("hello nandan\n");
    return 0;
}