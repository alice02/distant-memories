CFLAGS = -g

BIN = 	merge_sort \
	test_merge_sort \
	test_merge_sort_main

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

merge_sort:	merge_sort.o \
		merge_sort_main.o
	gcc -o $@ $^
