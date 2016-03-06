#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

#define TRUE 1
#define FALSE 0
int flag;
int sec;
void setflag(){

flag=TRUE;
printf("flag is %d\n",flag);
}

int main(int argc,char* argv[]){

if(argc<2)
{
	printf("too few argc\n");
	exit(1);
}

if((sec=atoi(argv[1]))<=0) {
	printf("invalid time\n");
	exit(2);
}

printf("sec=%d\n",sec);
printf("argv1=%s\n",argv[2]);



signal(SIGALRM,setflag);
alarm(sec);
pause();
printf("after pause flag is %d\n",flag); /*?? why after pause flag is 0?*/
if(flag)
{
printf("i am here\n");
int i=2;
for(i=2;i<argc;i++){
printf("%s\n",argv[i]);

}

}

 exit(0);
}
