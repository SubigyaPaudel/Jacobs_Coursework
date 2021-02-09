/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a9_p4.c
*/

#include <iostream>
#include <cstring>

using namespace std;

int mycount(int a, int b){
    return (b-a);
}

int mycount(char a, string s){
    int counter = 0;
    int upto = s.length() -1;
    for (int i = 0; i <= upto; i++){
        if(s[i] == a)
            counter++;
    }
    return counter;
}

int main(){
    string s;
    int a, b;
    char c;
    cout << "Enter two numbers" << endl;
    cin >> a >> b;
    cout << mycount(a,b) << endl; // mycount called for integers
    cout << "Enter a character and a string" << endl;
    cin >> s;
    cin >> c;
    cout << mycount(c, s) << endl; // mycount called for a char and a string
}