
all: command1 ./test clear

command1: heap.h heap_sort.cpp
	g++ -Wall heap_sort.cpp -o test

clear: test
	rm -f test && rm -f *.o