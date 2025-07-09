#include "../include/includes.h"
#include "../include/send_data.h"

void send_data(int socket_peer, fd_set* reads) {

    if (FD_ISSET(0, reads)) {

        char read[4096];

        if (!fgets(read, 4096, stdin)) exit(1);
        printf("Sending %s", read);
        
        int bytes_sent = send(socket_peer, read, strlen(read), 0);
        printf("Sent %d bytes.\n", bytes_sent);

    }

}
