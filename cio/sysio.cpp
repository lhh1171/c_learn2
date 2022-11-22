/*
以下三个常数中必须指定一个,且仅允许指定一个。
O_RDONLY 只读打开
O_WRONLY 只写打开
O_RDWR 可读可写打开

以下可选项可以同时指定0个或多个,和必选项按位或起来作为flags参数
O_APPEND 表示追加。如果文件已有内容,这次打开文件所写的数据附加到文件的末尾而
            不覆盖原来的内容。
O_CREAT 若此文件不存在则创建它。使用此选项时需要提供第三个参数mode,表示该
            文件的访问权限。
O_EXCL 如果同时指定了O_CREAT,并且文件已存在,则出错返回。
O_TRUNC 如果文件已存在,并且以只写或可读可写方式打开,则将其长度截断
            (Truncate)为0字节。
O_NONBLOCK 对于设备文件,以O_NONBLOCK方式打开可以做非阻塞I/O(Nonblock
        I/O)。
 */

/*
 * 文件权限计算方法  umask（设置是umask 022）
 * 通过这个命令可以得到如022的结果
 * 然后用open的mode掩码创建666的权限
 * 最后得到的文件权限是666-022=644
 */
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MSG_TRY "try again\n"
int sysio()
{
    char buf[10];
    int fd, n;
    fd = open("/dev/tty", O_RDONLY|O_NONBLOCK);//必须在真实终端运行，否则报错
    if(fd<0) {
        perror("error!!!aaaaaa");
        exit(1);
    }
    tryagain:
    n = read(fd, buf, 10);
    if (n < 0) {
        if (errno == EAGAIN) {
            sleep(1);
            write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
            goto tryagain;
        }
        perror("read /dev/tty");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);
    close(fd);
    return 0;
}