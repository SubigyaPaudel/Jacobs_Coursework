/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p07.c
*/

#include "Complex.h"
#include <iostream>

complex::complex(){
    real = 0;
    imaginary = 0;
}

complex::complex(double a, double b){
    setreal(a);
    setimaginary(b);
}

complex::complex(complex& cnumber){
    real = cnumber.real;
    imaginary = cnumber.imaginary;
}

complex::~complex(){
}

complex complex::add(complex b){    // adds complex number b to the complex object
    complex sum;
    sum.real = real + b.real;
    sum.imaginary += imaginary + b.imaginary;
    return sum;
}

void complex::setreal(double a){
    real = a;
}

void complex::setimaginary(double b){
    imaginary = b;
}

double complex::getreal(){
    return real;
}

double complex::getimaginary(){
    return imaginary;
}

void complex::printcomplex(){
    if(imaginary < 0){
      std::cout << real << imaginary << "i" ; //if condition to decide the sign 
                                            //between the real and imaginary parts
    }else if (imaginary > 0){
        std::cout << real << "+" << imaginary << "i" ;
    }else{
        std::cout << real;
    }
}

complex complex::subtract(complex b){   //subtracts complex number b from the complex object
    complex difference;
    difference.real = real- b.real;
    difference.imaginary = imaginary - b.imaginary;
    return difference;
}

complex complex::multiply(complex b){   //multiplies the complex object by complex number b
    complex multiple;
    multiple.real = real * b.real - imaginary * b.imaginary;
    multiple.imaginary = imaginary * b.real + real * b.imaginary;
    return multiple;  
}

complex complex::conjugation(){
    complex result;
    result.real = real;
    result.imaginary = imaginary * -1;
    return result;
}