//
// Created by lqc on 2022/5/8.
//
//
// Created by andilyliao on 16-12-6.
//
#include<cstdio>
#include<cstring>
#include<cerrno>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAXLINE 4096

//返回本地主机名
void checkHostName(int hostname) {
    if (hostname == -1) {
        perror("gethostname");
        _exit(1);
    }
}

//返回主机对应的信息到主机名
void checkHostEntry(struct hostent *hostentry) {
    if (hostentry == NULL) {
        perror("gethostbyname");
        _exit(1);
    }
}

//将Ipv4地址格式转化为点分十进制
void checkIPbuffer(char *IPbuffer) {
    if (NULL == IPbuffer) {
        perror("inet_ntoa");
        _exit(1);
    }
}


int server1() {
    int listenfd, connfd;
    struct sockaddr_in servaddr{};
    char buff[4096];
    int n;
    char *IPbuffer;
    int hostname;
    struct hostent *host_entry;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        return 0;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//将主机的无符号长整形数转换成网络字节顺序。
    servaddr.sin_port = htons(6666);//将一个无符号短整型数值转换为网络字节序，即大端模式(big-endian)　

    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
        return 0;
    }

    if (listen(listenfd, 10) == -1) {
        //第二个参数就是那个backlog
        printf("listen socket error: %s(errno: %d)\n", strerror(errno), errno);
        return 0;
    }



        if ((connfd = accept(listenfd, (struct sockaddr *) NULL, NULL)) == -1) {
            printf("accept socket error: %s(errno: %d)", strerror(errno), errno);
//            continue;
        }

        printf("======waiting for client's request======\n");
        n = recv(connfd, buff, MAXLINE, 0);
        //接收主机名
        hostname = gethostname(buff, sizeof(buff));
        checkHostName(hostname);

        //接收主机信息
        host_entry = gethostbyname(buff);
        checkHostEntry(host_entry);

        //转换网络地址
        IPbuffer = inet_ntoa(*((struct in_addr *) host_entry->h_addr_list[0]));
        printf("Hostname: %s\n", buff);
        printf("Host IP: %s\n", IPbuffer);
        buff[n] = '\0';
        printf("recv msg from client: %s\n", buff);
        close(connfd);

    close(listenfd);
    return 0;
}

int main() {
    server1();
    return 0;
}