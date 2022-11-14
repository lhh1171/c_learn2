
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
int exitecho1(){
    int i;
    while(true){
        std::cin>>i;
        if (i == 0)
            break;
    }
    return 10;
}

int exitecho2(){
    printf("using exit.\n");
    printf("This is the content in buffer");
    //_exit+flush
    exit(0);
}

int exitecho3(){
    printf("using _exit.\n");
    printf("This is the content in buffer");
    _exit(0);
}