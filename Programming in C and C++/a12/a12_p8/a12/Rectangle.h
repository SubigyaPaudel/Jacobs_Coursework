#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Area.h"

class Rectangle : public Area {
	public:
		Rectangle(const char *n, double a, double b);
		~Rectangle();
		virtual double calcArea() const;
		virtual double calcPerimeter() const;
	private:
		double length;
		double width;
};

#endif
