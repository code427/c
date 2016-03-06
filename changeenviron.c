#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
char* argv[]={"environ",NULL},
	*envp[]={"foo=bar","bar=foo",NULL };
execve("./environ",argv,envp);
perror("exeve failed");
return;
}
