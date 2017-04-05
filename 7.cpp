#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

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
exit(0);
if(pid>0)
{
sleep(1);
system("ps u");
}
return(0);
}
