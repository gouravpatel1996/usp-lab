#include<unistd.h>
#include<sys/types.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void fun(char *str)
{
int i=0;
while (str[i]!='\0')
{
cout<<str[i];
i++;
}
}
int main(void)
{
pid_t pid;
if((pid=fork())==-1)
{
perror("fork");
return 0;
}
if(pid==0)
fun("output from child\n");
if(pid>0)
fun("output from parent\n");
exit(0);
}

