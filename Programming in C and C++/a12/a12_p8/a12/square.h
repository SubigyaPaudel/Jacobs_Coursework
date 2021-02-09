#include "Area.h"
#include "Rectangle.h"

class Square: public Rectangle{
    private:
        double side;
    public:
        Square(const char* n, double side);
        ~Square();
        double calcArea() const;
        double calcPerimeter() const;
};