#include <iostream>
#include "Person.h"

using namespace std;

void person::setname(string newname){
    name = newname;
}

void person::setage(int newage){
    age = newage;
}

void person::setheight(double newheight){
    height = newheight;
}

void person::setrelative(person* arelative){
    relative = arelative;
}

string person::getname(){
    return name;
}

int person::getage(){
    return age;
}

int person::getheight(){
    return height;
}

person person::getrelative(){
    return *relative;
}