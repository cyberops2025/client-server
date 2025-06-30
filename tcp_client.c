#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>

void validate_inputs(int argc);

struct addrinfo *get_peer_address(char *hostname, char *port);

int main(int argc, char *argv[]) {
    
    validate_inputs(argc);
    // These also need to be validated.
    // Focused on learning basics. Will validate later.
    char *hostname = argv[1];
    char *port = argv[2];
    
    struct addrinfo *peer_address = get_peer_address(hostname, port);

    freeaddrinfo(peer_address);

    return 0;

}

void validate_inputs(int argc) {

    if (argc < 3) {
        fprintf(stderr, "usage: tcp_client hostname port\n");
        exit(1);
    }

}

struct addrinfo *get_peer_address(char *hostname, char *port) {

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    
    struct addrinfo *peer_address = malloc(sizeof(struct addrinfo));
    int ret = getaddrinfo(hostname, port, &hints, &peer_address);
    if (ret != 0) {
        fprintf(stderr, "getaddrinfo() failed. (%d)\n", errno);
        exit(1);
    }

    return peer_address;

}
