CFLAGS = -g

BIN = 	daifugo_server \
		daifugo_client


all:	$(BIN)


daifugo_server:	daifugo_server.o \
				player.o \
				card.o \
				disp.o \
				rule.o \
				network.o \
				getchar.o
	gcc -Wall -o $@ $^


daifugo_client:	daifugo_client.o \
				player.o \
				card.o \
				disp.o \
				rule.o \
				network.o \
				getchar.o
	gcc -Wall -o $@ $^


clean:
	rm -f $(BIN)
	rm -f *.o
