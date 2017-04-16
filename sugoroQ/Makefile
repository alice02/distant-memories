CFLAGS = -g

BIN =	sugoroQ_server \
		sugoroQ_client

all:	$(BIN)

sugoroQ_server:			server.o \
				quiz.o \
				network.o \
				station.o \
				test_print.o
	gcc -o $@ $^

sugoroQ_client:			client.o \
				network.o \
				station.o \
				disp.o \
				test_print.o
	gcc -o $@ $^ -lpthread

clean:
	rm -f *.o
	rm -f $(BIN)
