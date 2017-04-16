CFLAGS = -g

all:	factorial

clean:
	rm *.o

factorial:	factorial.o \
		factorial_main.o
	gcc -o $@ $^