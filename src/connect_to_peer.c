#include "../include/includes.h"
#include "../include/connect_to_peer.h"

void connect_to_peer(int socket_peer, struct addrinfo* peer_address) {

    int status = connect(socket_peer, peer_address->ai_addr, peer_address->ai_addrlen);
    if (status != 0) {
        fprintf(stderr, "connect() failed. (%d)\n", errno);
        exit(1);
    }

}
