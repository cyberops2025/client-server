#include "includes.h"
#include "get_socket_peer.h"

int get_socket_peer(struct addrinfo* peer_address) {

    int socket_peer;
    
    socket_peer = socket(peer_address->ai_family, peer_address->ai_socktype,
                         peer_address->ai_protocol);
    if (socket_peer < 0) {
        fprintf(stderr, "socket() failed. (%d)\n", errno);
        exit(1);
    }

    return socket_peer;

}
