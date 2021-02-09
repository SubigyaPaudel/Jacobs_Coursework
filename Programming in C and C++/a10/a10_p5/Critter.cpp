/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p05.c
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
    cout << "My height is " << height << " and my boredom is " << boredom << endl;
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

void Critter::setBoredom(int newboredom){
    boredom = newboredom;
}

Critter::Critter(){
	name = "default_critter";
	height = 5.0;
	hunger = 0; 
	boredom = 0;
	cout << "Calling constructor Critter()" << endl;
}

Critter::Critter(std::string s){
	name = s;
	height = 5.0;
	hunger = 0; 
	boredom = 0;
	cout << "Calling constructor Critter(std::string)" << endl;
}

Critter::Critter(std::string newname, int newhunger, int newboredom, double newheight){
    name = newname;
	hunger = newhunger;
	boredom = newboredom;
    height = newheight;
	cout << "Calling constructor Critter(std::string newname, int newhunger, int newboredom, double newheight)" << endl;
}
