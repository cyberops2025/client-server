#include "includes.h"
#include "get_peer_address.h"

struct addrinfo* get_peer_address(char* hostname, char* port) {

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    
    struct addrinfo* peer_address = malloc(sizeof(struct addrinfo));
    int status = getaddrinfo(hostname, port, &hints, &peer_address);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo() failed. (%d)\n", errno);
        exit(1);
    }

    return peer_address;

}
