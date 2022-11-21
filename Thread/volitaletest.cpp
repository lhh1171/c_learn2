//
// Created by andilyliao on 17-2-5.
//
#include <stdio.h>
#include <sys/time.h>
#include <malloc.h>

int volitaletest1()
{
    struct timeval start,end;
    gettimeofday( &start, NULL );  /*测试起始时间*/
    double  timeuse;
    int volatile j;
//    int j;
    for(j=0;j<10000000;j++);
    gettimeofday( &end, NULL );   /*测试终止时间*/
    timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
    timeuse /= 1000000;
    printf("运行时间为：%f\n",timeuse);

    int ar[10];
    int* __restrict restar = (int*)malloc(10*sizeof(int));
    int*  par = ar;

    return 0;
}