//
// Created by andilyliao on 16-11-10.
//
#include <stdio.h>
#include <math.h>
#include <sched.h>
//对于进程的情况，一般是使用sched_setaffinity这个函数来实现
double waste_time(long n) {
    double res = 0;
    long i = 0;
    while (i < n * 200000) {
        i++;
        res += sqrt(i);
    }
    return res;
}

int affinity2() {
    cpu_set_t mask; /* processor 0 */
    CPU_ZERO(&mask);
    CPU_SET(1, &mask);
    /* bind process to processor 0 */
    if (sched_setaffinity(0, sizeof(mask), &mask) < 0) {
        perror("sched_setaffinity");
    }

    /* waste some time so the work is visible with "top" */
    printf("result: %f\n", waste_time(2000));

    CPU_ZERO(&mask);
    CPU_SET(2, &mask); /* process switches to processor 1 now */
    if (sched_setaffinity(0, sizeof(mask), &mask) < 0) {
        perror("sched_setaffinity");
    }

    /* waste some more time to see the processor switch */
    printf("result: %f\n", waste_time(2000));
}