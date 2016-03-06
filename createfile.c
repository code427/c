#include<stdio.h>
#include<stdlib.h>
#include<sys/errno.h>
#include<fcntl.h>
#include<string.h>
int main(){

int temfd;

if((temfd=creat("teee",0444))<0)
printf("cant creat file\n");
if(link("teee","locktee")<0)
printf("link fail errorno=%s",strerror(errno));
creat("teee2",0444);
if(link("teee2","locktee")<0)
printf("link failed\n");

}
