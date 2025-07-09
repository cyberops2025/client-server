#include "includes.h"
#include "validate_inputs.h"
#include "establish_connection.h"
#include "select_or_error.h"
#include "receive_data.h"
#include "send_data.h"

int main(int argc, char* argv[]) {
    
    validate_inputs(argc);

    char* hostname  = argv[1]; // Need to validate
    char* port      = argv[2]; // Need to validate
    
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
