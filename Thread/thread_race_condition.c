#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
/*
-> A race condition is a situation that may occur inside a critical section. 
-> Result of multiple thread executing the critical section

*/

int countval = 0;  //critical section

//routine is used by both the threads
void* routine() {
    for (int i = 0; i < 1000000; i++) {
        countval++; //
    }
}

int main(int argc, char* argv[]) {
    pthread_t t1, t2, p3, p4;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0) 
    {
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0) {
        return 2;
    }
    if (pthread_join(t1, NULL) != 0) {
        return 3;
    }
    if (pthread_join(t2, NULL) != 0) {
        return 4;
    }
   //obseve that race output -> final value is uncertain
    printf("Number of times loop executed: %d\n", countval);
    return 0;
}
