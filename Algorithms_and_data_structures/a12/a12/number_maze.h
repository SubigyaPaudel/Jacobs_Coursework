#ifndef NUMBER_MAZE_H
#define NUMBER_MAZE_H
#include <cstdlib>

class Puzzleboard{
    private:
        int dimension;
        int** board;
        int* currentposition;
    public:
        Puzzleboard(int dimension);
        bool makemove(int direction);
        bool getresult();
        void printboard();
};



#endif