CFLAGS = -g

BIN = hangman

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

hangman:	hangman.o \
		getchar.o
	gcc -o $@ $^