#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
int interrupt(){
printf("interrupt called\n");
//sleep(1);
printf("Interrupt function ended\n");
}


int main()
{
signal(SIGINT,interrupt);
printf("signal set\n");
sleep(10); /*why isn't main func sleeping after pressing Ctr+C?" */
printf("main func resumed\n");
return;

}

