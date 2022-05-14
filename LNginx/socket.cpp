#include <sys/socket.h>
#include <cstdio>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>
#include <exception>
#include <iostream>
#define PORT 6666   //端口号
#define SIZE 128 //定义的数组大小
#define MCAST_PORT 8888
#define MCAST_ADDR "224.0.0.88"  // 多播地址
#define BUFF_SIZE 256   //接收缓冲区大小

using namespace std;
int udpclient2(char* buf) {
    int sock;
    struct sockaddr_in mcast_addr{};
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("socket error" );
        return -1;
    }
    memset(&mcast_addr, 0, sizeof(mcast_addr));
    mcast_addr.sin_family = AF_INET;
    mcast_addr.sin_addr.s_addr = inet_addr(MCAST_ADDR);
    mcast_addr.sin_port = htons(MCAST_PORT);
    //向局部多播地址发送多播内容
    int n = sendto(sock, buf, sizeof(buf), 0, (struct sockaddr *) &mcast_addr, sizeof(mcast_addr));
    if (n < 0) {
        printf("socket error" );
        return -2;
    }
    close(sock);
    return 0;
}

int udpserver2() {
    int sock;
    struct sockaddr_in local_addr{};
    int err = -1;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("socket error" );
        return -1;
    }
    /*初始化地址*/
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(MCAST_PORT);
    /*绑定socket*/
    err = bind(sock, (struct sockaddr *) &local_addr, sizeof(local_addr));
    if (err < 0) {
        printf("socket error" );
        return -2;
    }
    /*设置回环许可*/
    int loop = 1;
    err = setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop));
    if (err < 0) {
        printf("socket error" );
        return -3;
    }
    struct ip_mreq mreq{};
    /*加入多播组*/
    mreq.imr_multiaddr.s_addr = inet_addr(MCAST_ADDR);//多播地址
    mreq.imr_interface.s_addr = htonl(INADDR_ANY); //网络接口为默认
    /*将本机加入多播组*/
    err = setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
    if (err < 0) {
        printf("socket error" );
        return -4;
    }
    int times = 0;
    socklen_t addr_len = 0;
    char buff[BUFF_SIZE];
    int n = 0;
    /*循环接受多播组的消息，5次后退出*/
    for (times = 0;; times++) {
        addr_len = sizeof(local_addr);
        memset(buff, '\0', BUFF_SIZE);
        n = recvfrom(sock, buff, BUFF_SIZE, 0, (struct sockaddr *) &local_addr, &addr_len);
        if (n == -1) {
            printf("socket error" );
            return -5;
        }
        /*打印信息*/
        printf("RECV %dst message from server : %s\n", times, buff);
        if(strncmp(buff, "END", 3) == 0)     //当输入END时客户端退出
        {
            break;
        }
    }
    /*退出多播组*/
    err = setsockopt(sock, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));
    close(sock);
    return 0;
}
int Creat_socket()    //创建套接字和初始化以及监听函数
{
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);   //创建一个负责监听的套接字
    if(listen_socket == -1)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_in addr{};
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;  /* Internet地址族 */
    addr.sin_port = htons(PORT);  /* 端口号 */
    addr.sin_addr.s_addr = htonl(INADDR_ANY);   /* IP地址 */

    int ret = bind(listen_socket, (struct sockaddr *)&addr, sizeof(addr));  //连接
    if(ret == -1)
    {
        perror("bind");
        return -1;
    }
    //监听
    ret = listen(listen_socket, 5);
    if(ret == -1)
    {
        perror("listen");
        return -1;
    }
    return listen_socket;
}

//信息处理函数,功能是将客户端传过来的小写字母转化为大写字母
void handler_client(int listen_socket)
{
    char buf[SIZE];
    struct sockaddr_in cli_addr{};
    int addr_len = sizeof(cli_addr);
    int client_socket;
    //创建一个和客户端交流的套接字
    client_socket = accept(listen_socket, (struct sockaddr *)&cli_addr, reinterpret_cast<socklen_t *>(&addr_len));
    char* ip=inet_ntoa(cli_addr.sin_addr);
    printf("成功接收到一个客户端：%s\n",ip);
    while(true)
    {
        int ret = read(client_socket, buf, SIZE-1);
        if(ret == -1)
        {
            perror("read");
            break;
        }
        if(ret == 0)
        {
            break;
        }
        printf("%s\n",buf);
        printf("udp send to .....................\n");
        udpclient2(buf);
        if(strncmp(buf, "END", 3) == 0)     //当输入END时客户端退出
        {
            break;
        }
        memset(buf,'\0',SIZE);
        //断开连接
    }
    close(client_socket);
}
void tcp_server(){
    int listen_socket = Creat_socket();
    handler_client(listen_socket);
    close(listen_socket);
}

int main(){
    try {
        thread t(tcp_server);
        t.detach();
    } catch (const exception& e) {
        cerr << "EXCEPTION: " << e.what() << endl;
    }
    try {
        thread t(udpserver2);
        t.detach();
    } catch (const exception& e) {
        cerr << "EXCEPTION: " << e.what() << endl;
    }
    cin.get();
    return 0;
}