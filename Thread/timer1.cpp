//
// Created by andilyliao on 16-11-14.
//

#include <stdlib.h>
#include <iostream>
#include <sys/timeb.h>
#include <stdio.h>
#include <fstream>
#include <sys/time.h>
#include "../constutil.h"
using namespace std;


long long getSystemTime() {
    struct timeb t;
    ftime(&t);
    return 1000 * t.time + t.millitm;
}

int timer1()
{
    int i=0;
    struct timeval start1, end1;
    gettimeofday( &start1, NULL );
    long long start=getSystemTime();
    cout<<start<<endl;
    for(i=0;i<100000;i++)
    {
////        printf("a\n");
//        cout<<"a"<<endl;
    }
//    ofstream file(TESTOUTPATH, ios::ate);
//    for(i=0;i<100000;i++) {
//        file << "Hello World, fromwww.cpp-home.com and Loobian!";
//    }
//    file.flush();
    long long end=getSystemTime();
    gettimeofday( &end1, NULL );
    int timeuse = 1000000 * ( end1.tv_sec - start1.tv_sec ) + end1.tv_usec -start1.tv_usec;
    printf("time: %d us\n", timeuse);
    cout<<"time: "<<end-start<<" ms"<<endl;


    return 0;
}

