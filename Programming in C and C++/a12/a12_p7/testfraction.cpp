#include <iostream>
#include "fraction.h"

using namespace std;

int main(void)
{
    Fraction a, b;
    cout << "Enter the first fraction" << endl;
    cin >> a;
    cout << "Enter the second fraction" << endl;
    cin >> b;
	if(a > b){
        cout << a << "is greater than" << b << endl;
    }else if(b > a){
        cout << b << "is greater than a" << endl;
    }else{
        cout << "Both fractions are equal" << endl;
    }
    cout << "Addition of the fractions: " << a + b << endl;
    cout << "Difference of the fractions: " << a - b << endl;
    return 0;
}
