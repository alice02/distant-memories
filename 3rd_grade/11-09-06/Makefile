BIN =	hanoi \
	test_hanoi_main \
	test_init_tower \
	test_make_stack \
	test_pop \
	test_print_tower \
	test_push

CFLAGS = -g

all:	$(BIN)

hanoi:		hanoi_main.o \
		init_tower.o \
		make_stack.o \
		pop.o \
		print_tower.o \
		push.o
	gcc -o $@ $^ -lm

test_hanoi_main:hanoi_main.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/init_tower.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/make_stack.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/pop.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/print_tower.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/push.o
	gcc -o $@ $^ -lm

test_init_tower:/home/jugyou/j3/prog/j09/11-09-06/libs/hanoi_main.o \
		init_tower.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/make_stack.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/pop.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/print_tower.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/push.o
	gcc -o $@ $^ -lm

test_make_stack:/home/jugyou/j3/prog/j09/11-09-06/libs/hanoi_main.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/init_tower.o \
		make_stack.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/pop.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/print_tower.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/push.o
	gcc -o $@ $^ -lm

test_pop:	/home/jugyou/j3/prog/j09/11-09-06/libs/hanoi_main.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/init_tower.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/make_stack.o \
		pop.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/print_tower.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/push.o
	gcc -o $@ $^ -lm

test_print_tower:	/home/jugyou/j3/prog/j09/11-09-06/libs/hanoi_main.o \
			/home/jugyou/j3/prog/j09/11-09-06/libs/init_tower.o \
			/home/jugyou/j3/prog/j09/11-09-06/libs/make_stack.o \
			/home/jugyou/j3/prog/j09/11-09-06/libs/pop.o \
			print_tower.o \
			/home/jugyou/j3/prog/j09/11-09-06/libs/push.o
	gcc -o $@ $^ -lm

test_push:	/home/jugyou/j3/prog/j09/11-09-06/libs/hanoi_main.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/init_tower.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/make_stack.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/pop.o \
		/home/jugyou/j3/prog/j09/11-09-06/libs/print_tower.o \
		push.o
	gcc -o $@ $^ -lm

clean:
	rm -r *.o
	rm -r $(BIN)
