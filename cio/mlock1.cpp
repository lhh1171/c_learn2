#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include <zconf.h>

const int alloc_size = 32 * 1024 * 1024;//分配32M内存
int mlcok1()
{
    char *memory = static_cast<char *>(malloc(alloc_size));
    //这块内存不会被换掉,不会swap
    if(mlock(memory,alloc_size) == -1) {
        perror("mlock");
        return (-1);
    }
    size_t i;
    size_t page_size = getpagesize();
    for(i=0;i<alloc_size;i+=page_size) {
        printf("i=%zd\n",i);
        memory[i] = 0;
    }
    if(munlock(memory,alloc_size) == -1) {
        perror("munlock");
        return (-1);
    }
    return 0;
}