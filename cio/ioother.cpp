
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <cstring>

int ioother1()
{
    char str[13]="abc def ghi";
    int fdo=open("/dev/reverse",O_RDWR);
    write(fdo,str,strlen(str));
    read(fdo,str,strlen(str));
    printf(str);
    return 0;
}
