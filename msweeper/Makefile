CFLAGS = -g

BIN =	msweeper

all:	$(BIN)

clean:
	rm -f $(BIN)
	rm -f *.o

msweeper:	message.o \
		record.o \
		init.o \
		draw_field.o \
		cursor.o \
		key.o \
		getchar.o \
		msweeper.o \
		main.o
	gcc -Wall -o $@ $^ -lcurses

