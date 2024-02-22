#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int output = 0;
void *routine()
{
    int input_1 = 0;
    int input_2 = 0;
    printf("Enter two numbers:");
    scanf("%d %d",&input_1,&input_2);
    output = input_1 + input_2;
    printf("value of x: %d\n",output);
}

void *routine2()
{
    output *= 5;
    printf("value of z: %d\n",output);
}
int main(int argc, char argv[])
{
    pthread_t t1,t2;
    if(pthread_create(&t1,NULL,&routine,NULL))
    {
        return 1;
    }
    if (pthread_join(t1,NULL))
    {
        return 2;
    }
    if(pthread_create(&t2,NULL,&routine2,NULL))
    {
        return 3;
    }
   
    if(pthread_join(t2,NULL))
    {
        return 4;
    }
    return 0;
}