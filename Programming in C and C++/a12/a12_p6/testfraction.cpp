#include <iostream>
#include "fraction.h"

using namespace std;

int main(void)
{
    Fraction a, b;
	cout << "Enter a fraction" << endl;
    cin >> a;
    cout << "Enter another fraction" << endl;
    cin >> b;
    cout << "Multiplication of the fractions:" << a * b << endl;
    cout << "Division of the fraction:" << a / b << endl;
    return 0;
}
