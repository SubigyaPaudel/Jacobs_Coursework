/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p02.c
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter c;

	string name, gender;
	int hunger, age;
 
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
    cout << "Age: ";
    cin >> age;
    c.setage(age);
    cout << "Gender: ";
    cin >> gender;
    c.setgender(gender);
	cout << "You have created:" << endl;
	c.print();
	cout << c.getgender() << endl; // to demonstate that the getters for the new methods work
	cout << c.getage() << endl;		// same here
	return 0;
}
