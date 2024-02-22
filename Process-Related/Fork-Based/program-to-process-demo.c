/*
program -> program-to-process-demo.c
gcc program-to-process-demo.c -o prodemo.out
Process:
- program loaded in memory for CPU execution (RAM/SWAP)
process creation:
./prodemo.out

Check in the terminal PID and PPID
ps -e   -> locate the process 
Sample Output:
194156 pts/0    00:00:00 prodemo.out
ps -e o cmd,pid,ppid                 # o - format

*/
#include <stdio.h>
#include <unistd.h>   // man 3 sleep
int main (int argc, char* argv[])
{
    for (int index = 0; index < 20; index++)
    {
        printf("value of index = %d\n",index);
        sleep(2);
        printf("value of index = %d\n",index);
        sleep(2);
    }
    return 0;
}   