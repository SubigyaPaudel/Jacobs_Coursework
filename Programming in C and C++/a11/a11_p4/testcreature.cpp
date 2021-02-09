/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p04.c
*/


#include <iostream>
#include "Creature.h"

using namespace std;

int main()
{ 
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();
    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();
    Golem g;
    g.roll();
    g.run();
    Giant h;
    h.leap();
    h.run();
    return 0;
} 

