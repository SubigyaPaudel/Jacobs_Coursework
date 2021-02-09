#include "square.h"
#include <iostream>

Square::Square(const char* n, double side): Rectangle(n, side, side){
    this->side = side;
}

Square::~Square(){
}

double Square::calcArea() const{
    std::cout << "calcArea() Square being called..";
    return (side * side);
}

double Square::calcPerimeter() const{
    std::cout << "calcPerimeter() Square being called.."; 
    return (4.0*side);
}
