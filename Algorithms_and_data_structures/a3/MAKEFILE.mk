all: test
	./test
	clean
	
test: selection_sort.cpp
	g++ -Wall selection_sort.cpp -o test

clean:
	rm -f test 
