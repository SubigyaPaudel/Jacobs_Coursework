/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p06.c
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter c1, c2("Ram"), c3("Shyam", 2, 4), c4("Hari", 3,7);
 	cout << "These critters have been created: \n" << endl;
	c1.print();
	c2.print();
	c3.print();
    c4.print();
    cout << "Setting the hunger levels to 2 we get\n" << endl;
    c1.setHunger(2);
    c2.setHunger(2);
    c3.setHunger(2);
    c4.setHunger(2);
    c1.print();
	c2.print();
	c3.print();
    c4.print();
	return 0;
}
