/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a9_p3.c
*/

#include <iostream>

using namespace std;

float abs (float number){
    if(number < 0 ){
        return (number * (-1));
    }else{
        return number;
    }       
}

int main(){
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << "The absolute value is " << abs (n) << endl;
    return 0;
}