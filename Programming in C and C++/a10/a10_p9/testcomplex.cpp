/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p09.c
*/

#include <iostream>
#include <cstring>
#include "Complex.h"

using namespace std;

int main(){
    complex numbers[2];   // an array to store the complex objects
    double values[2][2];       // an array to store the inputs
    for(int i = 0; i <=1; i++){
        cout << "For complex number"<< i << endl;
        cout << "Enter the real part"<< i << endl;
        cin >> values[i][0];
        numbers[i].setreal(values[i][0]);
        cout << "Enter the imaginary part" << endl;
        cin >> values[i][1];
        numbers[i].setimaginary(values[i][1]);
    }
    cout << "Conjugate of the first complex number:";
    numbers[0].conjugation().printcomplex();       // multiplies the imaginary part by -1 to get its conjugate
    cout << endl << "Sum of the complex numbers: ";
    numbers[0].add(numbers[1]).printcomplex();
    cout << endl << "Difference of the second number and the first: ";
    numbers[1].subtract(numbers[0]).printcomplex();
    cout << endl << "Product of the numbers: ";
    numbers[0].multiply(numbers[1]).printcomplex();
    cout << endl;
    return 0;
}