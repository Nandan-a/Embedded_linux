#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t ret;
    ret = fork();
    if( ret == 0)
    {
        system("python3 Helloworld.py");
    }
    else if( ret > 0)
    {
        system("node Helloworld.js");
    }
    else 
    {
        perror("child is not created \n");
    }
    return 0;
}
