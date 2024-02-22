#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <wait.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#define PAGESIZE 4096;
int count = 0;
// *shared_memory=0;
sem_t sema;
int sem;

// void *routine()
// {
//     pthread_mutex_lock(&mutex);
//     static int num1 = 4;
//     static int num2 = 7;
//     printf("1st values are %d & %d\n",num1,num2);
//     num1=num1+num2;
//     num2=num1-num2;
//     num1=num1-num2;
//     printf("2nd values are %d & %d\n",num1,num2);
//     pthread_mutex_unlock(&mutex);
// }
int *ajja_bhai_krta_hu()
{
    int a=10,b=20;
    sem_getvalue(&sema,&sem);
    printf("%d\n",sem);
    sem_wait(&sema);
    for(int i=0;i<100000;i++)
    {
        count++;
    }
    count=a+b;
    printf("%d\n",count);
    sleep(5);
    sem_getvalue(&sema,&sem);
    sem_post(&sema);
}
/*int *ajja_bhai_krta_hu_tujebhi()
{
    sem_getvalue(&sema,&sem);
    printf("%d\n",sem);
    sem_wait(&sema);
    for (int i = 0; i < 100000; i++)
    {
        /* code */
        /*count ++;
    }

    printf("%d\n",count);
    sleep(5);
    sem_post(&sema);
    
}*/
// int 
// int x=10;
// int y=20;
// int add(int x, int y)
// {
//     int c;
//     c=x+y;
//     // printf("addition :%d\n",c);
//     return c;
// }

// int sub(int x, int y)
// {
//     int c;
//     c=x-y;
//     // printf("substraction :%d\n",c);
//     return c;
// }
// int *counter()
// {
//     sem_wait(&sema);
//     //printf("%d\n",count);
//     for(int i=0;i<10000000;i++)
//     {
//         count++;
//     }
//     printf("%d\n",count);
//     sem_post(&sema);
// }

// int *counter1()
// {
//     sem_wait(&sema);
//     //printf("%d\n",count);
//     for(int i=10000000;i>0;i--)
//     {
//         count--;
//     }
//     printf("%d\n",count);
//     sem_post(&sema);
// }





int main()
// {
//     u_int8_t *shared_memory = mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
//     int add,num1,num2;
//     pid_t ret = fork();
//     if(ret == 0)
//     {
//         printf("enter two numbers");
//         scanf("%d%d",&num1,&num2);
//         *shared_memory=num1+num2;
//         printf("%d\n",*shared_memory);
//     }
//     else if (ret > 0)
//     {
//         wait(NULL);
//         *shared_memory = *shared_memory * 2;
//         printf("%d",*shared_memory);
//     }

// }

// {
//     pthread_t t1,t2;
//     pthread_create(&t1,NULL,&routine,NULL);
//     pthread_create(&t2,NULL,&routine,NULL);

//     pthread_join(t1,NULL);
//     pthread_join(t2,NULL);
// }


// {
//     pid_t rut = fork();
//     if(rut==0)
//     {
        
//         add(10,30);
//         sub(12,02);

//     }
//     else
//     {
//         wait(NULL);
//         add(45,55);
//         sub(40,20);
//     }
// }

// ------------------------------------------------------------------------//

{
    sem_init(&sema,0,1);
    pthread_t t[8];
    for(int i=0;i<=8;i++)
    {
        pthread_create(&t+(i) ,NULL,ajja_bhai_krta_hu,NULL);
        //pthread_create(&t+(i+1),NULL,ajja_bhai_krta_hu,NULL);
    }
    for(int i=0;i<=8;i++)
    {
        pthread_join(t+(i),NULL);
        // pthread_join(t+(i+1),NULL);
    }
    // pthread_join(t2,NULL);
    sem_destroy(&sema);

}
