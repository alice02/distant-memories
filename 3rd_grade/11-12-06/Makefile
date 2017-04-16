CFLAGS = -g

BIN =	insert

all:	$(BIN)

clean:
	rm -f $(BIN)
	rm -f *.o

insert:		insert.o
	gcc -o $@ $^