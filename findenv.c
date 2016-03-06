#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

extern char** environ;
void* findenv(char* string)
{
char* jack;
int len=0;
char **p=environ;

while(*p){
jack=*p;
p++;
int i=0;
while((jack[i]&&string[i])&&(jack[i]==string[i]))
{i++;}
if((i>0)&&(jack[i]=='=')){
printf("found %s=%s\n",string,&jack[i]);
exit(0);
}}
}

int main()
{
char*input,c=0;
int i=0;
printf("please enter the cmd:");
while(c!='\n')
{c=getchar();
input[i]=c;i++;
}
findenv(input);

}
