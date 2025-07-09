#include "../include/includes.h"
#include "../include/validate_inputs.h"

void validate_inputs(int argc) {

    if (argc < 3) {
        fprintf(stderr, "usage: tcp_client hostname port\n");
        exit(1);
    }

}
