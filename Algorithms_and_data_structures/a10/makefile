all: test1
	./test
	remove

test1: hash_table.cpp hash_table.h test_hash_table.cpp
	g++ -Wall test_hash_table.cpp hash_table.cpp -o test

remove:
	rm -f *.o && rm -f test