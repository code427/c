#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define PORT 4000
#define MAXDATASIZE 1000

int main(int argc,char* argv[]){

int sock_fd,numbytes;
char buf[MAXDATASIZE];

struct hostent *he;

struct sockaddr_in their_addr;

if(argc!=2){
perror("enter hostname\n");
exit(1);
}
if((he=gethostbyname(argv[1]))==NULL){
herror("gethostbyname\n");
exit(1);
}
if((sock_fd=socket(AF_INET,SOCK_STREAM,0))==-1){
perror("socket \n");
exit(1);
}

their_addr.sin_family=AF_INET;
their_addr.sin_port=htons(PORT);

struct in_addr** adr;
adr=(struct in_addr**)he->h_addr_list;

their_addr.sin_addr=((struct in_addr )*adr[0]);

printf("get addr %s\n",inet_ntoa(*adr[0]));
bzero(&(their_addr.sin_zero),8);

if(connect(sock_fd,(struct sockaddr *)&their_addr,sizeof(struct sockaddr))==-1){
perror("connect\n");
exit(1);}

if((numbytes=recv(sock_fd,buf,MAXDATASIZE,0))==-1){
perror("receive\n");
exit(1);
}
buf[numbytes]='\0';
printf("Received:%s",buf);
return 0;
}


