/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p06.c
*/

#include "Shapes.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    Circle a("Circle1", 4.5, 4.5, 9.0);
    Square b("Square1", 0.0, 0.0, 5);
    Rectangle c;
    cout << a.getname() << "'s area is " << a.area() << endl;
    cout << a.getname() << "'s perimeter is " << a.perimeter() << endl;
    cout << b.getname() << "'s area is " << b.area() << endl;
    cout << b.getname() << "'s perimeter is " << b.perimeter() << endl;
    cout << c.getname() << "'s area is " << c.area() << endl;
    cout << c.getname() << "'s perimeter is " << c.perimeter() << endl;
    return 0;
}
