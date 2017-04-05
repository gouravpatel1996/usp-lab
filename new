#include<iostream>
#include<unistd.h>
#include<stdio.h>
using namespace std;
int main(int argc, char *argv[])
{
if(link(argv[1],argv[2])==-1)
perror("link error");
else
cout<<"link has been created with the name:"<<argv[2]<<endl;
return 0;
}
