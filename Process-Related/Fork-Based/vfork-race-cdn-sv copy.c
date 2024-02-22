/*
    Race condition : uncertain/unpredictiable about the final output 
    in multiprocessing environment
    Solution : using vfork() -  vfork doesn't start the execution of 
    parent until child does not exit.(exit should be explicitely in child block)
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t pid;
    int shared_Var = 10;
    pid = vfork();
    if (pid == 0)
    {
    
            ++shared_Var;
            //sleep(10);
            exit(0);
    }
    else if (pid > 0)
    {
            --shared_Var;
           // sleep(10);

    }
    else
    {
        {
            printf("Child process is not created\n");
        }

    }
    printf("Final count = %d\n",shared_Var);
    return 0;
}