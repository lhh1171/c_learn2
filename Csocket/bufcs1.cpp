
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
int client3(){
    int   connfd, n;
    char  recvline[4096], sendline[4096];
    struct sockaddr_in  servaddr;

    if( (connfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
        return 0;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    if( inet_pton(AF_INET,"127.0.0.1", &servaddr.sin_addr) <= 0){
        printf("inet_pton error for 127.0.0.1\n");
        return 0;
    }

    if(connect(connfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
        return 0;
    }

    ssize_t writeLen;
    char sendMsg[246988] = {0};
    int count = 0;
    while (1){
        count++;
        if (count == 5) {
            return 0;
        }
        writeLen = write(connfd, sendMsg, sizeof(sendMsg));
        if (writeLen < 0) {
            printf("write failed\n");
            close(connfd);
            return 0;
        }
        else{
            printf("write sucess, writelen:%d\n",writeLen);
        }
    }
    close(connfd);
    return 0;
}
int server3(){
    int    listenfd, acceptfd;
    struct sockaddr_in     servaddr;
    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        return -1;
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);
    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        return -1;
    }
    if( listen(listenfd, 10) == -1){
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        return -1;
    }
    printf("======waiting for client's request======\n");
    if( (acceptfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
        printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
    }else{
        printf("accept succ\n");
        int rcvbuf_len;
        socklen_t len = sizeof(rcvbuf_len);
        if( getsockopt( acceptfd, SOL_SOCKET, SO_RCVBUF, (void *)&rcvbuf_len, &len ) < 0 ){
            perror("getsockopt: " );
        }
        printf("the recv buf len: %d\n" , rcvbuf_len );
    }
    char recvMsg[246988]={0};
    ssize_t totalLen = 0;
    while (1) {
        sleep(1);
        ssize_t readLen = read(acceptfd, recvMsg, sizeof(recvMsg));
        printf("readLen:% ld\n",readLen);
        if (readLen < 0) {
            perror("read: ");
            return -1;
        }
        else if (readLen == 0) {
            printf("read finish: len = % ld\n",totalLen);
            close(acceptfd);
            return 0;
        }
        else{
            totalLen += readLen;
        }
    }
    close(acceptfd);
    return 0;
}
int bufcs1(){
    client3();
    server3();
    return 0;
}
