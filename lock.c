#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
int fd;
fd=open("temp",O_CREAT|O_RDWR);
flock(fd,F_LOCK,0);
printf("locked\n");
flock(fd,F_ULOCK,0);
printf("unlocked\n");


}
