#include <stdio.h>
#include <stdlib.h>

void validate_inputs(int argc);

int main(int argc, char *argv[]) {
    
    validate_inputs(argc);
    
    return 0;

}

void validate_inputs(int argc) {
    if (argc < 3) {
        fprintf(stderr, "usage: tcp_client hostname port\n");
        exit(1);
    }
}
