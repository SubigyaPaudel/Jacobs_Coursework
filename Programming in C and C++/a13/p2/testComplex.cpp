#include <iostream>
#include "Complex.h"

using namespace std;

int main(){
    complex c1, c2, result;
    string filename, filename2;
    cout << "Enter the filename" << endl;
    cin >> filename;
    ifstream in(filename.c_str());
    if(!in.good()){
        cout << "error opening file" << endl;
        exit(1);
    }
    cout << "Enter the second file" << endl;
    cin >> filename2;
    ifstream in2(filename2.c_str());
    if(!in.good()){
        cout << "Error opening file" << endl;
        exit(1);
    }
    in >> c1;
    in2 >> c2;
    string name = "Output.txt";
    ofstream out(name.c_str());
    if(!out.good()){
        cout << "error opening the outpur file" << endl;
        exit(1);
    }
    out << "The numbers extracted from the file" << c1 << " and " << c2 << endl;
    cout << "The numbers extracted from the file are:" << c1 << " and " << c2 << endl;
    result = c1 + c2;
    cout << "The sum of the two numbers is:" << result << endl;
    out << "The sum of the two numbers is:" << result << endl;
    result = c1 - c2;
    cout << "The difference of the two numbers is:" << result << endl;
    out << "The difference of the two numbers is:" << result << endl;
    result = c1 * c2;
    cout << "The product of the two numbers is:" << result << endl;
    out << "The product of the two numbers is:" << result << endl;
    cout << "The same output has been printed in Output.txt" << endl; 
    out.close();
    in.close();
    in2.close();
    cout << "Process completed" << endl;
    return 0;
}
