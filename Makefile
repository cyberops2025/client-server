objects = 	tcp_client.o validate_inputs.o establish_connection.o get_peer_address.o \
			print_host_ip_and_service_info.o get_socket_peer.o connect_to_peer.o \
			receive_data.o select_or_error.o send_data.o

tcp_client : $(objects)
	cc -o tcp_client $(objects)

tcp_client.o : 						includes.h
validate_inputs.o : 				validate_inputs.h includes.h
establish_connection.o : 			establish_connection.h includes.h
get_peer_address.o : 				get_peer_address.h includes.h
print_host_ip_and_service_info.o : 	print_host_ip_and_service_info.h includes.h
get_socket_peer.o : 				get_socket_peer.h includes.h
connect_to_peer.o :					connect_to_peer.h includes.h
receive_data.o :					receive_data.h includes.h
select_or_error.o :					select_or_error.h includes.h
send_data.o :						send_data.h includes.h

.PHONY : clean
clean :
	rm tcp_client $(objects)
