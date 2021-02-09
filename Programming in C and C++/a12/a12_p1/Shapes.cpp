// please refer to shapes.h for methods documentation

#include <iostream>
#include "Shapes.h"
#include <cmath>
#include <cstring>


using namespace std; 

Shape::Shape(const string& n) : name(n) {
}

string Shape::getname() const{
    return name;
}

void Shape::setname(const string& name){
    this->name = name;
}

void Shape::printName() const {
	cout << name << endl;
}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}


void CenteredShape::setx(double x){
    this->x = x;
}

void CenteredShape::sety(double y){
    this->y = y;
}

double CenteredShape::getx() const{
    return x;
}

double CenteredShape::gety() const{
    return y;
}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}

int RegularPolygon::getedges() const{
    return EdgesNumber;
}

void RegularPolygon::setedges(int edges){
    this->EdgesNumber = edges;
}

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) 
{
	Radius = r;
}

Hexagon::Hexagon(const string& name, double x, double y, double side, const std::string& color) :
RegularPolygon(name,x,y,6){
    this->side = side;
    this->color = color;
}


Hexagon::Hexagon(const Hexagon& copy): 
RegularPolygon(copy.getname(), copy.getx(), copy.gety(), 6){
    side = copy.getside();
    color = copy.getcolor();
}

Hexagon::~Hexagon(){
}

double Hexagon::getside() const{
    return side;
}

string Hexagon::getcolor() const{
    return color;
}

void Hexagon::setcolor(string& color){
    this->color = color;
}

void Hexagon::setside(double side){
    this->side = side;
}

double Hexagon::Perimeter(){
    return (6 * side);
}

double Hexagon::Area(){
    return (((3 * sqrt(3)) / 2) * side * side);
}