
#include<cstdio>
#include<csignal>
#include<sys/types.h>
#include<unistd.h>

void SigHandler(int iSignNum)
{
    printf("signal:%d\n",iSignNum);
}

int signal4()
{
    signal(SIGALRM,SigHandler);
    alarm(5);
    printf("before pause \n");
    /*
     * 当程序运行时，pause会使当前的进程挂起（进入睡眠状态），
     * 直到我们向该进程发送SIGINT中断信号，进程才会被唤醒，
     * 并处理信号，处理完信号后pause函数才返回，并继续运行该程序。

      任何信号都可使pause唤醒。
     */
    pause();
    printf("after pause \n");
    return 0;
}


