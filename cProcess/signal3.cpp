
#include<cstdio>
#include<csignal>
#include<sys/types.h>
#include<unistd.h>

void Handler(int i)
{
    printf("signal handler ..\n");
}

int signal3()
{
    int i;
    signal(SIGALRM,Handler);
    // alarm专门为SIGALRM信号而设，使系统在一定时间后发送信号,定时信号
    alarm(5);
    for(i=1;i<=10;i++)
    {
        sleep(1);
        printf("sleep %ds\n",i);
    }
    return 0;
}

