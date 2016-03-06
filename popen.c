#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){

FILE* pipein,*pipeout;

char buffer[80];

pipein=popen("ls","r");
pipeout=popen("sort","w");

while(fgets(buffer,80,pipein))
	fputs(buffer,pipeout);

pclose(pipein);
pclose(pipeout);

return(0);
}




