objects = tcp_client.o validate_inputs.o

tcp_client : $(objects)
	cc -o tcp_client $(objects)

tcp_client.o : includes.h
validate_inputs.o : includes.h validate_inputs.h

.PHONY : clean
clean :
	rm tcp_client $(objects)
