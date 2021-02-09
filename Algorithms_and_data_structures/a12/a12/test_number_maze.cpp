#include <iostream>
#include "number_maze.h"

using namespace std;

int main(){
    int n;
    cout << "Enter the dimensions of the grid" << endl;
    cin >> n;
    Puzzleboard myboard(n);
    myboard.printboard();
    return 0;
}