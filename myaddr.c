#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
int main(){

int sockfd;
struct sockaddr_in my_addr;

my_addr.sin_addr.s_addr=htonl(INADDR_ANY);
printf("my address is %s\n",inet_ntoa(my_addr.sin_addr.s_addr));
//printf("%s\n",inet_ntoa(INADDR_ANY));


}


