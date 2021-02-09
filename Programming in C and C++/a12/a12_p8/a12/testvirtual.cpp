#include <iostream>
using namespace std;
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"
const int num_obj = 7;
int main() {
	Area *list[num_obj];						// (1)
	// Here an array of Area pointers is beign created
	int index = 0;								// (2)
	// The index variable - which will later be used to
	// go through the list list above is being initialied to zero
	double sum_area = 0.0;						// (3)
	// Initializing the sum of areas to 0
	double sum_perimeter = 0.0;
	cout << "Creating Ring: ";
	Ring blue_ring("BLUE", 5, 2);				// (4)
	// Here an instance of the Ring class is being created
	// In order to create this object which has been derived from
	// the circle class, which in turn is derived from the area
	// class, the (Parametric) constructors for circle and area will be 
	// called in the order they are specified here.
	cout << "Creating Circle: ";
	Circle yellow_circle("YELLOW", 7);
	cout << "Creating Rectangle: ";
	Rectangle green_rectangle("GREEN",5,6);
	cout << "Creating Circle: ";
	Circle red_circle("RED", 8);
	cout << "Creating Rectangle: ";
	Rectangle black_rectangle("BLACK", 10, 20);
	cout << "Creating Ring: ";
	Ring violet_ring("VIOLET", 100, 5);
	cout << "Creating Square: ";
	Square Orange_Square("Orange", 10);
	list[0] = &blue_ring;						// (5)
	// The pointer of the blue_ring object is bleing stored in
	// the index 0 location of the list array. Since, through inheritance,
	// a ring is also an area object, this should be possible.
	list[1] = &yellow_circle;
	list[2] = &green_rectangle;
	list[3] = &red_circle;
	list[4] = &black_rectangle;
	list[5] = &violet_ring;
	list[6] = &Orange_Square;
	while (index < num_obj) {					// (7)
	//In this loop the getcolor method for each pointer of theobject 
	//stored in the list array is called and the color of the object
	// is displayed on the screen.
		(list[index])->getColor();				
		double area = list[index]->calcArea();// (8)
		// the calcArea of the object whose pointer is stored
		// in the list array on the index value "index" is called and 
		// the value returned by is then stored in the area variable
		sum_area += area;
		double perimeter = (list[index++])->calcPerimeter();
		sum_perimeter += perimeter; 
	}
	cout << "\nThe total area is "<< sum_area << " units " << endl;	// (9)
	// The sum of area of the called the objects whose pointer was stored in
	// the list array is printed on the screen.
	cout << "The total perimeter is" << sum_perimeter << "units" << endl;
	return 0;
}

/*
	   (Class Area)
			|
			|
-----------------------------
|							|
(Class Circle)        (Class Rectangle)
	   |
(Class Ring)



*/