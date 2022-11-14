
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int execve1()
{
    char *args[] = {"bash","/opt", NULL};
    //成功会jump到其他代码段
    //execve()函数从disk把ls挂载在虚拟地址，并且通过jump调到这个虚拟地址
    //成功就执行ls,失败才执行其他代码
    if(execve ("/bin/ls", args, NULL) == -1) {
        perror ("execve");
        exit(EXIT_FAILURE);
    }
    cout<<"这句是打印不出来的！！！！！！"<<endl;
}

int execve2(){
    system("echo a=1");
    setenv("a","99",1);
    putenv("USER=test");
}
