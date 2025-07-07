#include "includes.h"
#include "establish_connection.h"
#include "get_peer_address.h"
#include "print_host_ip_and_service_info.h"

int establish_connection(char* hostname, char* port) {

    struct addrinfo* peer_address = get_peer_address(hostname, port);
    print_host_ip_and_service_info(peer_address);
    int socket_peer = get_socket_peer(peer_address);
    connect_to_peer(socket_peer, peer_address);
    freeaddrinfo(peer_address);

    return socket_peer;

}
