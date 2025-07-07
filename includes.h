#ifndef INCLUDES_H
#define INCLUDES_H

#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int                 get_socket_peer                 (struct addrinfo* peer_address);
void                connect_to_peer                 (int socket_peer, struct addrinfo* peer_address);
void                receive_data                    (int socket_peer, fd_set* reads);
int                 establish_connection            (char* hostname, char* port);
void                select_or_error                 (int socket_peer, fd_set* reads);
void                send_data                       (int socket_peer, fd_set* reads);

#endif
