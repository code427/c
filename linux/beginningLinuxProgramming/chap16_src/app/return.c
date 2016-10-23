#include<stdio.h>
#include<stdlib.h>

int main()
{
char c;

printf("input char:");
c=getchar();
switch(c){
case 'a':
printf("you input a\n");
break;
case '\n':
printf("yout input return\n");
}
}
