#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
/*
 * ioctl用于向设备发控制和配置命令，有些命令也需要读写一些数据，
 * 但这些数据是不能用read/write读写的，称为Out-of-band数据。
 * 也就是说，read/write读写的数据是in-band数据，是I/O操作的主体，
 * 而ioctl命令传送的是控制信息，其中的数据是辅助的数据。
 *
 * 在串口线上收发数据通过read/write操作，
 * 而串口的波特率、校验位、停止位通过ioctl设置，A/D转换的结果通过read读取，而A/D转换的精度和工作频率通过ioctl设置。
 */
int ioctl1()//做服务端没啥用 ioctl一般做串口通信发布控制指令
{
    struct winsize size;
    if (isatty(STDOUT_FILENO) == 0) {// 检查设备
        exit(1);
    }
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size)<0) {//使用TIOCGWINSZ命令获得终端设备的窗口大小
        perror("error!!!");
        exit(1);
    }
    printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
    return 0;
}
