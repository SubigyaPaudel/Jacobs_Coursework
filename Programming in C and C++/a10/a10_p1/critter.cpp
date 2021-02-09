/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p01.c
*/


#include <iostream>
#include "Critter.h"

using namespace std;

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger << "." << endl;
}

int Critter::getHunger() {
	return hunger;
}

void Critter::setheight(double newheight){
	height = newheight;
}

double Critter::getheight(){
	return height;
}

Critter::Critter(){
	name = "default_critter";
	height = 5.0;
	hunger = 0; 
	boredom = 0;
	cout << "Calling constructor Critter()" << endl;
}
