all: randev.c
	gcc -o randev randev.c
run: randev
	./randev
clean: 
	rm randev rand_nums
