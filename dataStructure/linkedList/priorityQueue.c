#include<stdio.h>
#include<stdlib.h>

typedef struct {
int priority;
int data;
struct pnode* next;
}pnode;

pnode* node;

void insertPnode(int data,int priority);

int main(){
char data,priority;
int i=0;
while(i<3){
printf("instert data: ");
data=getchar();
data=atoi(&data);
getchar();
printf("insert priority: ");
priority=getchar();
priority=atoi(&priority);
getchar();

insertPnode(data,priority);
i++;
}
}

void insertPnode(int data,int priority){
node=malloc(sizeof(pnode));
printf("inserted!\n");


}
