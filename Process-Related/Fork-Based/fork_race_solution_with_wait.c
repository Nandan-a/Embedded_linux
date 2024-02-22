/*
	fork with shared variable
	code maintained by : <bhupendra.jmd@gmail.com>
	sequence of executaion is not guranteed (scheduling is handled by kernel (GPOS)
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int count = 10;
int main()
{
    pid_t ret;
    ret = fork();

    if (ret == 0 )
    {
        printf("Child process is created \n");
        count = count + 2;
        //sleep(1);
        printf("Count in child block: %d\n",count);
    }
    else if(ret > 0)
    {
        wait(NULL);
        printf("parent process block\n");
        count = count + 5 ;
        printf("Count in parent block: %d\n",count);
        printf("ret val parent : %d\n",ret);
    }
    else
    {
            perror("child is not created \n");
    }
    printf("Final output = %d\n",count);
	return 0;
}
