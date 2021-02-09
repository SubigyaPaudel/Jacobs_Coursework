#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <fstream>

class complex{
    private:
        double real;
        double imaginary;
    public:
        complex();
        complex(double, double);
        double getreal() const{return real;}
        double getimaginary() const{return imaginary;}
        void setreal(double real) {this->real = real;}
        void setimaginary(double imaginary){this->imaginary = imaginary;}
        friend complex operator+(complex& a, complex& b);
        friend complex operator-(complex& a, complex& b);
        friend complex operator*(complex& a, complex& b);
        friend std::istream& operator>>(std::istream& in, complex& c);
        friend std::ostream& operator<<(std::ostream& out, const complex& c);
        void operator=(const complex& a); 
};

#endif