
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
int fork1(){
    pid_t pid;
    printf("hhh\n");
    int a=1;
    //这不是pid,只是pid调用的标志
    pid = fork();
    //代表没fork成功，程序执行失败
    if (pid < 0){
        perror("fail to fork");
        exit(-1);
    }

    if (pid == 0){
        a+=1;
        printf("%d\n",a);
        /*子进程*/
        printf("Sub-process, PID: %u, PPID: %u\n", getpid(), getppid());
        sleep(20);
    }else{/*父进程*/
        printf("%d\n",a);
        printf("Parent, PID: %u, Sub-process PID: %u\n", getpid(), pid);
        sleep(20);
    }
    return 0;
}
