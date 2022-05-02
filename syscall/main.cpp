#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

void ls(){
    pid_t pid, pr;
    printf("hhh\n");
    pid = fork();
    //代表没fork成功，程序执行失败
    if (pid < 0){
        perror("fail to fork");
        exit(-1);
    }
    printf("lll\n");
    if (pid == 0){
        char *args[] = {"bash","./", NULL};
        //成功会jump到其他代码段
        if(execve ("/bin/ls", args, NULL) == -1) {
            perror ("execve");
            exit(EXIT_FAILURE);
        }
        cout<<"这句是打印不出来的！！！！！！"<<endl;
    }else if(pid>0){
        /* 如果是父进程 */
        do{
            pr=waitpid(pid, NULL, WNOHANG);
            /* 使用了WNOHANG参数，waitpid不会在这里等待 */
            if(pr==0){ /* 如果没有收集到子进程 */
                printf("No child exited\n");
                sleep(1);
            }
        }while(pr==0); /* 没有收集到子进程，就回去继续尝试 */
        if(pr==pid)
            printf("successfully get child %d\n", pr);
        else
            printf("some error occured\n");
    }
}
void echo(string s){
    pid_t pid,pr;
    pid = fork();
    //代表没fork成功，程序执行失败
    if (pid < 0){
        perror("fail to fork");
        exit(-1);
    }
    if (pid == 0){
        char *args[] = {"bssh",(char *)s.substr(5,s.length()).c_str(), NULL};
        //成功会jump到其他代码段
        if(execve ("/bin/echo", args, NULL) == -1) {
            perror ("execve");
            exit(EXIT_FAILURE);
        }
        cout<<"这句是打印不出来的！！！！！！"<<endl;
    }else if(pid>0){
        /* 如果是父进程 */
        do{
            pr=waitpid(pid, NULL, WNOHANG);
            /* 使用了WNOHANG参数，waitpid不会在这里等待 */
            if(pr==0){ /* 如果没有收集到子进程 */
                printf("No child exited\n");
                sleep(1);
            }
        }while(pr==0); /* 没有收集到子进程，就回去继续尝试 */
        if(pr==pid)
            printf("successfully get child %d\n", pr);
        else
            printf("some error occured\n");
    }
}

int main() {
    string s;
    getline(cin,s);
    while (true){
        if (s==("quit")){
            cout<<"bye"<<endl;
            break;
        }
        if (s=="ls"){
            //得单独开个进程来跑他
            ls();
        }
        if (s.substr(0,4)=="echo"){
            echo(s);
        }
        getline(cin,s);
    }
    return 0;
}