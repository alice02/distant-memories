BIN = 	init_fig_test \
	judge_fig_test \
	hit_and_blow

CFLAGS = -g

all:	$(BIN)

init_fig_test:	init_fig.o \
		init_fig_test_main.o
	gcc -o $@ $^

judge_fig_test:	judge_fig.o \
		judge_fig_test_main.o
	gcc -o $@ $^

hit_and_blow:	init_fig.o \
		judge_fig.o \
		hit_and_blow_main.o
	gcc -o $@ $^

clean:
	rm -r *o
	rm -r $(BIN)
