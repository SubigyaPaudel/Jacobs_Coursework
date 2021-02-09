#include "Complex.h"

complex::complex(){
    real = 0;
    imaginary = 0;
}

complex::complex(double a, double b){
    real = a;
    imaginary = b;
}

std::istream& operator>>(std::istream& in, complex& c){
    in >> c.real;
    getchar();
    in >> c.imaginary;
    return in;
}

std::ostream& operator<<(std::ostream& out, const complex& c){
    if(c.imaginary > 0)
        out << c.real << '+' << c.imaginary << 'i';
    else if(c.imaginary < 0)
        out << c.real << c.imaginary << 'i';
    else
        out << c.real;
    return out;
}

complex operator+(complex& a, complex& b){
    double newreal = a.real + b.real;
    double newimaginary = a.imaginary + b.imaginary;
    return complex(newreal, newimaginary);
}

complex operator-(complex& a, complex& b){
    double newreal = a.real - b.real;
    double newimaginary = a.imaginary - b.imaginary;
    return complex(newreal, newimaginary);
}

complex operator*(complex& a, complex& b){
    double newreal = a.real * b.real - a.imaginary * b.imaginary;
    double newimaginary = a.imaginary * b.real + a.real * b.imaginary;
    return complex(newreal, newimaginary); 
}

void complex::operator=(const complex& a){
    this->real = a.getreal();
    this->imaginary = a.getimaginary();
}
