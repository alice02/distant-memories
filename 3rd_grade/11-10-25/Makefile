CFLAGS = -g

BIN =	list_reverse

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

list_reverse:	print_list.o \
		append.o \
		list_main.o \
		reverse.o
	gcc -o $@ $^
