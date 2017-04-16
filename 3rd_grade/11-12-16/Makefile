CFLAGS = -g

BIN = 	tree

all:	$(BIN)

clean:
	rm -f $(BIN)
	rm -f *.o

tree:		lib/tree_main.o \
		lib/tree_make.o \
		tree_print.o
	gcc -o $@ $^
