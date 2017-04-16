CFLAGS = -g

BIN =	brute_force_search \
	test_brute_force_search \
	test_string_search_main

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

brute_force_search:	brute_force_search.o \
			string_search_main.o
	gcc -o $@ $^

test_brute_force_search:	brute_force_search.o \
				libs/string_search_main.o
	gcc -o $@ $^

test_string_search_main:	libs/brute_force_search.o \
				string_search_main.o
	gcc -o $@ $^