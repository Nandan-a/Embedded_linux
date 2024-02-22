/*
	Handling all possible values of fork system call
	code maintained by : <bhupendra.jmd@gmail.com>
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t ret;
    ret = fork();
    if (ret == 0 )
    { 
     //Child Process Block
     system("python helloworld.py");
    }
    else if(ret>0)
    {
      //parent process block
      system("node helloworld.js");
    }
    else
    {
            perror("child is not created \n");
    }
    
   return 0;
}
