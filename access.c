#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
if(access("/tmp/letmegrow",0)!=-1)
printf("can access!\n");
printf("can't!\n");
}
