#include "Box.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    int num;
    double newheight, newwidth, newdepth;
    cout << "Enter the number of boxes" << endl;
    cin >> num;
    Box* pointer = new Box[2 * num];
    for(int i = 0; i <= num-1; i++){
        cout << "Enter the height of the box" << endl;
        cin >> newheight;
        cout << "Enter the width of the box" << endl;
        cin >> newwidth;
        cout << "Enter the depth of the box" << endl;
        cin >> newdepth;
        pointer[i] = Box(newheight, newwidth, newdepth);
    }
    for(int i = 0; i <= num - 1; i++){
        pointer[num+i] = Box(pointer[i]&);
    }
    for(int i = 0; i <= 2*num - 1; i++){
        cout << "The volume of the " << (i + 1) << "th box is = " << pointer[i].volume() << endl; 
    }
    delete [] pointer;
    return 0;
}