#include "includes.h"
#include "print_host_ip_and_service_info.h"

void print_host_ip_and_service_info(struct addrinfo* peer_address) {

    char host_ip[100];
    char host_service[100];
    
    getnameinfo(peer_address->ai_addr, peer_address->ai_addrlen,
                host_ip, sizeof(host_ip),
                host_service, sizeof(host_service),
                NI_NUMERICHOST);
    
    printf("Target host IP and service: %s, %s\n", host_ip, host_service);

}
