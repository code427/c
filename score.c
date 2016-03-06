#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int scores[10]={67,28,21,6,88,92,90,21,14,1000};
int begin;

begin=0;

while(scores[begin]!=1000)
{
printf("%d\n", scores[begin]);
fflush(stdout);sleep(1);
begin=begin+1;

}

}
