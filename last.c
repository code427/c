#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
struct in_addr **adr;
struct hostent *h;

if((h = gethostbyname(argv[1])) == NULL) { 
    herror("gethostbyname");
        return 2;
    }


    adr= (struct in_addr **)h->h_addr_list;
    printf("%s \n", inet_ntoa(*adr[0]));

    printf("\n");

    return 0;
}
