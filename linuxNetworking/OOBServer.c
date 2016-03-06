#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
/* 服务器要监听的本地端口 */
#define MYPORT 4000
/* 能够同时接受多少没有accept 的连接 */
#define BACKLOG 10
void sig_urg(int );
int sock_fd, new_fd ;
main()
{
/* 在sock_fd 上进行监听，new_fd 接受新的连接 */

/* 用于存储以前系统缺省的SIGURL 处理器的变量 */ void * old_sig_urg_handle ;
/* 自己的地址信息 */
struct sockaddr_in my_addr;
/* 连接者的地址信息*/
struct sockaddr_in their_addr;
int sin_size;
int n ;
char buff[100] ;
/* 这里就是我们一直强调的错误检查．如果调用socket() 出错，则返回 */
if((sock_fd = socket(AF_INET,SOCK_STREAM,0)) == -1)
{
/* 输出错误提示并退出 */
perror("socket");
exit(1);
}
/* 主机字节顺序 */
my_addr.sin_family = AF_INET;
/* 网络字节顺序，短整型 */
my_addr.sin_port = htons(MYPORT);
/* 将运行程序机器的IP 填充入s_addr */
my_addr.sin_addr.s_addr = INADDR_ANY;
/* 将此结构的其余空间清零 */
bzero(&(my_addr.sin_zero), 8);
/* 这里是我们一直强调的错误检查！！ */ 
if (bind(sock_fd, (struct sockaddr *)&my_addr,
sizeof(struct sockaddr)) == -1)
{
/* 如果调用bind()失败，则给出错误提示，退出 */
perror("bind");
exit(1);
}
/* 这里是我们一直强调的错误检查！！ */
if (listen(sock_fd, BACKLOG) == -1)
{
/* 如果调用listen 失败，则给出错误提示，退出 */
perror("listen");
exit(1);
}
/* 设置SIGURG 的处理函数　sig_urg */
old_sig_urg_handle = signal(SIGURG, sig_urg);
/* 更改connfd 的属主 */
fcntl(sock_fd, F_SETOWN, getpid());
while(1)
{/* 这里是主accept()循环 */
sin_size = sizeof(struct sockaddr_in);
/* 这里是我们一直强调的错误检查！！ */
if ((new_fd = accept(sock_fd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
{
/* 如果调用accept()出现错误，则给出错误提示，进入下一个循环 */
perror("accept");
continue;
}
/* 服务器给出出现连接的信息 */
printf("server: got connection from %s\n", inet_ntoa(their_addr.sin_addr));
/* 这里将建立一个子进程来和刚刚建立的套接字进行通讯 */
if (!fork())
/* 这里是子进程 */
while(1)
{
if((n=recv(new_fd,buff,sizeof(buff)-1,NULL))==0)
{
printf("received EOF\n");
break ;
}
buff[n] = 0 ;
printf("Recv %d bytes: %s\n", n, buff);
}
/* 关闭new_fd 代表的这个套接字连接 */
close(new_fd);
}
/* 等待所有的子进程都退出 */
while(waitpid(-1,NULL,WNOHANG) > 0);
/* 恢复系统以前对SIGURG 的处理器 */
signal(SIGURG, old_sig_urg_handle);
}
void sig_urg(int signo)
{int n;
char buff[100] ;
printf("SIGURG received\n");
n=recv(new_fd,buff,sizeof(buff)-1,MSG_OOB);
buff [ n ] = 0;
printf("recv %d OOB byte: %s\n" , n, buff);
}
