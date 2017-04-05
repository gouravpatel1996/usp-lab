#include<iostream>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
using namespace std;
int main(int argc, char* argv[])
{
int fd,n;
char buf[256];
if((mkfifo(argv[1],S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO))==-1)
{
perror("mkfifo");
return-1;
}
else
cout<<"\n fifo has been created with the name:"<<argv[1];
if((fd=open(argv[1],O_RDWR|O_NONBLOCK))==-1)
{
perror("open");
return-1;
}
else
cout<<"\n fifo is opened successfully\n";
if((n=write(fd,argv[2],strlen(argv[2])))==-1)
{
perror("write");
return-1;
}
else
cout<<"\n successfully writes data to the fifo\n";
if(read(fd,buf,n)==-1)
{
perror("read");
return-1;
}
else
{
cout<<"fifo contents are:\n";
write(1,buf,n);
cout<<endl;
}
close(fd);
return 0;
}
