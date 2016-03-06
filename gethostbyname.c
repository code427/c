#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include<arpa/inet.h>
int main (int argc, char *argv[]) {
struct in_addr** adr; 
struct hostent *h;

if((h=gethostbyname(argv[1])) == NULL) {
herror("gethostbyname");
exit(1);
}

adr=(struct in_addr **)h->h_addr_list; 
printf("IP Address : %s\n",inet_ntoa(*adr[0]));
return 0;
}

