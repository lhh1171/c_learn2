//
// Created by andilyliao on 16-11-10.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <zconf.h>

void * tfn1(void * arg){
    sleep(10);
    printf("the thread\n");
    return NULL;
}
int attr(){
    int iRet;
    pthread_t tid;
    pthread_attr_t attr;
    iRet = pthread_attr_init(&attr);
    if(iRet){
        printf("can't init attr %s/n", strerror(iRet));
        return iRet;
    }
    //设置分离属性
    iRet = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if(iRet){
        printf("can't set attr %s\n", strerror(iRet));
        return iRet;
    }
    iRet = pthread_create(&tid, &attr, tfn1, NULL);
    if(iRet){
        printf("can't create thread %s\n", strerror(iRet));
        return iRet;
    }
    //主线程不会等着
    iRet = pthread_join(tid, NULL);
    if(iRet){
        printf("thread has been detached\n");
        return iRet;
    }
    return 0;
}