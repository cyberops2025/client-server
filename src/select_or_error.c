#include "../include/includes.h"
#include "../include/select_or_error.h"

void select_or_error(int socket_peer, fd_set* reads) {

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 100000;

    int status = select(socket_peer+1, reads, 0, 0, &timeout);
    if (status < 0) {
        fprintf(stderr, "select() failed. (%d)\n", errno);
        exit(1);
    }

}
