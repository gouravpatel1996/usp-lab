#include<iostream>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define INTERVAL 1
 void handle(int signo)
{
cout<<"alarm time out..."<<"signo is:"<<".....\n";
alarm(INTERVAL);
getchar();
}
int main()
{
struct sigaction act;
sigemptyset(&act.sa_mask);
act.sa_handler=handler;
act.sa_flags=SA_RESTART;
sigaction(SIGALRM,&act,0);
alarm(INTERVAL);
while(1);
cout<<"\n hello";
}
