/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p01.c
*/

#include "Box.h"

Box::Box(){
    height = 0;
    width = 0;
    depth = 0;
}

Box::Box(double x, double y, double z){
    height = x;
    width = y;
    depth = z;
}

Box::Box(const Box& pointer){
    height = pointer.getheight();
    width = pointer.getwidth();
    depth = pointer.getdepth();
}

Box::~Box(){
}

void Box::setheight(double x){
    height = x;
}

void Box::setwidth(double y){
    width = y;
}

void Box::setdepth(double z){
    depth = z;
}

double Box::getheight() const{
    return height;
}

double Box::getdepth() const{
    return depth;
}

double Box::getwidth() const{
    return width;
}

double Box::volume(){
    double volume = height * width * depth;
    return volume;
}

