#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
    private:
        double real;
        double imaginary;
    public:
        Complex(double = 0, double = 0);
        Complex(const Complex&);
        ~Complex();
        double getreal() const;
        double getimaginary() const;
        void setreal(double);
        void setimaginary(double);
        friend bool operator==(const Complex& a, const Complex& b);
};

#endif