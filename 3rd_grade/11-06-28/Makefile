all:	struct_change1 \
	struct_change2 \
	struct_change3 \
	linear_search

struct_change1:	struct_change1.o
	gcc -o $@ $^

struct_change2:	struct_change2.o
	gcc -o $@ $^

struct_change3: struct_change3.o
	gcc -o $@ $^

linear_search:	linear_search.o \
		linear_search_main.o \
		quick_sort.o
	gcc -o $@ $^
