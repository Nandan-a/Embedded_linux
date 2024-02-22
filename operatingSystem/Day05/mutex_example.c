#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

pthread_mutex_t mutex;
float area,radius;
void* get_circumference()
{
    float diameter;
    int circumference;
    pthread_mutex_lock(&mutex);
    printf("Enter the circumference of the circle: ");
    scanf("%d",&circumference);
    diameter = circumference / 3.14;
    radius = diameter / 2;
    pthread_mutex_unlock(&mutex);
}

void* calculate_area()
{
    pthread_mutex_lock(&mutex);
    area = 3.14 *(radius*radius);
    // printf("The area of circle is:%f\n",area);
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char* argv[])
{
    // time_t begin = time(NULL);
    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);
    if(pthread_create(&t1,NULL,get_circumference,NULL) != 0)
    {
        return 1;
    }
    if(pthread_create(&t2,NULL,calculate_area,NULL) != 0)
    {
        return 3;
    }
    if(pthread_join(t1,NULL))
    {
        return 2;
    }
    if(pthread_join(t2,NULL))
    {
        return 4;
    }
    pthread_mutex_destroy(&mutex);
    printf("The area of circle is:%0.2f\n",area);
    // time_t end = time(NULL);
    return 0;

}