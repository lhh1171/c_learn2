//
// Created by lqc on 2022/11/19.
//

#include <unistd.h>
#include <cstdio>
#include <thread>
#include <pthread.h>

//-lpthread

using namespace std;
int flag = 0;
long res = 0;


long fib(int x) {
    if (x < 2) {

        return x;

    }

    return fib(x - 1) + fib(x - 2);
}

void cal() {
    res = fib(42);
    flag = 1;
}


void show() {
    char c[] = {'\\', '/', '|', '-'};
    while (true) {
        if (flag != 0) {

            break;
        }
        for (char i : c) {
            printf("%c 计算中...\n", i);
            usleep(1000 * 200);
            system("clear");
        }
    }
}


void tm() {
    thread t1(show);
    thread t2(cal);
    t1.join();
    t2.join();
    printf("计算成功! \nfib的结果是 %d", res);
}
