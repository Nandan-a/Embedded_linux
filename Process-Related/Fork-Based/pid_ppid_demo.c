#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
BHIoT$ ./pp.out 
child process pid = 1048381
child process ppid = 1048380
fork ret val = 1048381
parent process pid = 1048380
parent process ppid = 488603
*/
int main()
{
    pid_t fork_ret_val;
    pid_t pid;
    fork_ret_val = fork();
    if (fork_ret_val == 0)
    {
        printf("child process pid = %d\n",getpid());
        printf("child process ppid = %d\n",getppid());
    }
    else if (fork_ret_val > 0 )
    {
        sleep(3);
        printf("fork ret val = %d\n",fork_ret_val);
        printf("parent process pid = %d\n",getpid());
        printf("parent process ppid = %d\n",getppid());
    }
    else
    {
        perror("Failed to create the child process\n");
        exit(0);
    }
    return 0;

}

