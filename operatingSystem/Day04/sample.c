#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int countval = 0; //called as critical section()

void *routine()
{
    for(int value = 0; value<1000000;value++)
    {
        countval++;
    }
}

int main(int argc, char argv[])
{
    pthread_t t1,t2;
    if(pthread_create(&t1,NULL,&routine,NULL)!=0)
    {
        return 1;
    }
    if(pthread_create(&t2,NULL,&routine,NULL)!=0)
    {
        return 3;
    }
    if(pthread_join(t1,NULL)!=0)
    {
        return 2;
    }
    if(pthread_join(t2,NULL)!=0)
    {
        return 4;
    }
    printf("Number of times loop executed: %d\n",countval);
    return 0;

}