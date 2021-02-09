/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a9_p8.c
*/

#include <iostream>

using namespace std;

void swapping (int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

void swapping (float &a, float &b){
    float c = a;
    a = b;
    b = c;
}

void swapping (const char* &a, const char* &b){
    const char* c = a;
    a = b;
    b = c;
}

int main(void){
    int a = 7, b = 15;
    float x = 3.5 ,y = 9.2;
    const char *str1 = "One";
    const char *str2 = "Two";
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    swapping(a, b);
    swapping(x, y);
    swapping(str1, str2);  
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    return 0;
} 