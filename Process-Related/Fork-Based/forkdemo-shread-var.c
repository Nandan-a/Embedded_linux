/*
	fork with shared variable
	code maintained by : <bhupendra.jmd@gmail.com>
	sequence of executaion is not guranteed (scheduling is handled by kernel (GPOS)
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t ret;
    ret = fork();
    int count = 10;
    if (ret == 0 )
    {
        printf("Child process is created \n");
        ++count;
        printf("Count in child block: %d\n",count);
    }
    else if(ret>0)
    {
        printf("parent process block\n");
        ++count ;
        printf("Count in parent block: %d\n",count);
        printf("ret val parent : %d\n",ret);
    }
    else
    {
            perror("child is not created \n");
    }
    
	return 0;
}
