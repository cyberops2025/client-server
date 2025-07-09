# I found this example here:
# https://web.stanford.edu/class/archive/cs/cs107/cs107.1174/guide_make.html

CC =		gcc
# Will include debug info and not optimize
# so I can look at the assembly, etc.
CFLAGS =	-g -Wall -O0

SOURCES = 	tcp_client.c \
			connect_to_peer.c \
			establish_connection.c \
			get_peer_address.c \
			get_socket_peer.c \
			print_host_ip_and_service_info.c \
			receive_data.c \
			select_or_error.c \
			send_data.c \
			validate_inputs.c

OBJECTS =	$(SOURCES:.c=.o)
TARGET =	tcp_client

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJECTS) 
