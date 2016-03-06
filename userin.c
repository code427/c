#include <stdlib.h>
#include <stdio.h>
#define EOL 1 /* 行结束 */
#define ARG 2
#define AMPERSAND 3
#define SEMICOLON 4
#define MAXARG 512 /* 命令行参数个数的最大值 */
#define MAXBUF 512 /* 输入行的最大长度 */
#define FOREGROUND 0
#define BACKGROUND 1

static char special[]={' ','\t','*',';','\n','\0'};
static char inpbuf[MAXBUF],tokbuf[2*MAXBUF],
*ptr =inpbuf,*tok=tokbuf;
/* userin()函数 */
int userin(char* p)
{

int c,count;
ptr=inpbuf;
tok=tokbuf;
/* 显示提示 */
printf("%s ",p);
for (count=0;;) {
if ((c=getchar())==EOF)
return(EOF);
if (count<MAXBUF)
inpbuf[count++]=c;
printf("count value: %d inpbuf[%d]=%c\nptr[%d]=%c\n",count,count-1,inpbuf[count-1],count-1,ptr[count-1]);
if (c =='\n' && count <MAXBUF) {
inpbuf[count]='\0';
printf("return count=%d\n",count);
return(count);
}
/* 如果行过长重新输入 */
if (c=='\n') {
printf("smallsh:input line too long\n");
count=0;
printf("%s ",p);
}
}}

inarg(char c)
{
char *wrk;
for (wrk=special;*wrk!='\0';wrk++)
if (c==*wrk)
return(0);
return(1);
}

gettok(char* output)
{
int type;
output=tok;
/* 首先去除空白字符 */
printf("inpbuf[0]=%c\nptr[0]=%c\n",inpbuf[0],ptr[0]);
for (;*ptr==' '||*ptr=='\t';ptr++);
*tok++=*ptr;
switch(*ptr++) {
case '\n':
type=EOL;break;
case '&':
type=AMPERSAND;break;
case ';':
type=SEMICOLON;break;
default:
type=ARG;
while (inarg(*inpbuf))
*tok++=*ptr++;
}
*tok++='\0';
printf("type: %d\n",type);
return (type);
}





procline()
{
char arg[MAXARG+1];
int toktype;
int narg;
int type;
printf("inside procline\n");
//ptr=inpbuf;
printf("inpbuf[0]=%c\nptr[0]=%c\n",inpbuf[0],ptr[0]);

for(narg=0;;) {

switch(toktype=gettok(&arg[narg])) {

case ARG:

if (narg<MAXARG)
narg++;
break;
case EOL:
case SEMICOLON:
case AMPERSAND:
type=(toktype==AMPERSAND)?
BACKGROUND:FOREGROUND;
if (narg!=0) {
arg[narg]=NULL;

runcommand(arg,type);
}
if (toktype==EOL)
return;
narg=0;
break;
}
}
}



runcommand(char** cline,int where)
{
int pid,exitstat,ret;
if((pid=fork())<0) {
perror("fork fail");
return(-1);
}
if (!pid) { /* 子进程代码 */
execvp(*cline,cline);
perror(*cline);
exit(127);
}
/* 父进程代码 */
/* 后台进程代码 */
if (where==BACKGROUND) {
printf("[process id %d]\n",pid);
return(0);
}
/* 前台进程代码 */
while ((ret=wait(&exitstat))!=pid && ret !=-1) ;
return (ret==-1?-1:exitstat);
}



char *prompt="command>";
main()
{
while (userin(prompt)!=EOF)
procline();
}



