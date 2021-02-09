/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p01.c
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter c;
	string name;
	int hunger;
 	cout << endl << "Please enter data: " << endl;
	cout << "Name: ";
	// cin >> name; will not work if name contains
	// spaces
	getline(cin, name);
	c.setName(name);
	c.setName(name);
	cout << "Hunger: ";
	cin >> hunger;
	c.setHunger(hunger);
	cout << "You have created:" << endl;
	c.print();
        return 0;
}
