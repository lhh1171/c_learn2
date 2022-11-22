#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//new 一个fd ,拿dup函数复制该fd，然后把fd给删除了，使用dup出的fd使用
int dup1()
{
    int fd, save_fd;
    char msg[] = "This is a test\n";
    fd = open("/opt/xxx", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    if(fd<0) {
        perror("open");
        exit(1);
    }
    //dup函数是用来打开一个新的文件描述符，指向和oldfd同一个文件，共享文件偏移量和文件状态。
    save_fd = dup(STDOUT_FILENO);
    //dup2函数，把指定的newfd也指向oldfd指向的文件，也就是说，执行完dup2之后，
    // 有newfd和oldfd同时指向同一个文件，共享文件偏移量和文件状态。
    dup2(fd, STDOUT_FILENO);
    close(fd);
    write(STDOUT_FILENO, msg, strlen(msg));
    dup2(save_fd, STDOUT_FILENO);
    write(STDOUT_FILENO, msg, strlen(msg)) ;
    close(save_fd);
    return 0;
}
