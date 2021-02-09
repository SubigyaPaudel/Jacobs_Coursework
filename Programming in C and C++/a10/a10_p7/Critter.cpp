/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p07.c
*/


#include <iostream>
#include "Critter.h"
#include <string>

using namespace std;

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = inttopercent(newhunger);
}

int Critter::getHunger() {
	return percenttoint(hunger);
}

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << getHunger() << ". ";
    cout << "My height is " << height << " and my boredom is " << boredom;
	cout << ". My thirst is " << getthirst() << endl;
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
	hunger = 0.0; 
	boredom = 0;
}

Critter::Critter(std::string s){
	name = s;
	height = 5.0;
	hunger = 0.0; 
	boredom = 0;
	thirst = hunger;
}

Critter::Critter(std::string newname, int newhunger, int newboredom, double newheight){
    name = newname;
	hunger = inttopercent(newhunger);
	boredom = newboredom;
    height = newheight;
	thirst = hunger;
}

Critter::Critter(std::string newname, int newhunger, int newboredom, double newheight, int newthirst){
	name = newname;
	hunger = inttopercent(newhunger);
	boredom = newboredom;
	height = newheight;
	thirst = inttopercent(newthirst);
}

double Critter::inttopercent(int x){
	return ((double) x / 10.0);
}

int Critter::percenttoint(double x){
	return ((int) (x * 10.0));
}

void Critter::setthirst(int newthirst){
	thirst = inttopercent(newthirst);
}

int Critter::getthirst(){
	return percenttoint(thirst);
}