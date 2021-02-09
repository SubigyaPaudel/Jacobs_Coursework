/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p07.c
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter c1, c2("Harry"), c3("Peter", 3, 4, 4.56), c4("Frank", 3,7);
    Critter c5("Franz", 7, 8, 9, 10);
 	cout << "These critters have been created: \n" << endl;
	c1.print();
	c2.print();
	c3.print();
    c4.print();
    c5.print();
    cout << "Setting the hunger levels to 2 we get\n" << endl;
    c1.setHunger(2);
    c2.setHunger(2);
    c3.setHunger(2);
    c4.setHunger(2);
    c5.setHunger(2);
    c1.print();
	c2.print();
	c3.print();
    c4.print();
    c5.print();
	return 0;
}
