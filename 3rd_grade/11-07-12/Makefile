BIN =	select

CFLAGS = -g

all:	$(BIN)

select:		select.o \
		select_main.o
	gcc -Wall -o $@ $^

clean:
	rm -r *.o
	rm -r $(BIN)
