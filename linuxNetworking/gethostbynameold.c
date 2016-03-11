#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int i;
    struct hostent *he;
    struct in_addr **addr_list;

    if (argc != 2) {
        fprintf(stderr,"usage: ghbn hostname\n");
        return 1;
    }

    if ((he = gethostbyname(argv[1])) == NULL) {  
        herror("gethostbyname");
        return 2;
    
     }

       printf("Official name is: %s\n", he->h_name);
       printf("IP addresses: ");
       addr_list = (struct in_addr **)he->h_addr_list;
       for(i = 0; addr_list[i] != NULL; i++) {
       printf("%s \n", inet_ntoa(*addr_list[i]));
       }
      

       return 0;
}
