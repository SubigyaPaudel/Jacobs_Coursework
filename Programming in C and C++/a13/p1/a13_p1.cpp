/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a13_p01.c
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    char buffer[100];
    string filename;
    cout << "Enter a filename" << endl;
    cin >> filename;
    int pos = filename.find(".");
    ifstream in(filename.c_str());
    if(!in.good()){
        cout << "Error opening the file" << endl;
        exit(1);
    }
    ofstream out((filename.insert(pos,"_copy")));
    while(!in.eof()){
        in.getline(buffer,100);
        out << buffer << endl;
    }
    in.close();
    out.close();
    cout << "Copy created as " << filename << endl;
    return 0;
}
