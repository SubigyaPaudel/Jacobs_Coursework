/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p03.cpp
*/

#include <iostream>
#include "City.h"

using namespace std;

void city::setname(std::string& newname){
    name = newname;
}      

void city::setpopulation(int newpopulation){
    population = newpopulation;
}

void city::setmayor(std::string& newmayor){
    mayor = newmayor;
}

void city::setarea(double newarea){
    area = newarea;
}

string city::getname(){
    return name;
}   

int city::getpopulation(){
    return population;
}

string city::getmayor(){
    return mayor;
}

double city::getarea(){
    return area;
}