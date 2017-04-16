CFLAGS = -g

BIN =	bin_sort \
	bin_sort2

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

bin_sort:	bin_sort.o \
		bin_sort_main.o
	gcc -o $@ $^

bin_sort2:	bin_sort.o \
		bin_sort_main2.o
	gcc -o $@ $^
