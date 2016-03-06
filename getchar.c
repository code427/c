#include<stdio.h>
int main(){

int i=0;
char ch=' ';
char string[100];
for(i=0;i<100;i++)
string[i]='a';

putchar('?');
i=0;
while((ch=getchar())!='\n'){

string[i]=ch;i++;
}


for(i=0;i<10;i++){
putchar(string[i]);


}

putchar('\n');
}
