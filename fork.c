#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()

{
int pid;
int status,exit_status;
if((pid=fork())<0)
{
printf("fork error");
exit(1);
}
if(!pid)
{
sleep(3);
exit(5);
}

wait(&status);

printf("exit status: %d\n", status);
exit_status=status>>8;
printf("after shift %d\n",exit_status);

exit(0);
}
