
#include<unistd.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define INPUT 0
#define OUTPUT 1

int pipe1() {
    int fd[2];
    /*定义子进程号 */
    pid_t pid;
    char buf[256];
    int returned_count;
    /*创建无名管道,他是一个阻塞管道*/
    pipe(fd);
    /*创建子进程*/
    pid=fork();
    //一个进程能在out里面写，一个进程就可以在in里面读
    if(pid<0) {
        printf("Error in fork\n");
        exit(1);
    }else if(pid == 0) { /*执行子进程*/
        printf("in the child process...\n");
        /*子进程向父进程写数据，关闭管道的读端*/
        close(fd[INPUT]);
        write(fd[OUTPUT], "hello", strlen("hello"));
        exit(0);
    }else { /*执行父进程*/
        printf("in the parent process...\n");
        /*父进程从管道读取子进程写的数据，关闭管道的写端*/
        close(fd[OUTPUT]);
        returned_count = read(fd[INPUT], buf, sizeof(buf));
        printf("%d bytes of data received from child process: %s\n", returned_count, buf);
    }

    return 0;
}