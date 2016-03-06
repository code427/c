#include<stdio.h>
#include<unistd.h>
main()
{
int pid;

pid=fork();
switch(pid){
case -1: 	
	perror("fork failed\n");
	exit(0);
case 0:	
	execl("/bin/ls","ls","-l",NULL);
	perror("execl failed");
	exit(1);
default:
	wait(NULL);
	printf("ls is completed!");
	exit(0);


}


}
