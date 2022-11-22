
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
全缓冲 如果缓冲区写满了就写回内核。常规文件通常是全缓冲的。
行缓冲 如果用户程序写的数据中有换行符就把这一行写回内核,或者如果缓冲区写满了就写回内
        核。标准输入和标准输出对应终端设备时通常是行缓冲的。
无缓冲 用户程序每次调库函数做写操作都要通过系统调用写回内核。标准错误输出通常是无缓冲
        的,这样用户程序产生的错误信息可以尽快输出到设备。

除了写满缓冲区、写入换行符之外,行缓冲还有一种情况会自动做Flush操作。如果:
    1、用户程序调用库函数从无缓冲的文件中读取
    2、或者从行缓冲的文件中读取,并且这次读操作会引发系统调用从内核读取数据
那么在读取之前会自动Flush所有行缓冲。
 */
int exit1()
{
    printf("hello world");
//    fflush(stdout);
//    fgetc(stdin);
    _exit(0);
//    exit(0);


}
