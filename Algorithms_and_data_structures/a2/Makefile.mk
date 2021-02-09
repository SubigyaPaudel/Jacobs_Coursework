all: test1 test2 test3 test4 test5 test6 test7 test8
	./test1
	./test2
	./test3
	./test4
	./test5
	./test6
	./test7
	./test8
	clean

test1: a2_p1.cpp
	g++ -Wall a2_p1.cpp -o test1

test2: a2_p2.cpp
	g++ -Wall a2_p2.cpp -o test2

test3: testWindgauge.cpp Windgauge.cpp
	g++ -Wall testWindgauge.cpp Windgauge.cpp -o test3

test4: a2_p4.cpp
	g++ -Wall a2_p4.cpp -o test4

test5: a2_p5.cpp
	g++ -Wall a2_p5.cpp -o test5

test6: Access.cpp testAccess.cpp
	g++ -Wall Access.cpp testAccess.cpp -o test6

test7: a2_p7.cpp
	g++ -Wall a2_p7.cpp -o test7

test8: Access2.cpp testAccess2.cpp
	g++ -Wall Access2.cpp testAccess2.cpp -o test8

clean:
	rm -f test1 && rm -f test2 && rm -f test3 && rm -f test4 && rm -f test5 && rm -f test6 && rm -f test7 && rm -f test8 && rm -f *.o