//
// Created by andilyliao on 16-12-6.
//

#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAXSIZE     1024
#define IPADDRESS   "127.0.0.1"
#define SERV_PORT   6666
#define FDSIZE        1024
#define EPOLLEVENTS 20
#define LISTENQ     5
void add_event(int epollfd,int fd,int state);
void delete_event(int epollfd,int fd,int state);
void modify_event(int epollfd,int fd,int state);



void handle_connection(int sockfd);
void handle_events(int epollfd,struct epoll_event *events,int num,int sockfd,char *buf);
void do_read(int epollfd,int fd,int sockfd,char *buf);
void do_write(int epollfd,int fd,int sockfd,char *buf);



int count=0;
int clientepoll1(){
    int                 sockfd;
    struct sockaddr_in  servaddr;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET,IPADDRESS,&servaddr.sin_addr);
    connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    /*处理连接*/
    handle_connection(sockfd);
    close(sockfd);
    return 0;
}

void handle_connection(int sockfd){
    int epollfd;
    struct epoll_event events[EPOLLEVENTS];
    char buf[MAXSIZE];
    int ret;
    epollfd = epoll_create(FDSIZE);
    add_event(epollfd,STDIN_FILENO,EPOLLIN);
    while (1 ) {
        ret = epoll_wait(epollfd,events,EPOLLEVENTS,-1);
        handle_events(epollfd,events,ret,sockfd,buf);
    }
    close(epollfd);
}

void handle_events(int epollfd,struct epoll_event *events,int num,int sockfd,char *buf){
    int fd;
    int i;
    for (i = 0;i < num;i++){
        fd = events[i].data.fd;
        if (events[i].events & EPOLLIN)
            do_read(epollfd,fd,sockfd,buf);
        else if (events[i].events & EPOLLOUT)
            do_write(epollfd,fd,sockfd,buf);
    }
}

void do_read(int epollfd,int fd,int sockfd,char *buf){
    int nread;
    nread = read(fd,buf,MAXSIZE);
    if (nread == -1){
        perror("read error:");
        close(fd);
    }
    else if (nread == 0){
        fprintf(stderr,"server close.\n");
        close(fd);
    }
    else{
        if (fd == STDIN_FILENO)
            add_event(epollfd,sockfd,EPOLLOUT);
        else{
            delete_event(epollfd,sockfd,EPOLLIN);
            add_event(epollfd,STDOUT_FILENO,EPOLLOUT);
        }
    }
}

void do_write(int epollfd,int fd,int sockfd,char *buf){
    int nwrite;
    char temp[100];
    buf[strlen(buf)-1]='\0';
    snprintf(temp,sizeof(temp),"%s_%02d\n",buf,count++);
    nwrite = write(fd,temp,strlen(temp));
    if (nwrite == -1){
        perror("write error:");
        close(fd);
    }
    else{
        if (fd == STDOUT_FILENO)
            delete_event(epollfd,fd,EPOLLOUT);
        else
            modify_event(epollfd,fd,EPOLLIN);
    }
    memset(buf,0,MAXSIZE);
}


//=============================================================================================
/*函数声明*/
/*创建套接字并进行绑定*/
int socket_bind(const char* ip,int port);
/*IO多路复用epoll*/
void do_epoll(int listenfd);
/*事件处理函数*/
void handle_eventsserver(int epollfd,struct epoll_event *events,int num,int listenfd,char *buf);
/*处理接收到的连接*/
void handle_accpet(int epollfd,int listenfd);
/*读处理*/
void do_readserver(int epollfd,int fd,char *buf);
/*写处理*/
void do_writeserver(int epollfd,int fd,char *buf);

int serverepoll1(){
    int  listenfd;
    listenfd = socket_bind(IPADDRESS,SERV_PORT);
    listen(listenfd,LISTENQ);
    do_epoll(listenfd);
    return 0;
}

int socket_bind(const char* ip,int port){
    int  listenfd;
    struct sockaddr_in servaddr;
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    if (listenfd == -1){
        perror("socket error:");
        exit(1);
    }
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&servaddr.sin_addr);
    servaddr.sin_port = htons(port);
    if (bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) == -1){
        perror("bind error: ");
        exit(1);
    }
    return listenfd;
}

void do_epoll(int listenfd){
    int epollfd;
    struct epoll_event events[EPOLLEVENTS];
    int ret;
    char buf[MAXSIZE];
    memset(buf,0,MAXSIZE);
    /*创建一个描述符*/
    epollfd = epoll_create(FDSIZE);
    /*添加监听描述符事件*/
    add_event(epollfd,listenfd,EPOLLIN);
    while(1){
        /*获取已经准备好的描述符事件*/
        ret = epoll_wait(epollfd,events,EPOLLEVENTS,-1);
        handle_eventsserver(epollfd,events,ret,listenfd,buf);//重点注意这个ret，它返回的是已经有事儿的fd的个数
                                                            //这样一会儿轮循的就不是所有的fd了
    }
    close(epollfd);
}

void handle_eventsserver(int epollfd,struct epoll_event *events,int num,int listenfd,char *buf){
    int i;
    int fd;
    /*进行选好遍历*/
    for (i = 0;i < num;i++){
        fd = events[i].data.fd;
        /*根据描述符的类型和事件类型进行处理*/
        if ((fd == listenfd) &&(events[i].events & EPOLLIN))
            handle_accpet(epollfd,listenfd);
        else if (events[i].events & EPOLLIN)
            do_readserver(epollfd,fd,buf);
        else if (events[i].events & EPOLLOUT)
            do_writeserver(epollfd,fd,buf);
    }
}

void handle_accpet(int epollfd,int listenfd){
    int clifd;
    struct sockaddr_in cliaddr;
    socklen_t  cliaddrlen;
    clifd = accept(listenfd,(struct sockaddr*)&cliaddr,&cliaddrlen);
    if (clifd == -1)
        perror("accpet error:");
    else{
        printf("accept a new client: %s:%d\n",inet_ntoa(cliaddr.sin_addr),cliaddr.sin_port);
        /*添加一个客户描述符和事件*/
        add_event(epollfd,clifd,EPOLLIN);
    }
}

void do_readserver(int epollfd,int fd,char *buf){
    int nread;
    nread = read(fd,buf,MAXSIZE);
    if (nread == -1){
        perror("read error:");
        close(fd);
        delete_event(epollfd,fd,EPOLLIN);
    }
    else if (nread == 0){
        fprintf(stderr,"client close.\n");
        close(fd);
        delete_event(epollfd,fd,EPOLLIN);
    }
    else{
        printf("read message is : %s",buf);
        /*修改描述符对应的事件，由读改为写*/
        modify_event(epollfd,fd,EPOLLOUT);
    }
}

void do_writeserver(int epollfd,int fd,char *buf){
    int nwrite;
    nwrite = write(fd,buf,strlen(buf));
    if (nwrite == -1){
        perror("write error:");
        close(fd);
        delete_event(epollfd,fd,EPOLLOUT);
    }
    else
        modify_event(epollfd,fd,EPOLLIN);
    memset(buf,0,MAXSIZE);
}
//====================================================================================

void add_event(int epollfd,int fd,int state){
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&ev);
}

void delete_event(int epollfd,int fd,int state){
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,&ev);
}

void modify_event(int epollfd,int fd,int state){
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&ev);
}

int epoll1(){
    clientepoll1();
//    serverepoll1();
    return 0;
}

