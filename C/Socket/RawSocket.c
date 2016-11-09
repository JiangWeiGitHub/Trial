#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <linux/if_ether.h>
#include <linux/in.h>

#define BUFFER_LENGTH 2048

int main(void)
{
    int sock_id, read_counter, protocal_type;        
    char buffer[BUFFER_LENGTH];
    char *eth_head, *ip_head, *tcp_head, *udp_head, *icmp_head, *p;
        
    if((sock_id = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP))) < 0)
    {
        fprintf(stdout, "Create Raw Socket Error!\n");
        fprintf(stdout, "You Have To Use 'root' Privilege!\n");
        exit(0);
    }
        
    while(1) 
    {
        read_counter = recvfrom(sock_id, buffer, BUFFER_LENGTH, 0, NULL, NULL);
        
        /*
        14   6(dest)+6(source)+2(type or length)
        +
        20   ip header 
        +
        8    icmp & tcp or udp header
        = 42
        */

        if(read_counter < 42) 
        {
            fprintf(stdout, "Incomplete Header, Packet Corrupt!\n");
            continue;
        }
                
        eth_head = buffer;
        p = eth_head;
        int n = 0XFF;
        printf("MAC: %.2X:%02X:%02X:%02X:%02X:%02X ==> %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
        p[6]&n, p[7]&n, p[8]&n, p[9]&n, p[10]&n, p[11]&n,
        p[0]&n, p[1]&n, p[2]&n,p[3]&n, p[4]&n, p[5]&n);

        ip_head = eth_head + 14;  
        p = ip_head + 12;
        
        printf("IP: %d.%d.%d.%d => %d.%d.%d.%d\n",
        p[0]&0XFF, p[1]&0XFF, p[2]&0XFF, p[3]&0XFF,
        p[4]&0XFF, p[5]&0XFF, p[6]&0XFF, p[7]&0XFF);

        protocal_type = (ip_head + 9)[0];
        p = ip_head + 20;
        printf("Protocol: ");

        switch(protocal_type)
        {
            case IPPROTO_ICMP: printf("ICMP\n");break;

            case IPPROTO_IGMP: printf("IGMP\n");break;

            case IPPROTO_IPIP: printf("IPIP\n");break;

            case IPPROTO_TCP :
            case IPPROTO_UDP : 
            printf("%s,", protocal_type == IPPROTO_TCP ? "TCP": "UDP"); 
            printf("source port: %u, ", (p[0]<<8)&0XFF00 | p[1]&0XFF);
            printf("dest port: %u\n", (p[2]<<8)&0XFF00 | p[3]&0XFF);
            break;

            case IPPROTO_RAW : printf("RAW\n");break;

            default:printf("Unkown, please query in include/linux/in.h\n");
        }
    }
}
