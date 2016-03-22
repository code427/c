#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	char *args[]={"ls", "-aF","/",0};
	char *env[]={0};
	execve("/bin/ls",args,env);
	perror("execve");
	exit(1);

}
