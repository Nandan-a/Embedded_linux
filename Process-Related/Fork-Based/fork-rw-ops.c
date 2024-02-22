/*
	Write two functions readFunction and writeFunction to perform read and write
	write : system call write data in a file and move the cursor following the last byte written
	subsequent read will return 0 bytes read; hence separate file descriptor in child and parent for both reading and writing the data
	code maintained by : bhupendra.jmd@gmail.com

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
void readFunction();
void writeFunction();
int main()
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        perror("Child process not created");
    }
    else if (pid == 0)
    {
        readFunction();
    }
    else
    {
        writeFunction();
    }
    
    return 0;
}
void writeFunction()
{
    int writefd = open("testmsg.txt",O_CREAT | O_RDWR);
    char buffer[512] = "The best way to predict the future in Embedded Linux is create VM in Windows and start writing the program\n";
    if (writefd < 0)
    {
        perror("Error in writing the data");
    }
    else
    {
       int nbytes = write(writefd,buffer,strlen(buffer)+1);
       printf("%d bytes data written in file: \n", nbytes);
       printf("Data %s\n ",buffer);
    }
    close(writefd);
}
void readFunction()
{
    char buffer[1024];
    int readfd = open("testmsg.txt", O_RDWR);
    if(readfd < 0)
    {
        perror("No data Read from file\n");
    }
    else
    {
        int nbytesread = read(readfd,buffer,sizeof(buffer));
        printf("%d bytes data read from the file: \n", nbytesread);
        printf("data read %s\n",buffer);
    }
    close(readfd);
}
