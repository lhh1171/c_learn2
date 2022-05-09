#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define MAXLINE 4096
int server1(){
    int  listenfd, connfd;
    struct sockaddr_in  servaddr;
    char  buff[4096];
    int  n;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        return 0;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//将主机的无符号长整形数转换成网络字节顺序。
    servaddr.sin_port = htons(6666);//将一个无符号短整型数值转换为网络字节序，即大端模式(big-endian)　

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        return 0;
    }

    if( listen(listenfd, 10) == -1){//第二个参数就是那个backlog
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        return 0;
    }

    printf("======waiting for client's request======\n");
    while(1){
        if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
            printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
            continue;
        }
        //0和read一样
        n = recv(connfd, buff, MAXLINE, 0);
        printf("the n is %d\n",n);
        buff[n] = '\0';
        printf("recv msg from client: %s\n", buff);
        close(connfd);
    }
    close(listenfd);
    return 0;
}
//int main(){
//    server1();
//}