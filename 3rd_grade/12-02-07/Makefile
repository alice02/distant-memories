CFLAGS = -g

BIN = 	bm_search \
	bm_search2

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

bm_search:	Boyer-Moore.o \
		string_search_main.o
	gcc -o $@ $^

bm_search2:	Boyer-Moore.o \
		string_search_main2.o
	gcc -o $@ $^

