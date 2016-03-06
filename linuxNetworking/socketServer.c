#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<arpa/inet.h>

#define MYPORT 4000
#define BACKLOG 10

int main(){
int sock_fd,new_fd;
struct sockaddr_in my_addr;
struct sockaddr_in their_addr;

int sin_size;

if((sock_fd=socket(AF_INET,SOCK_STREAM,0))==-1){

perror("socket creation error\n");
exit(1);
}

my_addr.sin_family=AF_INET;
my_addr.sin_port=htons(MYPORT);
my_addr.sin_addr.s_addr=INADDR_ANY;
bzero(&(my_addr.sin_zero),8);

if(bind(sock_fd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1){
perror("bind error\n");
exit(1);
}


if(listen(sock_fd,BACKLOG)==-1){
perror("listen error\n");
exit(1);
}

while(1){
sin_size=sizeof(struct sockaddr_in);

if((new_fd=accept(sock_fd,(struct sockaddr *)&their_addr,&sin_size))==-1){
perror("accept error\n");
continue;
}

printf("server:got connection from %s\n",inet_ntoa(their_addr.sin_addr));

if(!fork())

if(send(new_fd,"Hello, world!\n",14,0)==-1){
perror("send error\n");
close(new_fd);
exit(0);
}
close(new_fd);


}

while(waitpid(-1,NULL,WNOHANG)>0);


}
