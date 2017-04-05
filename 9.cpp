#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 
using namespace std;
int status;
int system(const char *cmd)
{
pid_t pid;
if(cmd==NULL)
return(1);
if((pid=fork())==-1)
{
status=-1;
}
if(pid==0)
{
execl("/bin/sh","sh","-c",cmd,NULL);
_exit(127);
}
if(pid>0)
{
while(waitpid(pid,&status,0)<0)
if(errno!=EINTR)
{
status=-1;
break;
}
}
return(status);
}
int main()
{

while(1)
{
cout<<"\nEnter Command to be executed, ctrl+c to terminate..";
int i=0;
char cmd[20];
while((cmd[i]=getchar())!='\n')
i++;
cmd[i]='\0';
system(cmd);
}
return 0;
}

