
#include<cstdio>
#include<csignal>
#include<sys/types.h>
#include<unistd.h>
//gcc -pthread -o outfile.out signal2.cpp  用这个编译
void SigRoutine(int iSignNum)
{
    switch(iSignNum)
    {
        case 1:
            printf("capture SIGHUP signal, signal number is %d\n",iSignNum);
            break;
        case 2:
            printf("capture SIGINT signal, signal number is %d\n",iSignNum);
            break;
        case 3:
            printf("capture SIGINT signal, signal number is %d\n",iSignNum);
            break;
    }

}

//注册多个信号
int signal2()
{
    printf("process ID is %d\n",getpid());
    if(signal(SIGHUP,SigRoutine) == SIG_ERR)
    {
        printf("coundn't register signal handler for SIGHUP");
    }

    if(signal(SIGQUIT,SigRoutine) == SIG_ERR)
    {
        printf("coundn't register signal handler for SIGQUIT");
    }else{
        printf("xxxxxx\n");
    }
    if(signal(SIGINT,SigRoutine) == SIG_ERR)
    {
        printf("coundn't register signal handler for SIGINT");
    }
    while(1)
        sleep(1);
    return 0;
}

