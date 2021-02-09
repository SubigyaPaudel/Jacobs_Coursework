#include <iostream>
#include "Shapes.h"

using namespace std;

int main(){
    Hexagon a("Hexagon1",0.0, 0.0, 9,"Blue");
    Hexagon b("Hexagon2", 1.0, 2.0,15, "Green");
    Hexagon c(b);
    cout << "Perimeter of " << a.getname() << "=" << a.Perimeter() << endl;
    cout << "Perimeter of " << b.getname() << "=" << b.Perimeter() << endl;
    cout << "Perimeter of " << c.getname() << "=" << c.Perimeter() << endl;
    cout << "Area of " << a.getname() << "=" << a.Area() << endl;
    cout << "Area of " << b.getname() << "=" << b.Area() << endl;
    cout << "Area of " << c.getname() << "=" << c.Area() << endl;
    return 0;
}