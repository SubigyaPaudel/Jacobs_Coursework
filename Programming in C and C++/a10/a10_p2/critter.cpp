/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p02.c
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
	cout << "I am " << name << ". My hunger level is " << hunger << ". I am " << age << " years old, and I am a " << gender << "." << endl;
}

int Critter::getHunger() {
	return hunger;
}

void Critter::setgender(string& newgender){
    gender = newgender;
}

void Critter::setage(int newage){
    age = newage;
}

int Critter::getage(){
	return age;
}

string Critter::getgender(){
	return gender;
}