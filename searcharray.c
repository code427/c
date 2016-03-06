#include<stdio.h>
#include<stdlib.h>



int main(){

int scores[10]={12,45,64,78,58,96,46,89,97,54};
int invscores[101];
int i=0, index=-1;
for (i=0;i<=101;i++)
invscores[i]=-1;
int grade=-1;
for(i=0;i<=10;i++){

index=scores[i];
invscores[index]=i;

}
while(1){
printf("please enter a score to search:");
scanf("%d",&grade);
if(grade!=-1)
printf("id is %d\n",invscores[grade]);
else
exit(1);



}

}
