CFLAGS = -g

BIN =	test_print_list \
	test_append \
	test_list_main \
	list

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

test_print_list:	print_list.o \
			/home/jugyou/j3/prog/j09/11-10-11/libs/append.o \
			/home/jugyou/j3/prog/j09/11-10-11/libs/list_main.o
	gcc -o $@ $^

test_append:	/home/jugyou/j3/prog/j09/11-10-11/libs/print_list.o \
		append.o \
		/home/jugyou/j3/prog/j09/11-10-11//libs/list_main.o
	gcc -o $@ $^

test_list_main:	/home/jugyou/j3/prog/j09/11-10-11/libs/print_list.o \
		/home/jugyou/j3/prog/j09/11-10-11/libs/append.o \
		list_main.o
	gcc -o $@ $^

list:		print_list.o \
		append.o \
		list_main.o
	gcc -Wall -o $@ $^