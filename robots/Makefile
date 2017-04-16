CFLAGS = -g

BIN =	robots

all:	$(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

robots:		robots_main.o \
		move.o \
		disp.o \
		init.o \
		judge.o \
		score.o \
		getchar.o
	gcc -o $@ $^
