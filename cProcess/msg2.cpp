
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <mqueue.h>
#include <fcntl.h>
#include <errno.h>
#include<sys/stat.h>
#include <cstring>

typedef unsigned int  uint_t;

int msg2()
{
    mqd_t   mqd;
    char    *ptr;
    size_t  len=100;
    uint_t  prio=10;
    mqd = mq_open("/test2",O_RDWR|O_CREAT,S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH,NULL);
    ptr = (char *)calloc(len,sizeof(char));
    strcpy(ptr,"hello!");
    if(mq_send(mqd,ptr,len,prio) == -1)
    {
        perror("mq_send() error:");
        exit(-1);
    }
    exit(0);
}

int msg2rev()
{
    int     c,flags;
    mqd_t   mqd;
    ssize_t n;
    uint_t  prio;
    char *buff;
    struct mq_attr attr;

    flags = O_RDONLY;

    mqd = mq_open("/test2",flags);
    mq_getattr(mqd,&attr);
    buff = (char *)malloc(attr.mq_msgsize);
    if((n = mq_receive(mqd,buff,attr.mq_msgsize,&prio)) == -1)
    {
        perror("mq_receive error: ");
        exit(-1);
    }
    printf("read %ld bytes,priority = %u %s\n",(long) n,prio,buff);
    exit(0);
}

