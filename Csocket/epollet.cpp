#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <assert.h>

#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 10
#define PORT 9999
int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

void addfd(int epollfd, int fd, bool enable_et)
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    if(enable_et){
        event.events |= EPOLLET;
    }
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblocking(fd);
}

void et(epoll_event* events, int number, int epollfd, int listenfd)
{
    char buf[BUFFER_SIZE];
    for(int i = 0; i < number; i++){
        int sockfd = events[i].data.fd;
        if(sockfd == listenfd){//新连接
            struct sockaddr_in client_address;
            socklen_t client_addrlen = sizeof(client_address);
            int connfd = accept(listenfd, (struct sockaddr*) &client_address, &client_addrlen);
            addfd(epollfd, connfd, true);
        }
        else if(events[i].events & EPOLLIN){//读数据
            printf("event trigger once\n");
            while(1){
                memset(buf, '\0', sizeof(buf));
                int ret = recv(sockfd, buf, BUFFER_SIZE - 1, 0);
                if(ret < 0){//下次再读
                    if(errno == EAGAIN || errno == EWOULDBLOCK){
                        printf("read later\n");
                        break;
                    }
                }
                else if(ret == 0){
                    close(sockfd);
                    break;
                }
                else{
                    printf("get %d bytes of content: %s\n", ret, buf);
                }
            }
        }
        else{
            printf("some thing else happened");
        }
    }
}

int epollet1() {

    int ret = 0;
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

    ret = bind(listenfd, (struct sockaddr *) &address, sizeof(address));

    ret = listen(listenfd, 5);

    epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(5);

    addfd(epollfd, listenfd, true);

    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if (nfds < 0) {
            printf("epoll failure!\n");
            break;
        }
        et(events, nfds, epollfd, listenfd);
    }
    close(listenfd);
    return 0;
}