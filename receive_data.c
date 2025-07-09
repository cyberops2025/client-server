#include "includes.h"
#include "receive_data.h"

void receive_data(int socket_peer, fd_set* reads) {

    if (FD_ISSET(socket_peer, reads)) {

        char read[4096];

        int bytes_received = recv(socket_peer, read, 4096, 0);
        if (bytes_received < 1) {
            printf("Connection closed by peer.\n");
            exit(1);
        }

        printf("Received (%d bytes), %.*s", bytes_received, bytes_received, read);
        
    }

}
