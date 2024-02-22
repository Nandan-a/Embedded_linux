#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/mman.h>
#define PAGE_SIZE 4096
int count=10;
int main(int argc,char *argv[])
{
    u_int8_t *shared_memory = mmap(NULL,PAGE_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);
    *shared_memory = 50;
    if (fork()==0)
    {
        *shared_memory = 20;
        count = 15;
        printf("child PID:%d\n",getpid());
    }
    else
    {
        wait(NULL);
    }
    printf("shared value between the process %i\tPID:%d\n",*shared_memory,getpid());
    printf("Not shared value between the procss:%d\tPID:%d\n",count,getpid());
    
}