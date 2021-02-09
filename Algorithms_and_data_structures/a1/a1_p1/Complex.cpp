#include "Complex.h"

Complex::Complex(double a, double b){
    real = a;
    imaginary = b;
}

Complex::Complex(const Complex& copy){
    real = copy.real;
    imaginary = copy.imaginary;
}

Complex::~Complex(){
}

void Complex::setreal(double a){
    real = a;
}

void Complex::setimaginary(double b){
    imaginary = b;
}

double Complex::getreal() const{
    return real;
}

double Complex::getimaginary() const{
    return imaginary;
}

bool operator==(const Complex& a, const Complex& b){
    if(b.real==a.real && b.imaginary==a.imaginary){
        return true;
    }else{
        return false;
    }
}