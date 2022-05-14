//
//
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <cstdio>
//#include <unistd.h>
//#include <arpa/inet.h>
//#include <cstring>
//#include <string>
//
//
//#define PORT 8888   //端口号
//#define SIZE 1024   //定义的数组大小
//
//using namespace std;
//int Creat_socket()    //创建套接字和初始化以及监听函数
//{
//    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);   //创建一个负责监听的套接字
//    if(listen_socket == -1)
//    {
//        perror("socket");
//        return -1;
//    }
//    struct sockaddr_in addr;
//    memset(&addr, 0, sizeof(addr));
//
//    addr.sin_family = AF_INET;  /* Internet地址族 */
//    addr.sin_port = htons(PORT);  /* 端口号 */
//    addr.sin_addr.s_addr = htonl(INADDR_ANY);   /* IP地址 */
//
//    int ret = bind(listen_socket, (struct sockaddr *)&addr, sizeof(addr));  //连接
//    if(ret == -1)
//    {
//        perror("bind");
//        return -1;
//    }
//
//    ret = listen(listen_socket, 5);        //监听
//    if(ret == -1)
//    {
//        perror("listen");
//        return -1;
//    }
//    return listen_socket;
//}
//
//int wait_client(int listen_socket)
//{
//    struct sockaddr_in cliaddr{};
//    int addrlen = sizeof(cliaddr);
//    printf("等待客户端连接。。。。\n");
//    int client_socket = accept(listen_socket, (struct sockaddr *)&cliaddr, reinterpret_cast<socklen_t *>(&addrlen));   //创建一个和客户端交流的套接字
//    if(client_socket == -1)
//    {
//        perror("accept");
//        return -1;
//    }
//    char* ip=inet_ntoa(cliaddr.sin_addr);
////    int port=cliaddr.sin_port;
//    //把他放在map里
//    printf("成功接收到一个客户端：%s\n",ip);
//
//    return client_socket;
//}
//string choose_IP_PORT(int strategy){
//
//}
//string getIP(string IP_PORT){
//
//}
//int getPort(string IP_PORT){
//
//};
//void handler_client(int client_socket)   //信息处理函数,功能是将客户端传过来的小写字母转化为大写字母
//{
//    string IP_PORT;
//    char buf[SIZE];
//    int   sock_fd;
//    struct sockaddr_in  servaddr{};
//    while(true)
//    {
//        memset(buf,'\0',SIZE);
//        int ret = read(client_socket, buf, SIZE-1);
//        if(ret == -1)
//        {
//            perror("read");
//            break;
//        }
//        if(ret == 0)
//        {
//            break;
//        }
////        buf[ret] = '\0';
////        int i;
////        for(i = 0; i < ret; i++)
////        {
////            buf[i] = buf[i] + 'A' - 'a';
////        }
////        printf("%s\n", buf);
////        string s="ok\r\n";
//        if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
//            printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
//            return;
//        }
//        //根据策略(0,1,2)读hashMap选择IpPort
//        IP_PORT=choose_IP_PORT(0);
//        // 转发
//        memset(&servaddr, 0, sizeof(servaddr));
//        servaddr.sin_family = AF_INET;
//        servaddr.sin_port = htons(getPort(IP_PORT));
//        if(inet_pton(AF_INET, getIP(IP_PORT).c_str(), &servaddr.sin_addr) <= 0){
//            printf("inet_pton error for 127.0.0.1");
//            return;
//        }
//        if( connect(sock_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
//            printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
//            return;
//        }
//        if(send(sock_fd, buf, ret, 0) < 0){
//            printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
//            return;
//        }
//        //更改hashMap
//        close(sock_fd);
////        write(client_socket,buf,ret);
////        if (strcmp(buf,"end\r\n") == 0){
////            break;
////        }
////        if(strncmp(buf, "end", 3) == 0)
////        {
////            break;
////        }
//    }
//    close(client_socket);
//}
//int main(){
//    Creat_socket();
//}