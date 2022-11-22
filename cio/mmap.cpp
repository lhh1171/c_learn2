/*
prot参数有四种取值:
PROT_EXEC 表示映射的这一段可执行,例如映射共享库
PROT_READ 表示映射的这一段可读
PROT_WRITE 表示映射的这一段可写
PROT_NONE 表示映射的这一段不可访问

flag参数:
MAP_SHARED 多个进程对同一个文件的映射是共享的,一个进程对映射的内存做了修
                改,另一个进程也会看到这种变化。
MAP_PRIVATE 多个进程对同一个文件的映射不是共享的,一个进程对映射的内存做了修
                改,另一个进程并不会看到这种变化,也不会真的写到文件中去。
*/
#include <cstdlib>
#include <sys/mman.h>
#include <fcntl.h>
#include <cstdio>
#include <zconf.h>

#include <iostream>
using namespace std;
int mmap1()
{
    char *p;
    int fd = open("/opt/xxx", O_RDWR);
    if (fd < 0) {
        perror("open hello");
        exit(1);
    }
    p =(char *) mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    close(fd);
    p[0] = 'z';
    cout<<p[4]<<'\t'<<p[0]<<'\t'<<p+1<<endl;
    //先写在内存里，munmap之后写入磁盘
    munmap(p, 6);
    return 0;
}
