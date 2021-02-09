#ifndef _RING_H
#define _RING_H
#include "Circle.h"

class Ring : public Circle {
	public:
		Ring(const char *n, double outer, double inner);
		~Ring();
		double calcArea() const;
		// a dedicated method for calling perimeter is not immplemented
		// as the methos in circle will calculate the outer boundary of
		// the circle
	private:
		double innerradius;
};

#endif
