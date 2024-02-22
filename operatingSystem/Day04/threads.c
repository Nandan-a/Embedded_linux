#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

int num1 = 2;
int num2 = 2;
void *routine()
{
    num1 += 5;
    printf("value of num1: %d\n",num1);
}

void *routine1()
{
    num2 +=10;
    printf("value of num2:%d\n",num2);

}

int main(int argc,char *argv[])
{
    pthread_t t1,t2;
    if(pthread_create(&t1,NULL, &routine,NULL))
    {
        return 1;

    }
    if(pthread_create(&t2,NULL,&routine1,NULL))
    {
        return 2;
    }
    if(pthread_join(t1,NULL))
    {
        return 3;
    }
    if(pthread_join(t2,NULL))
    {
        return 4;
    }
    printf("hello!");
}