#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
char buff[513];
int main(){

int fd,n;

fd=open("data",O_RDWR|O_CREAT);

lseek(fd,5,0);
n=read(fd,buff,512);
printf("n=%d\n",n);
fflush(stdout);
sleep(3);
write(fd,"iqiqiqn",5);

}
