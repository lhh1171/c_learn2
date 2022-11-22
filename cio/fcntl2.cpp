
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int fcntl2()
{
    int val;
    if ((val = fcntl(0, F_GETFL)) < 0) {
        printf("fcntl error for fd %d\n", 0);
        exit(1);
    }
    switch(val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read write");
            break;
        default:
            fputs("invalid access mode\n", stderr);
            exit(1);
    }
    if (val & O_APPEND)
        printf(", append");
    if (val & O_NONBLOCK)
        printf(", nonblocking");
    putchar('\n');
    return 0;
}
