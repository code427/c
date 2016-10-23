#include<stdio.h>
#include<unistd.h>

main()
{
pid_t pid;
printf("Now only on process\n");
printf("calling fork..\n");
pid=fork();
if(!pid)
printf("I'm in the child\n");
else if (pid>0)
printf("I'am the parent, child process id is%d",pid);

}

