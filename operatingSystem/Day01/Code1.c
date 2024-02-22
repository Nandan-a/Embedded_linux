#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    printf("Before fork\n");
    fork();
    sleep(2);
    fork();

    printf("1After Fork\n");

    fork();
    printf("2After Fork\n");

    return 0;
}