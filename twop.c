#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
int pid,ppid;
int paction(),caction();
int times=0;

int main(){

signal(SIGUSR1,paction);

switch(pid=fork())
{
case -1:
	printf("fork failed\n");
	break;

case 0:
signal(SIGUSR1,caction);
	ppid=getppid();

	for(;;){
sleep(1);
kill(ppid,SIGUSR1);
pause();

}
break;

default:
for(;;){
pause();
sleep(1);
kill(pid,SIGUSR1);
}}
}
paction(){

printf("Parent caught signal #%d\n",++times);
}
caction(){

printf("Child caught signal #%d\n",++times);
}
