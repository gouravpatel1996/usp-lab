#define _posix_source
#define _posix_c_source 199309l
#include<stdio.h>
#include<unistd.h>
using namespace std;
int main()
{
int value;
if((value=sysconf(_sc_clk_tck))==-1)
perror("sysconf");
else
cout<<"no of clock ticks are:"<<value<<endl;
if((value=sysconf(_sc_child_max))==-1)
perror("sysconf");
else
cout<<"max number of child process are:"<<value<<endl;
if((value=sysconf(_sc_open_max))==-1)
perror("sysconf")
else
cout<<"max number of oipen files are:"<<value<<endl;
if((valueconf("/"_pc_path_max))==-1)
perror("pathconf");
else
cout<<"pathlength is:"<<(VALUE+1)<,ENDL;
if((value=pathconf("/",_pc_name_max))==-1)
perror("pathconf");
else
cout<<"max no of characters in file name is:"<<(value+1)<<endl;
return 0;
}
