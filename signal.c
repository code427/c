#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int interrupt(){
printf("interrupt called\n");

fflush(stdout);
sleep(3);
printf("interupt ended\n");

}

int catchquit(){
printf("quit signal caught\n");
sleep(3);
printf("quit siangl seede\n");

}
int main(){
signal(SIGINT,interrupt);
signal(SIGQUIT,interrupt);
printf("signal set\n");
sleep(30);
printf("main func ended\n");

}
