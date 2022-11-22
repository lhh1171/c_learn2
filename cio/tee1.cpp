#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

//把管道的数据扔给其他管道
int tee1(){
    int fd1 = open("/opt/yyy1", O_RDONLY);
    int fd2 = open("/opt/yyy2", O_RDWR| O_CREAT | O_TRUNC, 0666);
    int fd3 = open("/opt/yyy3", O_RDWR| O_CREAT | O_TRUNC, 0666);
    /*用于向"./2.txt"输入数据*/
    int pipefd2[2];
    /*用于向"./3.txt"输入数据*/
    int pipefd3[2];
    pipe(pipefd2);
    pipe(pipefd3);

    /*将fd1文件的内容输入管道pipefd2中*/
    splice(fd1, NULL, pipefd2[1], NULL, 10086, SPLICE_F_MORE);
    /*将管道pipefd2的内容复制到管道pipefd3中，不消耗管道pipefd2上的数据，管道pipefd2上的数据可以用于后续操作*/
    tee(pipefd2[0], pipefd3[1], 10086, SPLICE_F_NONBLOCK);
    /*将管道pipefd2的内容写入fd2文件中*/
    splice(pipefd2[0], NULL, fd2, NULL, 10086, SPLICE_F_MORE);
    /*将管道pipefd3的内容写入fd3文件中*/
    splice(pipefd3[0], NULL, fd3, NULL, 10086, SPLICE_F_MORE);

    close(fd1);
    close(fd2);
    close(fd3);
    close(pipefd2[0]);
    close(pipefd2[1]);
    close(pipefd3[0]);
    close(pipefd3[1]);
    return 0;
}