
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#define DEFAULT_PORT 6666
#pragma pack(1)
struct Header {
    int num ;//包id
    int index ;//学生编号
};
struct PkgContent {
    char sex ;//性别
    int score ;//分数
    char address [100];//地址
    int age;
};
struct Pkg {
    Header head;
    PkgContent content ;
};

int MySend( int iSock, char * pchBuf, size_t tLen){
    int iThisSend;
    unsigned int iSended=0;
    if(tLen == 0)
        return 0;
    while(iSended<tLen){
        do{
            iThisSend = send(iSock, pchBuf, tLen-iSended, 0);
        } while((iThisSend<0) && (errno==EINTR));
        if(iThisSend < 0){
            return(iSended);
        }
        iSended += iThisSend;
        pchBuf += iThisSend;
    }
    return(tLen);
}


int client5(){
    int connfd = 0;
    int cLen = 0;
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(DEFAULT_PORT);
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    connfd = socket(AF_INET, SOCK_STREAM, 0);
    if(connfd < 0){
        printf("socket() failure!\n" );
        return -1;
    }
    if(connect(connfd, (struct sockaddr*)&client, sizeof(client)) < 0){
        printf("connect() failure!\n" );
        return -1;
    }
    Pkg mypkg;
    mypkg.head.num=1;
    mypkg.head.index=10001;
    mypkg.content.sex='m';
    mypkg.content.score=90;
    char * temp="guangzhou and shanghai";
    strncpy(mypkg.content.address,temp,sizeof(mypkg.content.address));
    mypkg.content.age=18;
    ssize_t writeLen;
    int tLen=sizeof(mypkg);
    printf("tLen:%d\n" ,tLen);
    int iLen=0;
    char * pBuff= new char [1000];
    *(int*)(pBuff+iLen)= htonl(tLen);
    iLen+=sizeof( int);
    *(int*)(pBuff+iLen)= htonl(mypkg.head.num);
    iLen+=sizeof( int);
    *(int*)(pBuff+iLen)= htonl(mypkg.head.index);
    iLen+=sizeof( int);
    memcpy(pBuff+iLen,&mypkg.content.sex,sizeof( char));
    iLen+=sizeof( char);
    *(int*)(pBuff+iLen)= htonl(mypkg.content.score);
    iLen+=sizeof( int);
    memcpy(pBuff+iLen,mypkg.content.address,sizeof(mypkg.content.address));
    iLen+=(sizeof(mypkg.content.address));
    *(int*)(pBuff+iLen)= htonl(mypkg.content.age);
    iLen+=sizeof( int);
    writeLen= MySend(connfd, pBuff, iLen);
    if (writeLen < 0) {
        printf("write failed\n" );
        close(connfd);
        return 0;
    }
    else{
        printf("write sucess, writelen :%d, iLen:%d, pBuff: %s\n",writeLen,iLen,pBuff);
    }
    close(connfd);
    return 0;
}
//=============================================================================================
int MyRecv( int iSock, char * pchBuf, size_t tCount){
    size_t tBytesRead=0;
    int iThisRead;
    while(tBytesRead < tCount){
        do{
            iThisRead = read(iSock, pchBuf, tCount-tBytesRead);
        } while((iThisRead<0) && (errno==EINTR));
        if(iThisRead < 0){
            return(iThisRead);
        }
        else if (iThisRead == 0)
            return(tBytesRead);
        tBytesRead += iThisRead;
        pchBuf += iThisRead;
    }
}
int server5(){
    int sockfd,acceptfd; /* 监听socket: sock_fd,数据传输socket: acceptfd */
    struct sockaddr_in my_addr; /* 本机地址信息 */
    struct sockaddr_in their_addr; /* 客户地址信息 */
    unsigned int sin_size, myport=6666, lisnum=10;
    if ((sockfd = socket(AF_INET , SOCK_STREAM, 0)) == -1) {
        perror("socket" );
        return -1;
    }
    printf("socket ok \n");
    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(DEFAULT_PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), 0);
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr )) == -1) {
        perror("bind" );
        return -2;
    }
    printf("bind ok \n");
    if (listen(sockfd, lisnum) == -1) {
        perror("listen" );
        return -3;
    }
    printf("listen ok \n");
    char recvMsg[1000];
    sin_size = sizeof(my_addr);
    acceptfd = accept(sockfd,(struct sockaddr *)&my_addr,&sin_size);
    if (acceptfd < 0) {
        close(sockfd);
        printf("accept failed\n" );
        return -4;
    }
    ssize_t readLen = MyRecv(acceptfd, recvMsg, sizeof(int));
    if (readLen < 0) {
        printf("read failed\n" );
        return -1;
    }
    int len=(int)ntohl(*(int*)recvMsg);
    printf("len:%d\n",len);
    readLen = MyRecv(acceptfd, recvMsg, len);
    if (readLen < 0) {
        printf("read failed\n" );
        return -1;
    }
    char * pBuff=recvMsg;
    Pkg RecvPkg;
    int iLen=0;
    memcpy(&RecvPkg.head.num , pBuff + iLen, sizeof( int));
    iLen += sizeof(int);
    RecvPkg. head. num = ntohl(RecvPkg.head.num);
    printf("RecvPkg.head.num:%d\n" ,RecvPkg.head.num);
    memcpy(&RecvPkg.head.index , pBuff + iLen, sizeof( int));
    iLen += sizeof(int);
    RecvPkg. head. index = ntohl(RecvPkg.head.index);
    printf("RecvPkg.head.index:%d\n" ,RecvPkg.head.index);
    memcpy(&RecvPkg.content.sex , pBuff + iLen, sizeof( char));
    iLen += sizeof(char);
    printf("RecvPkg.content.sex:%c\n" ,RecvPkg.content.sex);
    memcpy(&RecvPkg.content.score , pBuff + iLen, sizeof( int));
    iLen += sizeof(int);
    RecvPkg. content.score = ntohl(RecvPkg. content.score );
    printf("RecvPkg.content.score:%d\n" ,RecvPkg.content.score);
    memcpy(&RecvPkg.content.address, pBuff + iLen, sizeof(RecvPkg.content.address ));
    iLen += sizeof(RecvPkg.content.address);
    printf("RecvPkg.content.address:%s\n" ,RecvPkg.content.address);
    memcpy(&RecvPkg.content.age , pBuff + iLen, sizeof( int));
    iLen += sizeof(int);
    RecvPkg.content.age = ntohl(RecvPkg.content.age );
    printf("RecvPkg.content.age:%d\n" ,RecvPkg.content.age);
    close(acceptfd);
    return 0;
}
int structcs1(){
    client5();
    server5();
    return 0;
}