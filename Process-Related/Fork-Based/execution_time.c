#include <stdio.h>
#include <time.h>
int main()
{
	clock_t t;
	t = clock();
	printf("Hi This is PGDIOT\n");
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("Total %f seconds took to execute the program \n", time_taken);
	return 0;
}
