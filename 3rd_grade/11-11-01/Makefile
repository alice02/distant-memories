CFLAGS = -g

BIN = 	list_c

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

list_c:		append_c.o \
		list_main_c.o \
		print_list_c.o
	gcc -o $@ $^
