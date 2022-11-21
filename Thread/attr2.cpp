//
// Created by andilyliao on 16-11-10.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
void * tfn1(void * arg){
    printf("the sub thread sleeping for 5 seconds\n");
    sleep(5);/*休眠5秒钟，等待主线程将该线程设置为分离状态*/
    printf("the thread done\n");
    while (true)
    {
        sleep(1);
        printf("thread1 running...!\n");
    }
    return NULL;
}
int attr2(){
    int iRet;
    pthread_t tid;
    /*创建一个线程，这个线程和结束状态是分离的 */
    iRet = pthread_create(&tid, NULL, tfn1, NULL);

    if(iRet){
        printf("can't create thread %s\n", strerror(iRet));
        return iRet;
    }
    /*设置线程为分离状态 */
    iRet = pthread_detach(tid);
    if(iRet){
        printf("can't detach thread  %s\n", strerror(iRet));
        return iRet;
    }
    iRet = pthread_join(tid, NULL);
    /*由于状态分离，因此得不到线程的结束状态信息，此函数会出错 */
    if(iRet){
        printf("thread has been detached\n");
    }
    printf("the main thread sleeping for 8 seconds\n");
    sleep(8);
    printf("the main thread done.\n");
    //现成一旦被分离，主线程退出，只要保证不要return，子线程是不会死亡的
    pthread_exit(0);
    return 0;
}