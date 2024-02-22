#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    pid_t ret;
    int f;
    char buffer[1024] ="DIOT /-(-_-)-/ ";
    char buffer1[1024] = "Hello from child";
    ret = fork();
    if (ret<0)
    {
        perror("child process not created");
    }
    else if(ret==0)
    {
        f = open("h4.txt", O_CREAT | O_RDWR | S_IRWXU, 0777);
        write(f,buffer,sizeof(buffer));
    }
    else
    {
        read(f,buffer,sizeof(buffer1));
        printf("Data read from file in parent :\n");
        printf("%s\n",buffer1);
    }
    return 0;
}