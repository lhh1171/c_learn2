

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int holetest(){
    int fd;
    off_t offset;
    fd = creat("/opt/tmp.txt", 0777);   //创建一个权限为可读可写可执行的文件"tmp"
    if(-1 == fd){
        //如果出错返回-1
        perror("creat");
        return -1;
    }
    //偏移到最后写一个字节，这个文件一下就变大了
    //设置偏移的大小为1024ll*1024ll*1024ll,并偏移到文件尾//部
    offset = lseek(fd, 1024ll * 1024ll * 1024ll, SEEK_END);
    printf("offset = %d\n", offset);
    write(fd, "", 1);  //写空，写1个字节到文件描述符里
    close(fd);   //关闭文件描述符
    return 0;
}