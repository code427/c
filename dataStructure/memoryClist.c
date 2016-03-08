//memory management, two lincked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//declaration of linked list
struct clist {
int data;
struct clist* next;
};
typedef struct clist cnode;
typedef cnode* clink;

//allocate node to data list from memory list
clink nodeAlloc(clink* memory){

// while(1){printf(" first time nodeAlloc verify  memory is a loop:%d \n",*memory);fflush(stdout);sleep(1);*memory=(*memory)->next;}
clink new_node;
clink ptr;

if(((*memory)!=NULL)&&(((*memory)->next)!=*memory)){
ptr=(*memory)->next; //put the address of cnode 1 into ptr (*memory points to cnode 0)
(*memory)->next=(*memory)->next->next;
ptr->next==NULL; // when there are two node left, one more node alloc will left one node point to itself, and (*memory)->next will never NULL, therefore add a NULL test
// while(1){printf(" after first time nodeAlloc verify  memory removed one node :%d \n",*memory);fflush(stdout);sleep(1);*memory=(*memory)->next;}
return ptr;
}
else if((*memory)->next==(*memory)) //free last node in  memory 
{
printf("last node address is %d\n", *memory);fflush(stdout);sleep(5);
}
else { 
new_node=(clink)malloc(sizeof(cnode));
return new_node;
}
}

//free node from data list to memory list
void freeNode(clink *memory, clink ptr){

if(*memory==NULL){ //form a loop
ptr->next=(*memory);
(*memory)=ptr;
ptr->next=(*memory);

}
else{ //insert data list node into memory list loop
clink memory_next;
memory_next=(*memory)->next;
(*memory)->next=ptr;
ptr->next=memory_next;

}

}

void printClist(clink head){
clink ptr=head;
printf("content: ");
do{
printf("%d, ",ptr->data);
ptr=ptr->next;
} while(head!=ptr);
printf("\n");
}

//create memory list based on array
clink createClist(int *array,clink *memory, int len){
clink head;
clink before;
clink new_node;
int i;

head=nodeAlloc(memory);

head->data=array[0];
before=head;

for(i=1;i<len;i++){
new_node=nodeAlloc(memory);
new_node->data=array[i];
before->next=new_node;
before=new_node;
}

//is while(1){printf(" after nodeAlloc  verify  memory is a loop:%d \n",*memory);fflush(stdout);sleep(1);*memory=(*memory)->next;}

new_node->next=head; //loop list

// is not while(1){printf(" before return verify  memory is a loop:%d \n",*memory);fflush(stdout);sleep(1);*memory=(*memory)->next;}
return head;

}

//release entire data list to memory list by joining two loops
void freeClist (clink head, clink *memory){

// while(1){printf("before free  list there left only one node in memory:%d \n",*memory);fflush(stdout);sleep(1);*memory=(*memory)->next;}
//while(1){printf("before free  list there left six node in data loop:%d \n",head);fflush(stdout);sleep(1);head=head->next;}
 
clink head_next;
clink memory_next=(*memory)->next;
if(head!=NULL){
if((*memory)->next==*memory){clink head_next=head->next;head->next=*memory;(*memory)->next=head_next;}
else{head->next=memory_next;
(*memory)->next=head;
}}
clink temp=(*memory);do{printf("memory content after free Clist%d\n",temp->data);temp=temp->next;fflush(stdout);sleep(1);}while(1);
}

void main(){
clink head=NULL;
clink memory=NULL;
clink ptr;
int list[6]={1,2,3,4,5,6};
int i;
//create memory list by creating and freeing node
for(i=0;i<7;i++){
printf("loop count %d",i);
ptr=(clink)malloc(sizeof(cnode));
ptr->data=100+i;
freeNode(&memory,ptr);
}


printf("memory list: \n");
printClist(memory);

// is while(1){printf("before create Clist verify  memory is a loop:%d \n",memory);fflush(stdout);sleep(1);memory=(memory)->next;}
head=createClist(list,&memory,6);

// not while(1){printf("after create Clist verify  memory is a loop:%d \n",memory);fflush(stdout);sleep(1);memory=(memory)->next;}
printf("data list: ");
printClist(head);
freeClist(head,&memory);
printf("memory after free data list: ");
printClist(memory);
}
