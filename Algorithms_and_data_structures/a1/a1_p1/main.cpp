#include <iostream>
#include <cstdlib>
#include "Complex.h"

template <class T>
int array_search(T array[], int n , T thing){
    for(int i = 0; i < n; i++){
        if(array[i] == thing){
            return i;
        }
    }
    return -1;
}

using namespace std;

int main(){
    Complex complex_array[5];
    int int_array[50];
    double double_array[20];
    for(int i = 0; i < 5; i++)
        complex_array[i] = Complex(i, i*i);
    for(int i = 0; i < 50; i++)
        int_array[i] = (50-i)*2;
    for(int i = 1; i < 21; i++)
        double_array[i] = 16.0/i;      
    cout << "In the complex_array, 3+9i is in position " << array_search<Complex>(complex_array, 5, Complex(3,9)) << endl;
    cout << "In the int_array, 45 is in the position " << array_search<int>(int_array, 50, 45) << endl;
    cout << "In the int_array, 16 is in the position " << array_search<int>(int_array, 50, 16) << endl;
    cout << "In the double_array," << 16.0/7.0 << "is in the position " << array_search<double>(double_array, 20, 16.0/7.0) << endl; 
    return 0;
}