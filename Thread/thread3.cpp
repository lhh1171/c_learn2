//
// Created by andilyliao on 16-11-10.
//
#include <stdio.h>
#include <pthread.h>
void* say_hello(void* args){
    int i=*(int*)args;
    printf("hello from thread,i=%d\n",i);
    pthread_exit((void*)1);
}
int thread3(){
    pthread_t tid;
    int para=10;
    int iRet = pthread_create(&tid, NULL, say_hello, &para);
    if (iRet){
        printf("error: iRet=%d\n",iRet);
        return iRet;
    }
    void *retval;
    iRet=pthread_join(tid,&retval);
    if (iRet){
        printf("error: iRet=%d\n",iRet);
        return iRet;
    }
    printf("retval=%ld\n",(long)retval);
    return 0;
}
