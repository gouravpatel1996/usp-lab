#define POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<iostream>
using namespace std;
int main()
{
#ifdef _POSIX_JOB_CONTROL
cout<<"system support job control\n";
#else
cout<<"system doesnot support job control\n";
#endif

#ifdef _POSIX_SAVED_IDS
cout<<"System support saved set-UID and saved set-GID\n";
#else
cout<<"System  doesnot support saved set-UID and set-GID\n";
#endif

#ifdef _POSIX_CHOWN_RESTRICTED
cout<<"Chown restricted option is:"<<_POSIX_CHOWN_RESTRICTED<<endl;
#else
cout<<"system doesnt support Chown restricted option\n";
#endif

#ifdef _POSIX_NO_TRUNC
cout<<"Pathname truncation option is:"<<_POSIX_NO_TRUNC<<endl;
#else
cout<<"system doesnt support truncation option\n";
#endif

#ifdef _POSIX_VDISABLE
cout<<"the DISABLE character is:"<<_POSIX_VDISABLE<<endl;
#else
cout<<"system doesnot support _POSIX_VDISABLE\n";
#endif
return 0;
}
