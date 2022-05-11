#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <iostream>

using namespace std;
void
handle_packets(u_char *user, const struct pcap_pkthdr *h, const u_char *packet)
{
    printf("capture a packet.\n");
//    for (int i = 0; i <100; ++i) {
//        printf("%x\n",packet[i]);
//    }
    for (int i = 0; i < 20; ++i) {
        printf("%x\n",packet[i]);
    }
}

int
main(int argc, char **argv)
{
    char errbuff[PCAP_ERRBUF_SIZE];
//    char *dev;

//    if ((dev = pcap_lookupdev(errbuff)) == NULL)
//    {
//        fprintf(stderr, "Failed to find active network interface!");
//        exit(EXIT_FAILURE);
//    }

    pcap_t *p;

    if ((p = pcap_open_live("usb0", 1518, 1, 1000, errbuff)) ==NULL)
    {
        fprintf(stderr, "Failed to open the interface: enp3s0!");
        exit(EXIT_FAILURE);
    }

    struct bpf_program bfp;
    char fp[]="ip";

    if (pcap_compile(p, &bfp, fp, 0, PCAP_NETMASK_UNKNOWN) != 0)
    {
        fprintf(stderr, "Failed to compile the bpf expression: %s!", pcap_geterr(p));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(p, &bfp) != 0)
    {
        fprintf(stderr, "Failed to set the bpf expression: %s!", pcap_geterr(p));
        exit(EXIT_FAILURE);
    }

    pcap_loop(p, 2, handle_packets, nullptr);
    pcap_close(p);
    return 0;
}