#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
char* itoa(int,char*);
static int num=0;
static char namebuf[20];
static char prefix[]="/tem/tem";
char* getemp(){

int length,pid;
pid=getpid();
printf("pid=%d\n",pid);
strcpy(namebuf,prefix);
length=strlen(namebuf);
itoa(pid,&namebuf[length]);

}
char *itoa(int i,char* string)
{
int j,power;
j=i;
for(power=1;j>=10;j/=10)
power*=10;

for(;power>=1;power/=10)
{
*string++='0'+i/power;
i%=power;

}
return(string);


}
int main()
{
char* name;
name=getemp();
printf("path=%s\n",namebuf);
}
