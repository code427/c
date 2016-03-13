//linked list loop,queue,stack,memory allocation, etc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaration of linked list
struct clist {
int data;
struct clist* next;
};
typedef struct clist cnode;
typedef cnode* clink;

//memory loop
void initializeMemory();
void memoryLink();
clink nodeAlloc(clink* memory);
void freeNode(clink *memory, clink* ptr);
void printClist(clink head);
clink createClist(int *array,clink *memory, int len);
void freeClist (clink head, clink *memory);

clink head=NULL;
clink memory=NULL;

//stack
void stackFunc();
void push();
void pop();
void peek();

clink stack=NULL;

//queue
void queueFunc();
void insert();
void delete();
void freeNextNode();

clink queue=NULL;

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
clink lastMem=(*memory);
return lastMem;
(*memory)==NULL;
}
else {
new_node=(clink)malloc(sizeof(cnode));
return new_node;
}
}

//free node from data list to memory list
void freeNode(clink *memory, clink* ptr){
clink tmp=NULL;
clink originStack=(*ptr);
clink swap;
int last=0;
//test if *ptr is the last link
if((*ptr)->next==(*ptr))last=1;
/*printf("inside freeNode show stack\n"); 
int j=1;
if(stack!=NULL){
clink sti;
sti=stack;
while(++j<10&&(stack->next!=NULL)){printf("%d at %d \n", sti->data,sti);sti=sti->next;fflush(stdout);}
}
*/
tmp=(*ptr)->next;

//if(tmp!=NULL){printf("tmp is %d at %d",tmp->data,tmp);fflush(stdout);sleep(1);}

if(*memory==NULL){ //form a loop
(*ptr)->next=(*ptr);
(*memory)=(*ptr);
}

else{ //insert data list node into memory list loop

swap=*ptr;
if(swap->next!=NULL){
while(swap->next!=originStack){swap=swap->next;}
//printf("last is %d at %d\n",swap->data,swap);fflush(stdout);sleep(1);
//swap->next=(*ptr);
}

clink memory_next;
memory_next=(*memory)->next;
(*memory)->next=(*ptr);
(*ptr)->next=memory_next;
//printf("before assign swap is %d at %d\n",swap->data,swap);fflush(stdout);sleep(1);
//printf("before assign tmp is %d at %d\n",tmp->data,tmp);fflush(stdout);sleep(1); 
if(tmp!=NULL) swap->next=tmp;
}
(*ptr)=tmp;
//if((*ptr)!=NULL){printf("ptr is %d at %d",(*ptr)->data,(*ptr));fflush(stdout);sleep(1);}
//if((*ptr)!=NULL){printf("stack is %d at %d",stack->data,stack);fflush(stdout);sleep(1);}
if(last) *ptr=NULL;
}

void printClist(clink head){
if(head==NULL)
	printf("nothing to display");
else{
clink ptr=head;
printf("content: ");

do{
printf("%d, ",ptr->data);
fflush(stdout);sleep(1);
ptr=ptr->next;
} while(head!=ptr&&(ptr!=NULL));
printf("\n");
}}

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

new_node->next=head; //loop list
return head;
}

//release entire data list to memory list by joining two loops
void freeClist (clink head, clink *memory){

// while(1){printf("before free  list there left only one node in memory:%d \n",*memory);fflush(stdout);sleep(1);*memory=(*memory)-//while(1){printf("before free  list there left six node in data loop:%d \n",head);fflush(stdout);sleep(1);head=head->next;}}

clink head_next;
clink memory_next=(*memory)->next;
if(head!=NULL){
        if((*memory)->next==*memory){
        clink head_next=head->next;
        head->next=*memory;
        (*memory)->next=head_next;}

        else{head->next=memory_next;
        (*memory)->next=head;
        }
}
//clink temp=(*memory);do{printf("memory content after free Clist%d\n",temp->data);temp=temp->next;fflush(stdout);sleep(1);}while(1);
}

