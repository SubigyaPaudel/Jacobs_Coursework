all : command1 command2
	./test1

command1: optimal_meeting_point.py test_meeting_point.py
	python test_meeting_point.py

command2: number_maze.h number_maze.cpp test_number_maze.cpp
	g++ -Wall number_maze.cpp test_number_maze.cpp -o test1

clear:
	rm -f test1