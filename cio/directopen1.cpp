

#define _GNU_SOURCE//第一步
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int direct_open1()
{
    char*buff=NULL;
    const char* fileName="/home/lqc/桌面/代码/程序例子_01_testiocpp_new/testio-cpp/testfile/direct.txt";
    int fd=0;

    /*
      第二步,使用posix_memalign分配内存
      因为直接IO直接往磁盘里读写数据,磁盘是块设备,以扇区为最小单位,大小为512个字节,需要内存边界对齐
      所以第二个参数设置成512,第三个参数需要满足是第二个参数的倍数等其他条件
    */
    posix_memalign((void**)&buff,512,512);

    strcpy(buff,"adfjaklsdjflkas;jfkasdjf\n");

    //第三步,文件打开方式必须加上O_DIRECT
    fd=open(fileName,O_RDWR|O_CREAT|O_APPEND|O_DIRECT,S_IRWXU|S_IRWXG|S_IRWXO);
    if(fd<0)
    {
        fprintf(stderr,"open file fail,reason:%s\n",strerror(errno));
        return -1;
    }
    for(int i=0;i<10;i++)
    {
        int len=0;
        /*
          写入的字符可能需要是512的倍数
            (根据硬件吧或者其他情况,因为我看别人写入其他数量的字符也成功了,但是我就失败了,"invalid parameter")
          如果是read,则文件大小要是512的倍数，可以使用"truncate -s 大小 文件名"来指定文件大小
      */
        if((len=write(fd,buff,512))<0){
            fprintf(stderr,"write error,reason:%s\n",strerror(errno));
        }else{
            printf("%d\n",i);
        }
    }
    if(buff)
    {
        free(buff);
        buff=NULL;
    }
    sleep(10);//等到写入
    close(fd);
    return 0;
}