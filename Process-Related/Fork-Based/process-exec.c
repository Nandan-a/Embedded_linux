#include<stdio.h>
#include <unistd.h>
#include <time.h> 
void add(int a,int b);
void multiply(int a,int b);
void add(int a, int b)
{
    printf("Add : %d\n",(a+b));   
}
void multiply(int a, int b)
{
    printf("Multiply: %d\n",(a*b));   
}
int main()
{
    clock_t start = clock(); 
    for(int i=0; i<200000;i++)
    {
        add(2,4);
    }
    for(int i=0; i<250000;i++)
    {
        multiply(4,5);
    }
    clock_t end = clock(); 
    double time_taken = (double)(end - start)/CLOCKS_PER_SEC; // in seconds 
    printf("time program took %f seconds to execute \n", time_taken); 
    return 0; 
}