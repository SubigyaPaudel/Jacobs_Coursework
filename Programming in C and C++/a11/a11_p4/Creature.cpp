/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p04.c
*/


#include "Creature.h"
#include <iostream>

using namespace std;

Creature::Creature(int a): distance(a){
    cout << "Creature created" << endl;
}    

void Creature::run() const
{ 
    cout << "running " << distance << " meters!\n";
}  

Creature::~Creature(){
    cout << "Now the creature is gone" << endl;
}

Wizard::Wizard(int a, int b) : Creature(a)
{
    distFactor = b;
    cout << "Wizard created" << endl;
}  

void Wizard::hover() const
{
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

Wizard::~Wizard(){
    cout << "Now the wizard is gone" << endl;
}

Golem::Golem(int a, float b) : Creature(a) {
    radius = b;
    cout << "Golem created" << endl;
}

Golem::~Golem(){ 
    cout << "Now the Golem is gone" << endl;
}

void Golem::roll(){
    float dist = 2 * radius;
    cout << "Rolling " << dist << "meters" <<  endl;
}


Giant::Giant(int a, float b) : Creature(a){
    height = a;
    cout << "Giant created" << endl;
}

Giant::~Giant(){
    cout << "Now the Giant is gone" << endl;
}

void Giant::leap() const{
    cout << "Leaping " << 2.0 * height << " meters" << endl; 
}
