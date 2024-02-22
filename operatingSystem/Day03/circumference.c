#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/mman.h>

#define PAGE_SIZE 4096

int main(int argc,char *argv[])
{
    u_int8_t *shared_memory = mmap(NULL,PAGE_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);

    int radius;
    if(fork()==0)
    {
        printf("enter the diameter:");
        scanf("%hhd",&*shared_memory);
        *shared_memory = *shared_memory / 2;
        printf("getting radius:%d\n",*shared_memory);
    }
    else
    {
        wait(NULL);
        radius = *shared_memory *3.14 *2;
        printf("Circumference id:%d\n",radius);
    }
    printf("value of radius is: %d\n",*shared_memory);
}