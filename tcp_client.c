#include "includes.h"
#include "validate_inputs.h"

struct addrinfo*    get_peer_address                (char* hostname, char* port);
void                print_host_ip_and_service_info  (struct addrinfo* peer_address);
int                 get_socket_peer                 (struct addrinfo* peer_address);
void                connect_to_peer                 (int socket_peer, struct addrinfo* peer_address);
void                receive_data                    (int socket_peer, fd_set* reads);
int                 establish_connection            (char* hostname, char* port);
void                select_or_error                 (int socket_peer, fd_set* reads);
void                send_data                       (int socket_peer, fd_set* reads);

int main(int argc, char* argv[]) {
    
    validate_inputs(argc);

    // These also need to be validated.
    // Focused on learning basics. Will validate later.
    char* hostname  = argv[1];
    char* port      = argv[2];
    
    int socket_peer = establish_connection(hostname, port);

    printf("Connected.\n");

    while (1) {

        fd_set reads;

        FD_ZERO(&reads);
        FD_SET(socket_peer, &reads);    // SOCKET for receiving
        FD_SET(0, &reads);              // STDIN for sending

        select_or_error(socket_peer, &reads);
        receive_data(socket_peer, &reads);
        send_data(socket_peer, &reads);

    }

    close(socket_peer);

    return 0;

}

int establish_connection(char* hostname, char* port) {

    struct addrinfo* peer_address = get_peer_address(hostname, port);
    print_host_ip_and_service_info(peer_address);
    int socket_peer = get_socket_peer(peer_address);
    connect_to_peer(socket_peer, peer_address);
    freeaddrinfo(peer_address);

    return socket_peer;

}

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

void print_host_ip_and_service_info(struct addrinfo* peer_address) {

    char host_ip[100], host_service[100];
    getnameinfo(peer_address->ai_addr, peer_address->ai_addrlen,
                host_ip, sizeof(host_ip),
                host_service, sizeof(host_service),
                NI_NUMERICHOST);
    printf("Target host IP and service: %s, %s\n", host_ip, host_service);

}

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

void connect_to_peer(int socket_peer, struct addrinfo* peer_address) {

    int status = connect(socket_peer, peer_address->ai_addr, peer_address->ai_addrlen);
    if (status != 0) {
        fprintf(stderr, "connect() failed. (%d)\n", errno);
        exit(1);
    }

}

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

void send_data(int socket_peer, fd_set* reads) {

    if (FD_ISSET(0, reads)) {
        char read[4096];
        if (!fgets(read, 4096, stdin)) exit(1);
        printf("Sending %s", read);
        int bytes_sent = send(socket_peer, read, strlen(read), 0);
        printf("Sent %d bytes.\n", bytes_sent);
    }

}
