/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p06.c
*/

/* 
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>

const double pi = 3.14;

class Shape {			// base class
	private:   				// private access modifier: could also be protected
		std::string name;   // every shape will have a name
	public:
		Shape(const std::string&);  // builds a shape with a name
		Shape();					// empty shape
		Shape(const Shape&);		// copy constructor
		std::string getname() const;
		void setname(std::string newname);
		void printName() const ;  	// prints the name  
};

class CenteredShape : public Shape {  // inherits from Shape
	private: 
		double x,y;  // the center of the shape
	public:
		CenteredShape(const std::string&, double, double);  // usual three constructors
		CenteredShape();
		CenteredShape(const CenteredShape&);
		double getx() const;
		double gety() const;
		void move(double, double);	// moves the shape, i.e. it modifies it center
};

class RegularPolygon : public CenteredShape { // a regular polygon is a centered_shape with a number of edges
	private: 
		int EdgesNumber;
	public:
		RegularPolygon(const std::string&, double, double, int);
		RegularPolygon();
		RegularPolygon(const RegularPolygon&);
		void setedges(int);
		int getedges() const;
};

class Circle : public CenteredShape {  // a Circle is a shape with a center and a radius
	private:
		double Radius;
	public:
		Circle(const std::string&, double, double, double);
		Circle();
		Circle(const Circle&);
		void changeradius(double);
		double getradius() const;
		double area() const;
		double perimeter() const;
};

class Rectangle : public RegularPolygon{
	private:
		double length;
		double breadth;
	public:
		Rectangle();
		Rectangle(const std::string& name, double x, double y, double length, double breadth);
		Rectangle(const Rectangle&);
		void setlength(double newlength);
		void setbreadth(double newbreadth);
		double getlength() const;
		double getbreadth() const;
		double area() const;
		double perimeter() const;
};
    
class Square : public Rectangle {
	private:
		double side;
	public:
		Square();
		Square(const std::string& name, double x, double y, double sidelength);
		Square(Square& copy);
		void setside(double newside);
		double getside() const;
		double area() const;
		double perimeter() const;
};

#endif
