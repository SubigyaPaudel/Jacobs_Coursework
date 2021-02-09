#include <iostream>
#include "Creature.h"


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
