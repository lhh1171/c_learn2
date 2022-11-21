//
// Created by andilyliao on 16-11-24.
//

#include <iostream>
#include <time.h>
using namespace std;

timespec diff(timespec start, timespec end);
/*
which_clock参数解释

CLOCK_REALTIME:系统实时时间,随系统实时时间改变而改变,即从UTC1970-1-1 0:0:0开始计时,
                中间时刻如果系统时间被用户该成其他,则对应的时间相应改变

CLOCK_MONOTONIC:从系统启动这一刻起开始计时,不受系统时间被用户改变的影响

CLOCK_PROCESS_CPUTIME_ID:本进程到当前代码系统CPU花费的时间

CLOCK_THREAD_CPUTIME_ID:本线程到当前代码系统CPU花费的时间
 */
int timer2()
{
    timespec time1, time2;
    int i=0;
    int temp;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
//    237152823
//    122400174
    for(i=0;i<100000;i++)
    {
////        printf("a\n");
        cout<<"a"<<endl;
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;


    struct timespec time3 = {0, 0};
    clock_gettime(CLOCK_REALTIME, &time1);
    printf("CLOCK_REALTIME: %d, %d\n", time3.tv_sec, time3.tv_nsec);
    clock_gettime(CLOCK_MONOTONIC, &time1);
    printf("CLOCK_MONOTONIC: %d, %d\n", time3.tv_sec, time3.tv_nsec);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time3);
    printf("CLOCK_PROCESS_CPUTIME_ID: %d, %d\n", time3.tv_sec, time3.tv_nsec);
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time1);
    printf("CLOCK_THREAD_CPUTIME_ID: %d, %d\n", time3.tv_sec, time3.tv_nsec);

    printf("\n%d\n", time(NULL));

    return 0;
}

timespec diff(timespec start, timespec end)
{
    timespec temp;
    if ((end.tv_nsec-start.tv_nsec)<0) {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }
    return temp;
}