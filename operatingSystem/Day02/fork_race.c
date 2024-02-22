#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


int main(){
    pid_t pid;
    int shared_var = 10;
    pid = fork();
    int num1 = 6;
    int *num2;
    num2=&num1;
    printf("*num2=%p\n",num2);
    printf("num1=%d\n",&num1);
    if(pid==0)
    {
        shared_var++;
        int value;
        int *ptrx;
        ptrx = &value;
        printf("%d\n value=%d\n",&shared_var,&value);
        printf("%d\n ptrx=%p\n",&shared_var,ptrx);
        system("chmod 700 add.sh");
        system("./add.sh");
        sleep(1);

    }
    else if (pid>0)
    {
        int u_value;
        int *ptru;
        ptru = &u_value;
        shared_var--;
        printf("%d\n u_value=%d\n",&shared_var,&u_value);
        printf("%d\n ptru=%p\n",&shared_var,&u_value);
        system("chmod 700 subtract.sh");
        system("./subtract.sh");
        sleep(2);
    }
    else
    {
        {
            printf("child process is not created\n%d",&shared_var);
        }
    }
    printf("final count = %d\n",shared_var);
    printf("%d\n",shared_var);
}