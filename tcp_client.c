#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        fprintf(stderr, "usage: tcp_client hostname port");
        exit(1);
    }

    return 0;

}
