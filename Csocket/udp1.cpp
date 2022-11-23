
#include<iostream>
#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

using namespace std;

int udpclient1() {
    setvbuf(stdout, NULL, _IONBF, 0);
    fflush(stdout);
    int sock = -1;
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        cout << "sock error" << endl;
        return -1;
    }
    const int opt = -1;
    int nb = 0;
    nb = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *) &opt, sizeof(opt));//设置套接字类型
    if (nb == -1) {
        cout << "set socket error...\n" << endl;
        return -1;
    }
    struct sockaddr_in addrto;
    bzero(&addrto, sizeof(struct sockaddr_in));
    addrto.sin_family = AF_INET;
    addrto.sin_addr.s_addr = htonl(INADDR_BROADCAST);//套接字地址为广播地址
    addrto.sin_port = htons(6000);//套接字广播端口号为6000
    int nlen = sizeof(addrto);
    while (1) {
        sleep(1);
        char msg[] = {"the message broadcast"};
        int ret = sendto(sock, msg, strlen(msg), 0, (sockaddr *) &addrto, nlen);//向广播地址发布消息
        if (ret < 0) {
            cout << "send error...\n" << endl;
            return -1;
        }
        else {
            printf("ok\n");
        }
    }
    return 0;
}

int udpserver1() {
    setvbuf(stdout, NULL, _IONBF, 0);
    fflush(stdout);
    struct sockaddr_in addrto;
    bzero(&addrto, sizeof(struct sockaddr_in));
    addrto.sin_family = AF_INET;
    addrto.sin_addr.s_addr = htonl(INADDR_ANY);
    addrto.sin_port = htons(6000);
    socklen_t len = sizeof(addrto);
    int sock = -1;
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        cout << "socket error..." << endl;
        return -1;
    }
    const int opt = -1;
    int nb = 0;
    nb = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *) &opt, sizeof(opt));
    if (nb == -1) {
        cout << "set socket errror..." << endl;
        return -1;
    }
    if (bind(sock, (struct sockaddr *) &(addrto), len) == -1) {
        cout << "bind error..." << endl;
        return -1;
    }
    char msg[100] = {0};
    while (1) {
        int ret = recvfrom(sock, msg, 100, 0, (struct sockaddr *) &addrto, &len);
        if (ret <= 0) {
            cout << "read error..." << endl;
        }
        else {
            printf("%s\t", msg);
        }
        sleep(1);
    }
    return 0;
}
int udp1(){
    udpserver1();
    udpclient1();
    return 0;
}