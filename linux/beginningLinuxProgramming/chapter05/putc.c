#include<stdio.h>
#include<stdlib.h>

int main()
{

FILE *output;
output=fopen("/root/bk/newpro","w");
putc(43, output);
exit(0);
}
