#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Complex
{
private:
    float real; // real part
    float imag; // imaginary part
public:
    Complex();
    Complex(float, float = 0);
    double magnitude() const;
    void print();
    friend ofstream& operator<<(const Complex& num, ofstream& file);
    bool operator<(const Complex& num);
    bool operator>(const Complex& num);
};

inline double Complex::magnitude() const
{
    return sqrt(real * real + imag * imag);
}

void Complex::print()
{
    if (imag)
        cout << noshowpos << real << showpos << imag << "i" << endl;
    else
        cout << noshowpos << real << endl;
}

Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex::Complex(float a, float b)
{
    real = a;
    imag = b;
}

bool Complex::operator<(const Complex& num){
    return (this->magnitude() < num.magnitude());
}

bool Complex::operator>(const Complex& num){
    return (this->magnitude() > num.magnitude());
}

ofstream& operator<<(const Complex& num, ofstream& file){
    if(num.imag > 0){
        file << num.real << "+" << num.imag;
    }else if(num.imag < 0){
        file << num.real << num.imag;
    }else{
        file << num.real;
    }
    return file;
}

int main(void){
    Complex a(1);
    Complex b(2,3);
    Complex c;
    if(a < b){
        cout << a << endl;
    }else{
        cout << b << endl;
    }
    cout << "And the complex number c is " << c;
}
