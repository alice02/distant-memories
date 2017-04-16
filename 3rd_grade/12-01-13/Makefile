CFLAGS = -g

BIN =	merge_sort_list \
	test_merge_sort_list \
	test_merge_list

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

merge_sort_list:	merge_list.o \
			merge_sort_list.o \
			merge_sort_list_main.o
	gcc -o $@ $^

test_merge_sort_list:	~/j3/12-01-13/libs/merge_list.o \
			merge_sort_list.o \
			~/j3/12-01-13/libs/merge_sort_list_main.o
	gcc -o $@ $^

test_merge_sort_list_main:	~/j3/12-01-13/libs/merge_list.o \
				~/j3/12-01-13/libs/merge_sort_list.o \
				merge_sort_list_main.o
	gcc -o $@ $^

test_merge_list:	merge_list.o \
			~/j3/12-01-13/libs/merge_sort_list.o \
			~/j3/12-01-13/libs/merge_sort_list_main.o
	gcc -o $@ $^
