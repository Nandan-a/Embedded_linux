#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>


sem_t sema;

void *routine(void *pv)
{
    sem_wati(&sema);//goes into wait state
    printf("\nEntered into the critical seciton ");
}