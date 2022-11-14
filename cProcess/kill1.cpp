
#include <csignal>
int kill1()
{   // 程序运行Ctrl+c将不能终止，因为“Ctrl+c”产生的信号SIGINT
//将交给已经注册的自定义函数处理，“Ctrl+\”终止是因为它产生的SIGQUIT尚未在程序中注册
    __pid_t pid=0;
    kill(15829,SIGINT);
    return 0;
}
