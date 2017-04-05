#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{int value;
 if((value=sysconf(_SC_CLK_TCK))==-1)
 perror("sysconf");
 else
 cout<<"number of clock ticks are:"<<value<<endl;
 if((value=sysconf(_SC_CHILD_MAX))==-1)
 perror("sysconf");
 else
 cout<<"max no.of child process are:"<<value<<endl;
 if((value=sysconf(_SC_OPEN_MAX))==-1)
 perror("sysconf");
 else
 cout<<"max no.of open files are:"<<value<<endl;
 if((value=pathconf("/",_PC_PATH_MAX))==-1)
 perror("pathconf");
 else
 cout<<"path lengths is:"<<(value+1)<<endl;
 if((value=pathconf("/",_PC_NAME_MAX))==-1)
 perror("pathconf");
 else
 cout<<"max no.of char in filename is:"<<(value+1)<<endl;
 return 0;
}

