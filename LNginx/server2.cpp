//#include <sys/types.h>
//#include <sys/socket.h>
//#include <cstdio>
//#include <unistd.h>
//#include <arpa/inet.h>
//#include <cstring>
//#include <string>
//#include <map>
//#include <iostream>
//#include <vector>
//#define PORT 9100   //端口号
//#define SIZE 40960 //定义的数组大小
//
//using namespace std;
//int property_len=0;
//map<int , string> property_map;
//map<string , int> ip_map;
//string client_ip;
//vector<string> split(const string& str, const string& delim) {
//    vector<string> res;
//    if("" == str) return res;
//    //先将要切割的字符串从string类型转换为char*类型
//    char * strs = new char[str.length() + 1] ; //不要忘了
//    strcpy(strs, str.c_str());
//
//    char * d = new char[delim.length() + 1];
//    strcpy(d, delim.c_str());
//
//    char *p = strtok(strs, d);
//    while(p) {
//        string s = p; //分割得到的字符串转换为string类型
//        res.push_back(s); //存入结果数组
//        p = strtok(NULL, d);
//    }
//    return res;
//}
//
//vector<string> splitStr(const string& src, const string& delimiter) {
//    std::vector<string> vetStr;
//
//    // 入参检查
//    // 1.原字符串为空或等于分隔符，返回空 vector
//    if (src == "" || src == delimiter) {
//        return vetStr;
//    }
//    // 2.分隔符为空返回单个元素为原字符串的 vector
//    if (delimiter == "") {
//        vetStr.push_back(src);
//        return vetStr;
//    }
//
//    string::size_type startPos = 0;
//    auto index = src.find(delimiter);
//    while (index != string::npos) {
//        auto str = src.substr(startPos, index - startPos);
//        if (str != "") {
//            vetStr.push_back(str);
//        }
//        startPos = index + delimiter.length();
//        index = src.find(delimiter, startPos);
//    }
//    // 取最后一个子串
//    auto str = src.substr(startPos);
//    if (str != "") {
//        vetStr.push_back(str);
//    }
//
//    return vetStr;
//}
//
//
//int Creat_socket()    //创建套接字和初始化以及监听函数
//{
//    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);   //创建一个负责监听的套接字
//    if(listen_socket == -1)
//    {
//        perror("socket");
//        return -1;
//    }
//    struct sockaddr_in addr{};
//    memset(&addr, 0, sizeof(addr));
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
//    //监听
//    ret = listen(listen_socket, 5);
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
//    struct sockaddr_in cli_addr{};
//    int addr_len = sizeof(cli_addr);
//    printf("等待客户端连接。。。。\n");
//    //创建一个和客户端交流的套接字
//    int client_socket = accept(listen_socket, (struct sockaddr *)&cli_addr, reinterpret_cast<socklen_t *>(&addr_len));
//    if(client_socket == -1)
//    {
//        perror("accept");
//        return -1;
//    }
//    char* ip=inet_ntoa(cli_addr.sin_addr);
//    printf("成功接收到一个客户端：%s\n",ip);
//    //拿到客户端的IP
//    client_ip=ip;
//    return client_socket;
//}
//void init_map(){
//    //读property配置文件
//    property_map.insert(map<int , string>::value_type(0,"127.0.0.1:8080"));
//    property_map.insert(map<int , string>::value_type(1,"127.0.0.1:7777"));
//    property_map.insert(map<int , string>::value_type(2,"127.0.0.1:8888"));
//    property_map.insert(map<int , string>::value_type(3,"127.0.0.1:9999"));
//}
//
//void flushMap(){
//    //将此次的连接记录刷新到Map
//}
//
////三种负载均衡策略
////ip_map(cliIp,server_index)
//string round_robin(){
//    map<string , int>::iterator iter1=ip_map.begin();
//    map<int, string>::iterator iter2=property_map.begin();
//    int ii=-1;
//    string target_ip;
//    //如果该客户端连接过
//    for(;iter1!=ip_map.end();iter1++){
//        if (iter1->first==client_ip){
//            for(;iter2!=property_map.end();iter2++){
//                if (iter2->first==(iter1->second+1)){
//                    cout<<"sec:" <<iter2->first<<endl;
//                    cout<<"targetIp: "<<iter2->second<<endl;
//                    ii=iter2->first;
//                    target_ip = iter2->second;
//                }
//            }
//        }
//    }
//    if (ii==-1){
//        //如果该客户端未连接过
//        iter2=property_map.begin();
//        ip_map.insert(map<string, int>::value_type(client_ip, 0));
//        for (; iter2 != property_map.end(); iter2++) {
//            if (iter2->first == 0) {
//                target_ip = iter2->second;
//            }
//        }
//    } else {
//        ip_map.insert(map<string, int>::value_type(client_ip, ii));
//    }
//    return target_ip;
//}
//string weight(){
//    return "";
//}
//string ip_hash(){
//    return "";
//}
//string choose_i_p(int strategy){
//    string I_P;
//    switch (strategy) {
//        case 0:
//            I_P=round_robin();
//            break;
//        case 1:
//            I_P=weight();
//            break;
//        case 2:
//            I_P=ip_hash();
//            break;
//        default:
//            I_P="0.0.0.0";
//            break;
//    }
//    return I_P;
//}
//string get_ip(const string& IP_PORT){
//    std::vector<string> res = split(IP_PORT, ":");
//    cout<<res[0]<<endl;
//    return res[0];
//}
//string get_port(const string& IP_PORT){
//    std::vector<string> res = split(IP_PORT, ":");
//    cout<<res[1]<<endl;
//    return res[1];
//}
////信息处理函数,功能是将客户端传过来的小写字母转化为大写字母
//void handler_client(int listen_socket)
//{
//    string IP_PORT;
//    char buf[SIZE];
//    int   sock_fd;
//    struct sockaddr_in  server_addr{};
//    struct sockaddr_in cli_addr{};
//    int addr_len = sizeof(cli_addr);
//    while(true)
//    {
//        //创建一个和客户端交流的套接字
//        int client_socket = accept(listen_socket, (struct sockaddr *)&cli_addr, reinterpret_cast<socklen_t *>(&addr_len));
//        char* ip=inet_ntoa(cli_addr.sin_addr);
//        printf("成功接收到一个客户端：%s\n",ip);
//        //拿到客户端的IP
//        client_ip=ip;
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
//        printf("%s\n",buf);
//        //创建一个socket转发
//        if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
//            printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
//            return;
//        }
//        //根据策略(0,1,2)读hashMap选择IpPort
//        IP_PORT=choose_i_p(0);
//        // 转发
//        memset(&server_addr, 0, sizeof(server_addr));
//        server_addr.sin_family = AF_INET;
//        server_addr.sin_port = htons(std::stoi(get_port(IP_PORT)));
//        if(inet_pton(AF_INET, get_ip(IP_PORT).c_str(), &server_addr.sin_addr) <= 0){
//            printf("inet_pton error for 127.0.0.1");
//            return;
//        }
//
//        if(connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
//            printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
//            return;
//        }
//        //write(sock_fd,buf,ret);
//        string aa=buf;
//        string bb="GET / HTTP/1.1\r\n";
//        bb.append("Host: ");
//        bb.append(get_ip(IP_PORT));
//        bb.append(":");
//        bb.append(get_port(IP_PORT));
//        bb.append("\r\nConnection");
//        std::vector<string> res = splitStr(buf, "\r\nConnection");
//        bb.append(res[1]);
//        if(send(sock_fd, bb.c_str(), bb.length(), 0) < 0){
//            printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
//            return;
//        }
//        memset(buf,'\0',SIZE);
////        int len=recv(sock_fd, buf, SIZE,MSG_WAITALL);
//        int len=read(sock_fd, buf, SIZE);
//        write(client_socket, buf, len);
//        printf("--------------------------------------------\n%s\n",buf);
//        //更改hashMap
//        flushMap();
//        //断开连接
//        close(client_socket);
//        close(sock_fd);
//    }
//}
//
//
//int main()
//{
//    init_map();
//    int listen_socket = Creat_socket();
//    handler_client(listen_socket);
//    close(listen_socket);
//    return 0;
//}