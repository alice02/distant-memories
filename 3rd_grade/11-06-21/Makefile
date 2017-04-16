all:	define1 define2	queue

define1:	define1.o
	gcc -o $@ $^

define2:	define2.o
	gcc -o $@ $^

queue:		queue.o \
		queue_main.o
	gcc -Wall -o $@ $^
