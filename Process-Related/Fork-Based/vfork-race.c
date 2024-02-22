/*
    Race condition : uncertain/unpredictiable about the final output 
    in multiprocessing environment
    Solution : using vfork() -  vfork doesn't start the execution of 
    parent until child does not exit.
    code maintained by : bhupendra.jmd@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t pid;
    int count1, count2;
    pid = vfork();
    if (pid == 0)
    {
        for(count1 = 0; count1<=10; count1++)
        {
            printf("Child count = %d\n",count1);
        }
        exit(0);
    }
    else if (pid > 0)
    {
        for(count2 = 0; count2<=50; count2++)
        {
            printf("Parent count = %d\n",count2);
        }
    }
    else
    {
        {
            printf("Child process is not created\n");
        }
    }
    return 0;
}
