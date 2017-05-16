#include<iostream>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#define INTERVAL 1
using namespace std;
 void handler(int signo)
{
cout<<"alarm time out..."<<"signo is:"<<signo<<".....\n";
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
while(1)
cout<<"\n hello";
}
