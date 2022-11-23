
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>
#include<sys/types.h>
#include <zconf.h>

int port=8888;
int udpserver0(){
    int sockfd;
    socklen_t len;
    int z;
    char buf[256];
    struct sockaddr_in adr_inet;
    struct sockaddr_in adr_clnt;
    printf("waiting for client...\n");
    adr_inet.sin_family=AF_INET;
    adr_inet.sin_port=htons(port);
    adr_inet.sin_addr.s_addr=htonl(INADDR_ANY);
    bzero(&(adr_inet.sin_zero),8);
    len=sizeof(adr_clnt);
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd==-1){
        perror("socket error_1");
        exit(1);
    }
    z=bind(sockfd,(struct sockaddr *)&adr_inet,sizeof(adr_inet));
    if(z==-1){
        perror("bind error_1");
        exit(1);
    }
    while(1){
        z=recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&adr_clnt,&len);
        if(z<0){
            perror("recvfrom error_1");
            exit(1);
        }
        buf[z]=0;
        printf("接收：%s",buf);
        if(strncmp(buf,"stop",4)==0){
            printf("结束....\n");
            break;
        }
    }
    close(sockfd);
    exit(0);
}
int udpclient0(){
    int sockfd;
    int i=0;
    int z;
    char buf[80],str1[80];
    struct hostent *host;
    struct sockaddr_in adr_srvr;
    if((host=gethostbyname("127.0.0.1"))==NULL){
        herror("gethostbyname error!");
        exit(1);
    }
    printf("connecting server....\n");
    adr_srvr.sin_family=AF_INET;
    adr_srvr.sin_port=htons(port);
    adr_srvr.sin_addr=*((struct in_addr *)host->h_addr);
    bzero(&(adr_srvr.sin_zero),8);
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd==-1){
        perror("socket error!");
        exit(1);
    }
    printf("send file ...\n");
    for(i=0;i<3;i++){
        fgets(str1,80,stdin);
        printf("%d:%s",i,str1);
        sprintf(buf,"%d:%s",i,str1);
        z=sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&adr_srvr,sizeof(adr_srvr));
        if(z<0){
            perror("recvfrom error");
            exit(1);
        }
    }
    printf("send ....\n");
    sprintf(buf,"stop\n");
    z=sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&adr_srvr,sizeof(adr_srvr));
    if(z<0){
        perror("sendto error");
        exit(1);
    }
    close(sockfd);
    exit(0);
}
int udp0(){
    udpserver0();
//    udpclient0();
    return 0;
}