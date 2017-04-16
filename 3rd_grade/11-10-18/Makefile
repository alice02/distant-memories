CFLAGS = -g

BIN =	test_delete \
	list_delete

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

test_delete:	/home/jugyou/j3/prog/j09/11-10-18/libs/print_list.o \
		/home/jugyou/j3/prog/j09/11-10-18/libs/append.o \
		/home/jugyou/j3/prog/j09/11-10-18/libs/list_main.o \
		delete.o
	gcc -o $@ $^

list_delete:	print_list.o \
		append.o \
		list_main.o \
		delete.o
	gcc -o $@ $^