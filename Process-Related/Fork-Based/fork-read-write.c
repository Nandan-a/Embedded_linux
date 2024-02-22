/*
	Fork : Read and write
	wrtite : parent process
	read : Child Process
	code maintained by : bhupendra.jmd@gmail.com
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
   pid_t ret;
   int fd;
   char buffer[1024] = "Embedded Linux is awesome";
   char buffer1[1024] = "Hello from Child";
   ret = fork();
   if(ret<0)
   {
       perror("Child process not created !! \n");
   }
   else if(ret == 0)
   {
       fd = open("testdata1.txt",O_RDWR);
       write(fd,buffer,sizeof(buffer));
   }
   else
   {
       read(fd,buffer1,sizeof(buffer1));
       printf("Data read from file in parent : \n");
       printf("%s\n",buffer1);
   }
   return 0;
}
