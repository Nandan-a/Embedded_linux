#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

pthread_mutex_t mutex;
int countval = 0;
int shared_val = 0;
void *routine()
{
    for(int val =0; val<1000000;val++)
    {
        pthread_mutex_lock(&mutex);
        shared_val++;
        pthread_mutex_unlock(&mutex);
    }

}

int main(int argc,char argv[])
{
    time_t begin = time(NULL);
    pthread_t t1,t2,t3,t4;
    pthread_mutex_init(&mutex,NULL);
    if(pthread_create(&t1,NULL,&routine,NULL)!=0)
    {
        return 1;
    }
    if(pthread_create(t2,NULL,&routine,NULL)!=0)
    {
        return 2;
    }
    // if(pthread_create(&t3,NULL,&routine,NULL)!=0)
    // {
    //     return 3;
    // }
    if(pthread_join(t1,NULL))
    {
        return 3;
    }
    if(pthread_join(t2,NULL))
    {
        return 4;
    }
    pthread_mutex_destroy(&mutex);
    printf("\nNumber of times loop is executed: %d\n",shared_val);
    time_t end = time(NULL);
    printf("Time %ld\n",(end-begin));
    return 0;
}