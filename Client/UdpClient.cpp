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

int client() {
    int fd=socket(AF_INET,SOCK_DGRAM,0);
    if (fd==-1){
        perror("fail to sock");
        exit(1);
    }
/*设置回环许可*/
    int loop = 1;
    int err = setsockopt(fd, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop));
    if (err < 0) {
        cout << "set sock error" << endl;
        return -3;
    }
    struct ip_mreq mreq;
    mreq.imr_multiaddr.s_addr=inet_addr("224.0.0.88");
    mreq.imr_interface.s_addr=INADDR_ANY;
    int ee=setsockopt(fd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq));
    if(ee<0){
        cout << "set mreq error" << endl;
        return -3;
    }
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9999);
    addr.sin_addr.s_addr=inet_addr("192.168.206.88");

    struct sockaddr_in baddr;
    baddr.sin_family=AF_INET;
    baddr.sin_port=htons(8888);
    baddr.sin_addr.s_addr=inet_addr("224.0.0.88");
    bind(fd,(struct sockaddr *)&baddr,sizeof(baddr));

    char buf[1024]={};
    struct sockaddr_in caddr;
    int caddrlen=sizeof(caddr);
    while (true){
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1]='\0';
        if (sendto(fd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, sizeof(addr))==-1){
            perror("fail to send");
            exit(1);
        }

        if (recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&caddr, (socklen_t *)&caddrlen)==-1){
            perror("fail to recv");
            exit(1);
        }
        printf("ip:%s , port:%d \n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));
        printf("client : %s\n",buf);
    }
    close(fd);
}
int main(){
    client();
}
