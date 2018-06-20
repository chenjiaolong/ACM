#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <malloc.h>
#include <process.h>
#include <sys\stat.h>
int main(void)
{
    void* buf ;
    int handle;
    int bytes ;
    buf=malloc(100000);
    /*
    Looks for a file in the current directory named TEST.$$$ and attempts
    to read 100000 bytes from it.To use this example you should create the
    file TEST.$$$
    */
    handle=open("TEST.$$$",O_RDONLY|O_BINARY,S_IWRITE|S_IREAD);
    if(handle==-1)
    {
        printf("Error Opening File\n");
        exit(1);
    }
    bytes=read(handle,buf,100000);
    if(bytes==-1)
    {
        printf("Read Failed.\n");
        exit(1);
    }
    else
        printf("Read:%d bytes read.\n",bytes);
    return 0 ;
}

