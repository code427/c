#include<stdio.h>
#include<unistd.h>

main()
{
char* av[]={"fork",NULL};
execv("/root/bk/780470147627_download/chap16_src/app/fork",av);
perror("execv failed");
}
