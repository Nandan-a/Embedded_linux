#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
	for(int i=0;i<5;i++)
	{
		system("gopen water.txt");
		sleep(2);
		system("pkill -15 gedit");
		sleep(300);
	}
return 0;
}
