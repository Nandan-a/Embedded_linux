#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/mman.h>
#define PAGE_SIZE 4096

int main(int argc, char *argv[])
{
    u_int8_t *shared_memory = mmap(NULL,PAGE_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);
    u_int8_t *shared_memory_2 = mmap(NULL,PAGE_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);
    int add,sub,mul,div;
    pid_t ret = fork();

    if (ret == 0)
    {
        printf("enter two numbers:");
        scanf("%d %d",&*shared_memory,&*shared_memory_2);
        div = *shared_memory / *shared_memory_2;
        printf("division is: %d\n",div);
    }
    else if (ret > 0)
    {
        wait(NULL);
        printf("addition:");
        add = *shared_memory + *shared_memory_2;
        printf("addition is : %d\n",add);
        exit(0);
    }
    pid_t ret_1 = fork();
    if (ret_1 == 0)
    {
        wait(NULL);
        printf("Substraction:");
        sub = *shared_memory - *shared_memory_2;
        printf("Substraction is : %d\n",sub);
        // exit(0);
    }
    else if (ret_1 > 0)
    {
        wait(NULL);
        printf("Multiplication");
        mul = *shared_memory * *shared_memory_2;
        printf("Multiplication is:%d\n",mul);
    }
}
