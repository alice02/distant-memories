CFLAGS = -g

BIN =	radix_sort \
	test_radix_sort \
	test_radix_sort_main

all:	$(BIN)

clean:
	rm -rf *.o
	rm -rf $(BIN)

radix_sort:	radix_sort.o \
		radix_sort_main.o
	gcc -o $@ $^

test_radix_sort:	radix_sort.o \
			libs/radix_sort_main.o
	gcc -o $@ $^

test_radix_sort_main:	libs/radix_sort.o \
			radix_sort_main.o
	gcc -o $@ $^