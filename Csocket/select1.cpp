//
// Created by andilyliao on 16-12-6.
//

#include <sys/time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/select.h>
int select1(){
    int keyboard;
    int ret,i;
    char c;
    fd_set readfd;
    struct timeval timeout;
    keyboard = open("/dev/tty1",O_RDONLY | O_NONBLOCK);//必须用真实的终端，clion这个有问题
    assert(keyboard>0);
    while(1){
        timeout.tv_sec=1;
        timeout.tv_usec=0;
        FD_ZERO(&readfd);   //清空fd列表
        FD_SET(keyboard,&readfd);  //设置需要监听的fd  本例为keyboard这个fd
        ret=select(keyboard+1,&readfd,NULL,NULL,&timeout); //通过select方法获取有事件的fd （注意：必须是最大fd+1）
        if(FD_ISSET(keyboard,&readfd)) {
            //判断监听的fd是否有事儿发生
            i=read(keyboard,&c,1);
            if('\n'==c)
                continue;
            printf("The input is %c\n",c);
            if ('q'==c)
                break;
        }
    }
    return 0;
}