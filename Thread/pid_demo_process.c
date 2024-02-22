#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]) 
{
    int pid = fork();
    if (pid == -1) 
    {

        return 1;
    }
    //Child Process Block
    printf("Process id = ",getpid());
    if (pid != 0) 
    {
        wait(NULL); // Parent Process
    }
    return 0;
}