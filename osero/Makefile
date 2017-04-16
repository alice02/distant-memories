CFLAGS = -g

BIN =	client \
	server

all:	$(BIN)

client:		client.o
	gcc -o $@ $^

server:		server.o
	gcc -o $@ $^

clean:
	rm -f $(BIN)
	rm -f *.o
