////
//// Created by andilyliao on 2021/1/3.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>           // close()
//#include <string.h>           // strcpy, memset(), and memcpy()
//#include <netdb.h>            // struct addrinfo
//#include <sys/types.h>        // needed for socket(), uint8_t, uint16_t, uint32_t
//#include <sys/socket.h>       // needed for socket()
//#include <netinet/in.h>       // IPPROTO_ICMP, INET_ADDRSTRLEN
//#include <netinet/ip.h>       // struct ip and IP_MAXPACKET (which is 65535)
//#include <netinet/ip_icmp.h>  // struct icmp, ICMP_ECHO
//#include <arpa/inet.h>        // inet_pton() and inet_ntop()
//#include <sys/ioctl.h>        // macro ioctl is defined
//#include <bits/ioctls.h>      // defines values for argument "request" of ioctl.
//#include <net/if.h>           // struct ifreq
//#include <linux/if_ether.h>   // ETH_P_IP = 0x0800, ETH_P_IPV6 = 0x86DD
//#include <linux/if_packet.h>  // struct sockaddr_ll (see man 7 packet)
//#include <net/ethernet.h>
//
//#include <errno.h>            // errno, perror()
//#define ETH_P_DEAN 0x8874 //自定义的以太网协议type
//
//int pfpacket1 ()
//{
//    int i, datalen,frame_length, sd, bytes;
//    char interface[]="usb0";
//    uint8_t data[IP_MAXPACKET];
//    uint8_t src_mac[6];
//    uint8_t dst_mac[6];
//    uint8_t ether_frame[IP_MAXPACKET];
//    struct sockaddr_ll device;
//    struct ifreq ifr;
//
////    // Submit request for a socket descriptor to look up interface.
////    if ((sd = socket (PF_PACKET, SOCK_RAW, htons (ETH_P_ALL))) < 0) {
////        //第一次创建socket是为了获取本地网卡信息
////        perror ("socket() failed to get socket descriptor for using ioctl() ");
////        exit (EXIT_FAILURE);
////    }
////
////    // Use ioctl() to look up interface name and get its MAC address.
////    memset (&ifr, 0, sizeof (ifr));
////    snprintf (ifr.ifr_name, sizeof (ifr.ifr_name), "%s", interface);
////    printf("ifr_name===%s\n",ifr.ifr_name);
////    if (ioctl (sd, SIOCGIFHWADDR, &ifr) < 0) {
////        perror ("ioctl() failed to get source MAC address ");
////        return (EXIT_FAILURE);
////    }
////    close (sd);
//
//    // Copy source MAC address.
//    memcpy (src_mac, ifr.ifr_hwaddr.sa_data, 6);
//
//    // Report source MAC address to stdout.
//    printf ("MAC address for interface %s is ", interface);
//    for (i=0; i<5; i++) {
//        printf ("%02x:", src_mac[i]);
//    }
//    printf ("%02x\n", src_mac[5]);
//
//    // Find interface index from interface name and store index in
//    // struct sockaddr_ll device, which will be used as an argument of sendto().
//    memset (&device, 0, sizeof (device));
//    //if_nametoindex
//    if ((device.sll_ifindex = if_nametoindex (interface)) == 0) {
//        perror ("if_nametoindex() failed to obtain interface index ");
//        exit (EXIT_FAILURE);
//    }
//    printf ("Index for interface %s is %i\n", interface, device.sll_ifindex);
//
//    // Set destination MAC address: you need to fill these out
//    ////设置目的网卡地址
//    //80:fa:5b:97:96:ae
//    //64:79:f0:6d:d3:4b
//    //0a:00:27:00:00:00
//    dst_mac[0] = 0x0a;
//    dst_mac[1] = 0x00;
//    dst_mac[2] = 0x27;
//    dst_mac[3] = 0x00;
//    dst_mac[4] = 0x00;
//    dst_mac[5] = 0x00;
//
//    // Fill out sockaddr_ll.
//    device.sll_family = PF_PACKET;
//    memcpy (device.sll_addr, src_mac, 6);
//    device.sll_halen = htons (6);
//
//    // 发送的data，长度可以任意，但是抓包时看到最小数据长度为46，
//    // 这是以太网协议规定以太网帧数据域部分最小为46字节，不足的自动补零处理
//    datalen = 12;
//    data[0] = 'h';
//    data[1] = 'h';
//    data[2] = 'h';
//    data[3] = 'h';
//    data[4] = 'h';
//    data[5] = 'h';
//    data[6] = 'h';
//    data[7] = 'h';
//    data[8] = 'r';
//    data[9] = 'l';
//    data[10] = 'd';
//    data[11] = '!';
//
//    // Fill out ethernet frame header.
//    frame_length = 6 + 6 + 2   + datalen;
//    // Destination and Source MAC addresses
//    memcpy (ether_frame, dst_mac, 6);
//    memcpy (ether_frame + 6, src_mac, 6);
//
//    ether_frame[12] = 0x08;
//    ether_frame[13] = 0x00;
//
//    // data
//    memcpy (ether_frame + 14 , data, datalen);
//
//    // Submit request for a raw socket descriptor.
//    if ((sd = socket (PF_PACKET, SOCK_RAW, htons (ETH_P_ALL))) < 0) {//创建正真发送的socket
//        perror ("socket() failed ");
//        exit (EXIT_FAILURE);
//    }
////    device.sll_addr=inet_addr("192.168.56.1");
//    // Send ethernet frame to socket.
//    if ((bytes = sendto (sd, ether_frame, frame_length, 0, (struct sockaddr *) &device, sizeof (device))) <= 0) {
//        perror ("sendto() failed");
//        exit (EXIT_FAILURE);
//    }
//    printf ("send num=%d,read num=%d\n",frame_length,bytes);
//    // Close socket descriptor.
//    close (sd);
//    return (EXIT_SUCCESS);
//}
//int main(){
//    pfpacket1();
//}