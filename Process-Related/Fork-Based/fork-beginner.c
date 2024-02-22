/*
    Demonstration of the working of fork system call (man 2 fork)
    fork : used to create a child process
    All the statements written after fork system call is executed twice
    (One by parent process and one by child process)
    code maintained by : bhupendra.jmd@gmail.com
   
   BHIoT$ ps -eL -o user,pid,ppid,cmd | grep a.out 
    BHIoT$ ./fb.out 
    Before Fork
    After fork
    After fork

    BHIoT$ ps -eL -o user,pid,ppid,stat,cmd | grep fb.out
bhupend+ 2223268 1794686 S+   ./fb.out
bhupend+ 2223269 2223268 S+   ./fb.out

Note:
PID of the parent process is PPID of the child process

*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    printf("Before Fork\n");
    fork();
    /*
            The statement written below will be printed twice
            One will be executed by parent process and one by child process
    */
    sleep (20);
    printf("After fork\n");
    return 0;
}
