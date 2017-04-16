CFLAGS = -g

BIN = list_d

all:	$(BIN)

clean:
	rm -f $(BIN)
	rm -f *.o

list_d:		append_d.o \
		print_list_d.o \
		list_main_d.o \
		insert_d.o \
		delete_d.o
	gcc -o $@ $^
