#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int execve1()
{
    char *args[] = {"bash","/opt", NULL};
    //成功会jump到其他代码段
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
int main() {
    execve2();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}