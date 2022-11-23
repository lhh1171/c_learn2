
#include<iostream>
#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define MCAST_PORT 8888
#define MCAST_ADDR "224.0.0.88"  // 多播地址
#define MCAST_DATA "BROADCAST TEST DATA"  // 多播内容
#define MCAST_INTERVAL 5  //多播时间间隔
#define BUFF_SIZE 256   //接收缓冲区大小
using namespace std;

int udpclient2() {
    int sock;
    struct sockaddr_in mcast_addr;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        cout << "socket error" << endl;
        return -1;
    }
    memset(&mcast_addr, 0, sizeof(mcast_addr));
    mcast_addr.sin_family = AF_INET;
    mcast_addr.sin_addr.s_addr = inet_addr(MCAST_ADDR);
    mcast_addr.sin_port = htons(MCAST_PORT);
    while (1) {
        //向局部多播地址发送多播内容
        int n = sendto(sock, MCAST_DATA, sizeof(MCAST_DATA), 0, (struct sockaddr *) &mcast_addr, sizeof(mcast_addr));
        if (n < 0) {
            cout << "send error" << endl;
            return -2;
        }
        else {
            cout << "send message is going ...." << endl;
        }
        sleep(MCAST_INTERVAL);

    }
    return 0;
}

int udpserver2() {
    int sock;
    struct sockaddr_in local_addr;
    int err = -1;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        cout << "sock error" << endl;
        return -1;
    }
    /*初始化地址*/
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(MCAST_PORT);
    /*绑定socket*/
    err = bind(sock, (struct sockaddr *) &local_addr, sizeof(local_addr));
    if (err < 0) {
        cout << "bind error" << endl;
        return -2;
    }
    /*设置回环许可*/
    int loop = 1;
    err = setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop));
    if (err < 0) {
        cout << "set sock error" << endl;
        return -3;
    }
    struct ip_mreq mreq;
    /*加入多播组*/
    mreq.imr_multiaddr.s_addr = inet_addr(MCAST_ADDR);//多播地址
    mreq.imr_interface.s_addr = htonl(INADDR_ANY); //网络接口为默认
    /*将本机加入多播组*/
    err = setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
    if (err < 0) {
        cout << "set sock error" << endl;
        return -4;
    }
    int times = 0;
    socklen_t addr_len = 0;
    char buff[BUFF_SIZE];
    int n = 0;
    /*循环接受多播组的消息，5次后退出*/
    for (times = 0;; times++) {
        addr_len = sizeof(local_addr);
        memset(buff, 0, BUFF_SIZE);
        n = recvfrom(sock, buff, BUFF_SIZE, 0, (struct sockaddr *) &local_addr, &addr_len);
        if (n == -1) {
            cout << "recv error" << endl;
            return -5;
        }
        /*打印信息*/
        printf("RECV %dst message from server : %s\n", times, buff);
        sleep(MCAST_INTERVAL);
    }
    /*退出多播组*/
    err = setsockopt(sock, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));
    close(sock);
    return 0;
}
int udp2(){
    udpserver2();
    udpclient2();
    return 0;
}