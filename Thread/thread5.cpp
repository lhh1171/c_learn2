//
// Created by andilyliao on 17-2-15.
//
#include <pthread.h>
#include <iostream>
#include <zconf.h>
using namespace std;
void* thrd_start_routine(void* v)
{
    sleep(10);
    cout<<"created thread"<<endl;
}

int thread5()
{
    pthread_t thrdid;

    pthread_create(&thrdid, NULL, &thrd_start_routine, NULL);

    sleep(5);
    cout<<"main thread"<<endl;
    pthread_exit(NULL);
    return  0;
}

