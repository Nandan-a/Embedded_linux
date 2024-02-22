#include <stdio.h>
#include <unistd.h>
int main()
{
    char *path_loc = "/bin/bash";
    char *arg1 = "mkdir_file.sh";
    printf("Hello I am before Execl\n");
    execl(path_loc,"bash",arg1,NULL);
    printf("Hello I am after Execl");

}
