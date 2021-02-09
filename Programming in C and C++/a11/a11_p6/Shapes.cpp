/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p06.c
*/


// please refer to shapes.h for methods documentation

#include <iostream>
#include "Shapes.h"

using namespace std; 

Shape::Shape(){
	name = "Triangle"; // since a triangle is the simplest shape
}

Shape::Shape(const string& n) : name(n) {
}

Shape::Shape(const Shape& shape){
	name = shape.getname();
}

void Shape::printName() const {
	cout << name << endl;
}

string Shape::getname() const{
	return name;
}

void Shape::setname(string newname){
	name = newname;
}

CenteredShape::CenteredShape() : Shape(){
	x = 0.0;		// the the co-ordinates of the shape to the origin
	y = 0.0;
}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

CenteredShape::CenteredShape(const CenteredShape& copy) : Shape(copy.getname()){
	x = copy.getx();
	y = copy.gety();
}

void CenteredShape::move(double nx, double ny){
	x = nx;
	y = ny;
}

double CenteredShape::getx() const{
	return x;
}

double CenteredShape::gety() const{
	return y;
}

RegularPolygon::RegularPolygon() : CenteredShape(){
	EdgesNumber = 3; // since the default shape is a triangle
}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}

RegularPolygon::RegularPolygon(const RegularPolygon& copy) :
CenteredShape(copy.getname(), copy.getx(), copy.gety()){
	EdgesNumber = copy.getedges();
}

void RegularPolygon::setedges(int ne){
	EdgesNumber = ne;
}

int RegularPolygon::getedges() const{
	return EdgesNumber;
}

Circle::Circle(): CenteredShape("Circle", 0.0, 0.0){
	Radius = 1.0;
}

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) 
{
	Radius = r;
}

Circle::Circle(const Circle& copy): CenteredShape(copy.getname(), copy.getx(), copy.gety()){
	Radius = copy.getradius();
}

void Circle::changeradius(double nr){
	Radius = nr;
}

double Circle::getradius() const{
	return Radius;
}

double Circle::perimeter() const{
	return (2 * pi * Radius);
}

double Circle::area() const{
	return (pi * Radius * Radius);
}

Rectangle::Rectangle() : RegularPolygon("Rectangle", 0.0 ,0.0 , 4)
{
	length = 2.0;
	breadth = 1.0;
}

Rectangle::Rectangle(const string& name, double x, double y, double nlength, double nbreadth) :
RegularPolygon(name, x, y, 4){
	length = nlength;
	breadth = nbreadth;
}

Rectangle::Rectangle(const Rectangle& another) :
RegularPolygon(another.getname(), another.getx(), another.gety(), another.getedges())
{
	length = another.getlength();
	breadth = another.getbreadth();
}

double Rectangle::getlength() const{
	return length;
}

double Rectangle::getbreadth() const{
	return breadth;
}

void Rectangle::setlength(double nlength){
	length = nlength;
}

void Rectangle::setbreadth(double nbreadth){
	breadth = nbreadth;
}

double Rectangle::area() const{
	return (length * breadth);
}

double Rectangle::perimeter() const{
	return 2*(length + breadth);
}

Square::Square() : Rectangle("Square", 0.0 , 0.0, 4.0, 4.0)
{
	side = 4;
}

Square::Square(const string& name, double x, double y, double sidelength):
Rectangle(name, x, y, sidelength, sidelength){
	side = sidelength;
}

Square::Square(Square& copy) : 
Rectangle(copy.getname(), copy.getx(), copy.gety(), copy.getlength(), copy.getbreadth()){
	side = copy.getside();
}

void Square::setside(double newside){
	side = newside;
	setlength(newside);
	setbreadth(newside);
}

double Square::getside() const{
	return side;
}

double Square::perimeter() const{
	return (4.0 * side);
}

double Square::area() const{
	return (side * side);
}