#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int count = 10;
int main()
{
    pid_t ret;
    ret = fork();
    if (ret==0)
    {
        printf("child process is created");
        count = count + 2;
        printf("value of child block:%d\n pid:%d\n",count,getpid());
    }
    else if (ret>0)
    {
        wait(NULL);
        printf("parent process is created");
        count = count + 5;
        printf("output of parent block:%d\npid:%d\n",count,getpid());
    }
    else
    {
        perror("child process is not created>_<");
    }
printf("final output:%d\npid:%d\n",count,getpid());
}