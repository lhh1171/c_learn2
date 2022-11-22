#include <fcntl.h>
#include <poll.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <zconf.h>

//从网卡接收数据直接通过buf给disk
int splice1() {
    int fd, client_fd, server_fd, retin;
    int yes = 1;
    struct sockaddr_in addr_in = {0};
    fd = socket(AF_INET, SOCK_STREAM, 0);
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(1234);
    addr_in.sin_addr.s_addr = inet_addr("192.168.56.1");
    retin = bind(fd, (struct sockaddr *) (&addr_in), sizeof(struct sockaddr));
    retin = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    //new socket
    retin = listen(fd, 5);
    socklen_t len = sizeof(addr_in);
    client_fd = accept(fd, (struct sockaddr *) (&addr_in), &len);
    //接收客户端，连接服务端。
    struct sockaddr_in addr = {0}, addr2 = {0};
    struct in_addr x;
    inet_aton("192.168.56.113", &x);
    addr.sin_family = AF_INET;
    addr.sin_addr = x;
    addr.sin_port = htons(12345);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    retin = connect(server_fd, (struct sockaddr *) &addr, sizeof(addr));

    //pdf是server端的一个管道
    //pdfs是客户端
    //将客户端数据转发到服务端
    struct pollfd pfds[2];
    int pfd[2] = {-1};
    pfds[0].fd = client_fd;
    pfds[0].events = POLLIN | POLLOUT;
    pfds[1].fd = server_fd;
    pfds[1].events = POLLIN | POLLOUT;
    //声明一个管道
    int ret = -1;
    ret = pipe(pfd);
    while (1) {
        int efds = -1;
        if ((efds = poll(pfds, 2, -1)) < 0) {
            return -1;
        }
        //两次splice，第一次sock_client->pipe，第二次pipe->sock_server
        if (pfds[0].revents & POLLIN) {
//            SPLICE_F_MOVE：按整页内存移动数据，存在bug，自内核2.6.21后，实际上没有效果。
//            SPLICE_F_NONBLOCK：非阻塞splice操作，实际会受文件描述符本身阻塞状态影响。
//            SPLICE_F_MORE：提示内核：后续splice将调用更多数据。
//            SPLICE_F_GIFT：对splice没有效果。
            //把客户端数据拷贝给server端的一个管道
            //按照页拷贝给pfd管道,pdf[1]进
            int rncount = splice(pfds[0].fd, NULL, pfd[1],
                    NULL, 65535, SPLICE_F_MORE);
            /*
             * fdin和fdout必须至少有一个是管道文件描述符。
                返回值：
                返回值>0：表示移动的字节数。
                返回0：表示没有数据可以移动，如果从管道中读，表示管道中没有被写入数据。
                返回-1；表示失败，并设置errno。
                errno值如下：
                EBADF：描述符有错。
                EINVAL：目标文件不支持splice，或者目标文件以追加方式打开，或者两个文件描述符都不是管道描述符。
                ENOMEM：内存不够。
                ESPIPE：某个参数是管道描述符，但其偏移不是NULL。
             */

            //pdf[0]出，拷贝给pfds,最后给客户端
            //把server端的一个管道的数据拷贝给server端的网卡
            int wncount = splice(pfd[0], NULL, pfds[1].fd,
                    NULL, 65535, SPLICE_F_MORE);
        }
    }
}