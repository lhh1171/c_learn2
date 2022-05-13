//
// Created by andilyliao on 17-2-12.
//

#include<iostream>
#include<cstdio>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<cstring>

#define MCAST_PORT 8888
#define MCAST_ADDR "224.0.0.88"  // 多播地址
#define MCAST_DATA "BROADCAST TEST DATA"  // 多播内容
#define MCAST_INTERVAL 3  //多播时间间隔
#define BUFF_SIZE 256   //接收缓冲区大小
using namespace std;

int udpserver2() {
    int fd=socket(AF_INET,SOCK_DGRAM,0);
    if (fd==-1){
        perror("fail to sock");
        exit(1);
    }


    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9999);
    addr.sin_addr.s_addr=inet_addr("192.168.206.88");
    bind(fd,(struct sockaddr *)&addr,sizeof(addr));

    struct sockaddr_in gaddr;
    gaddr.sin_family=AF_INET;
    gaddr.sin_port=htons(8888);
    gaddr.sin_addr.s_addr=inet_addr("224.0.0.88");


    char buf[1024]={};
    struct sockaddr_in caddr;
    int caddrlen=sizeof(caddr);
    while (true){
        if (recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&caddr, (socklen_t *)(&caddrlen))==-1){
            perror("fail to recv");
            exit(1);
        }
        printf("ip:%s , port:%d \n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));
        printf("client : %s\n",buf);
        if (sendto(fd, buf, sizeof(buf), 0, (struct sockaddr *)&gaddr, sizeof(gaddr))==-1){
            perror("fail to send");
            exit(1);
        }
    }
    close(fd);
}
int main(){
    udpserver2();
}
