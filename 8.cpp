#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
using namespace std;
int main(void)
{
pid_t pid;
if((pid=fork())==-1)
{
perror("fork");
return 0;
}
if(pid==0)
{
if((pid=fork())==-1)
{
perror("fork error");
return-1;
}
if(pid>0)
{
sleep(2);
exit(0);
}
}
if(pid>0)
{
if(waitpid(pid,NULL,0)!=pid)
perror("waitpiderror");
system("ps u");
}
return 0;
}
