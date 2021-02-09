#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main(){
    char *buffer;
    int number;
    string filename;
    cout << "Enter the number of files" << endl;
    cin >> number;
    ifstream* files= new ifstream[number];
    for(int i =0 ; i < number; i++){
        cout << "Enter the name of file " << (i+1) << endl;
        cin >> filename;
        files[i].open(filename.c_str(),ios::binary|ios::in);
        if(!files[i].good()){
            cout << "Error opening file" << endl;
            exit(1);
        }
    }
    ofstream output;
    string outname = "concatn.txt";
    output.open(outname.c_str(),ios::binary|ios::out);
    for(int i =0; i < number; i++){
        int pos = 0;
        files[i].seekg(0, ios::end);
        pos = files[i].tellg();
        buffer = new char[pos + 1];
        files[i].seekg(0, ios::beg);
        files[i].read(buffer, pos);
        buffer[pos] = '\n';
        output.write(buffer, pos+1);
        delete[] buffer;
    }
    for(int i =0; i < number; i++)
        files[i].close();
    delete [] files;
    output.close();
    return 0;
}