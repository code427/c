#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<arpa/inet.h>	
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define PORT 4000
#define MAXDATASIZE 100
int main (int argc,char* argv[]){

int numbytes,sock_fd;
char buf[MAXDATASIZE];
struct hostent *he;
struct sockaddr_in their_addr;
struct in_addr ** adr;
if(argc !=2)
{
perror("usage client hostname\n");
exit(1);}
if((he=gethostbyname(argv[1]))==NULL)
{herror("gethostbyname");
exit(1);
}

if((sock_fd=socket(AF_INET,SOCK_STREAM,0))==-1){
perror("socket");
exit(1);
}

their_addr.sin_family=AF_INET;
their_addr.sin_port=htons(PORT);
adr=(struct in_addr**)he->h_addr_list;
printf("their ip is: %s\n",inet_ntoa(*adr[0]));
their_addr.sin_addr=((struct in_addr)*adr[0]);
bzero(&(their_addr.sin_zero),8);


if((connect(sock_fd,(struct sockaddr *)&their_addr,sizeof(struct sockaddr)))==-1)
{
perror("connecect\n");
exit(1);
}
if(send(sock_fd,"123",3,0)==-1)
{ perror("send0\n");
close(sock_fd);
exit(0);
}
printf("send 3 byte of normal data\n");
sleep(1);
if(send(sock_fd,"4",1,MSG_OOB)==-1){
perror("send1");
close(sock_fd);
exit(0);
}
printf("send 1 byte of OOB data\n");
sleep(1);
if(send(sock_fd,"56",2,0)==-1){
perror("send2");
close(sock_fd);
exit(0);
}

printf("send 2 byte of normal data\n");
sleep(1);
if(send(sock_fd,"7",1,MSG_OOB)==-1){
perror("send3");
close(sock_fd);
exit(0);
}
printf("send 1 byte of OOB data\n");
sleep(1);
if(send(sock_fd,"89",2,0)==-1){
perror("send4");
close("sock_fd");
exit(0);
}
printf("send 2 bytes of normal data\n");
sleep(1);
close(sock_fd);
return 0;

}
