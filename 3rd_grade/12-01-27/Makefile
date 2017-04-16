CFLAGS = -g

BIN =	dist_count_sort \
	dist_count_sort2

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

dist_count_sort:	dist_count_sort.o \
			dist_count_sort_main.o
		gcc -o $@ $^

dist_count_sort2:	dist_count_sort.o \
			dist_count_sort_main2.o
		gcc -o $@ $^