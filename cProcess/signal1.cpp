
#include<unistd.h>
#include<cstdio>
#include<csignal>

void SignalHandler(int iSignNum)
{
    printf("capture signal number:%d\n",iSignNum);
    _exit(0);
}

int signal1()
{   // 程序运行Ctrl+c将不能终止，因为“Ctrl+c”产生的信号SIGINT(2)
    //将交给已经注册的自定义函数处理，“Ctrl+\”终止是因为它产生的SIGQUIT尚未在程序中注册
    //发送kill -2,执行函数
    signal(SIGINT,SignalHandler);
    while(1)
        sleep(1);
    return 0;
}

