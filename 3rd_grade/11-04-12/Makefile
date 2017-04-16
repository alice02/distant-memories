test_average:	ex_average_main.o \
		ex_input.o \
		average.o
	gcc -o $@ $^

test_input:	ex_average_main.o \
		input.o \
		ex_average.o
	gcc -o $@ $^

test_main:	average_main.o \
		ex_input.o \
		ex_average.o
	gcc -o $@ $^

average:	average_main.o \
		input.o \
		average.o
	gcc -o $@ $^
