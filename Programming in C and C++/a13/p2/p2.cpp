/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a13_p01.c
*/

#include <iostream>
#include <fstream>
#include "Complex.h"

using namespace std;



int main(){
    string filename1;
    string filename2;
    string outputfile = "output";
    complex result;
    complex input1;
    complex input2;
    cout << "Enter the filename of the input file with extension" << endl;
    cin >> filename1;
    ifstream in1(filename1.c_str());
    if(!in1.good()){
        cout << "Error opening file" << endl;
        exit(1);
    }
    in1 >> input1;
    cout << "Enter the filename of the input file with extension" << endl;
    cin >> filename2;
    ifstream in2(filename2.c_str());
    if(!in2.good()){
        cout << "Error opening file" << endl;
        exit(1);
    }
    in2 >> input2;
    ofstream out(outputfile.c_str());
    if(!in2.good()){
        cout << "Error opening output file" << endl;
        exit(1);
    }
    result = input1 + input2;
    cout << "The sum of the complex numbers is" << result;
    out << "The sum of the complex numbers is" << result;
    result = input1 - input2;
    cout << "The difference of the complex numbers is" << result;
    out << "The difference of the complex numbers is" << result;
    result = input1 * input2;
    cout << "The product of the complex numbers is" << result;
    out << "The product of the complex numbers is" << result;
    in1.close();
    in2.close();
    out.close();
    return 0;
}

