#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
int main()
{
char hostname[255];

gethostname(hostname,255);
printf("hostname: %s\n",hostname);

}

