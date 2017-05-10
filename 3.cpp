#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(int argc,char *argv[])
{
struct flock fvar;
int fdisc;
if((fdisc=open(argv[1],O_RDWR))==-1)
{
perror("open");
return -1;
}
fvar.l_type=F_WRLCK;
fvar.l_whence=SEEK_END;
fvar.l_start=-100;
fvar.l_len=100;
fvar.l_pid=getpid();
if(fcntl(fdisc,F_SETLK,&fvar)==-1)
{
perror("fcntl");
return-1;
}
if(fcntl(fdisc,F_GETLK,&fvar)!=1)
cout<<"\n file has been locked,locked by the process having the PID"<<fvar.l_pid;
fvar.l_type=F_UNLCK;
fvar.l_whence=SEEK_END;
fvar.l_start=-50;
fvar.l_len=50;
if(fcntl(fdisc,F_SETLK,&fvar)==-1)
{
perror("fcntl");
return-1;
}
cout<<"\n successfully unlock the last"<<fvar.l_len<<"bytes of data\n";
char buf[2];
lseek(fdisc,-50,SEEK_END);
cout<<"\n last 50 bytes of data of the file"<<argv[1]<<"is as follows"<<endl;
while(read(fdisc,buf,1)>0)
write(1,buf,1);
return 0;
}
