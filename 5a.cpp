#include<iostream>
#include<unistd.h>
using namespace std;
int main(int argc,char*argv[],char*env[])
{
for(int i=0;env[i]!='\0';i++)
cout<<"\n"<<env[i];
return 0;
}

