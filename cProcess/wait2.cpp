
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
int wait2(){
    /*fork一个子进程*/
    pid_t pid = fork();
    if(pid<0){
        perror("fork error\n");
        return 0;
    }else if(pid > 0){
        /*父进程*/
        printf("Parent process\n");
        int status=-1;
        //同步回收，父亲一直等着子，回收子,拿状态(子怎么死的)
        pid_t pr=wait(&status);
        if(WIFEXITED(status)){
            printf("the child process %d exit normally.\n",pr);
            printf("the return code is %d.\n",WEXITSTATUS(status));//WEXITSTATUS可以获取返回值
        }else{
            printf("the child process %d exit abnormally.\n",pr);
        }
    }else if(pid == 0){
        printf("Sub-process, PID: %u, PPID: %u\n", getpid(), getppid());
        exit(3);
    }
    return 0;
}