#include "../include/includes.h"
#include "../include/establish_connection.h"
#include "../include/get_peer_address.h"
#include "../include/print_host_ip_and_service_info.h"
#include "../include/get_socket_peer.h"
#include "../include/connect_to_peer.h"

int establish_connection(char* hostname, char* port) {

    struct addrinfo* peer_address = get_peer_address(hostname, port);
    print_host_ip_and_service_info(peer_address);
    int socket_peer = get_socket_peer(peer_address);
    connect_to_peer(socket_peer, peer_address);
    freeaddrinfo(peer_address);

    return socket_peer;

}