void push(){

char input[512];
printf("enter an number to push: ");
fgets(input,sizeof(input),stdin);
while(input[0]=='\n'){
fgets(input,sizeof(input),stdin);}
printf("get string %s",input);
input[strlen(input)-1]='\0';
clink tmp;
tmp=nodeAlloc(&memory);
tmp->next=NULL;
tmp->data=atoi(input);
if(stack==NULL){
	tmp->next=tmp;
	stack=tmp;
}
else if(stack->next==stack){
	tmp->next=stack;
	stack->next=tmp;
	stack=tmp;
}
else if(stack==stack->next->next){
	stack->next->next=tmp;
	tmp->next=stack;
	stack=tmp;
}
else {
	tmp->next=stack;
//link last node to tmp
	clink last=stack;
	while(last->next!=stack){
	last=last->next;
}
last->next=tmp;
stack=tmp;
}
printf("pushed %d\n",atoi(input));fflush(stdout);
} 

void pop(){
if(stack==NULL) {
	printf("nothing to pop\n");
}
//one left
else if(stack->next==stack) {
	freeNode(&memory,&stack);
	stack=NULL;
}
//two left
else if(stack==stack->next->next){
	freeNode(&memory,&stack);
	stack->next=stack;
}
//at least three
else
{
	freeNode(&memory,&stack);
}
}

void peek(){
if(stack!=NULL)
printf("top of stack is %d\n",stack->data);
else printf("nothing to peek\n");
}

void initializeMemory(){
clink ptr;
int i;
printf("create memory list by creating and freeing node..\n");fflush(stdout);sleep(1);
for(i=0;i<7;i++){
ptr=(clink)malloc(sizeof(cnode));
ptr->data=100+i;
freeNode(&memory,&ptr);
}}

void insert(){

char input[512];
printf("enter an numbe to insertr: ");
fgets(input,sizeof(input),stdin);
while(input[0]=='\n'){
fgets(input,sizeof(input),stdin);}
printf("get string %s",input);
input[strlen(input)-1]='\0';

if(memory==NULL)initializeMemory();

clink new=nodeAlloc(&memory);

new->data=atoi(input);
if(queue==NULL){
new->next=new;
}
else if(queue->next==queue){
queue->next=new;
new->next=queue;
}
else {
new->next=queue->next;
queue->next=new;
}
queue=new;
}

void delete(){
freeNextNode();
}

void freeNextNode(){
freeNode(&memory,&(queue->next));
}

void main(){
//char *option X 
char option[1];
do{
printf("0.Quit\n");
printf("1.memory management, two lincked list loop\n");
printf("2.Stack\n");
printf("3.Queue\n");
printf("\n");

//reads one less than the number, here 2-1=1 
fgets(option,2,stdin);
while(option[0]=='\n'){
fgets(option,2,stdin);
}
switch(atoi(option)){
case 0:return;
case 1:memoryLink();break;
case 2:stackFunc();break;
case 3:queueFunc();break;
}}
while(atoi(option)!=0); 
}

void memoryLink(){
initializeMemory();

int list[6]={1,2,3,4,5,6};
printf("memory list ");
printClist(memory);fflush(stdout);sleep(1);
printf("create data list by allocating memory list..\n");fflush(stdout);sleep(1);
head=createClist(list,&memory,6);
printf("data list ");
printClist(head);fflush(stdout);sleep(1);
printf("free entire data list to memory..\n");fflush(stdout);sleep(1);
freeClist(head,&memory);
printf("after free data list memory list ");
printClist(memory);
}


void stackFunc() {
int choice;
initializeMemory();
        
        while(1)
        {
         printf("0.return\n");
         printf("1.push\n");
         printf("2.pop\n");
         printf("3.peek\n");
         printf("4.display\n");
         scanf("%d",&choice);   

         switch(choice)
               {
                case 0: return;
                case 1: push();break;
                case 2: pop();break;
                case 3: peek();break;
                case 4: printClist(stack);break;
                }
        }


}

void queueFunc(){
int choice;
while(1)
        {
         printf("0.quit\n");
         printf("1.insert\n");
         printf("2.delete\n");
         printf("3.display\n");
         scanf("%d",&choice);

         switch(choice)
               {
                case 0: return;
                case 1: insert();break;
                case 2: delete();break;
                case 3: printClist(queue->next);break;//queue points to the end
                }
        }
}
