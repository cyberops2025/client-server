#ifndef INCLUDES_H
#define INCLUDES_H

#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void                receive_data                    (int socket_peer, fd_set* reads);
void                select_or_error                 (int socket_peer, fd_set* reads);
void                send_data                       (int socket_peer, fd_set* reads);

#endif
