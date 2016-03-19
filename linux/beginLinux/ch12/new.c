#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>


char work_area[4];

int main ()
{


fgets(work_area, 4, stdin);
printf("size is %d\n, contents: %s\n",strlen(work_area), work_area);
exit(0);
}
