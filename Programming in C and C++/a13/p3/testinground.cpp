#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int number;
    string filename;
    ifstream* files;
    cout << "Number of files" << endl;
    cin >> number;
    files = new ifstream[number];
    for(int i = 0; i < number; i++){
        cout << "Enter the name of the file" << endl;
        cin >> filename;
        files[i].open(filename,ios_base::binary);
        if(files[i].badbit){
            cout << "Error opening file" << endl;
            exit(1);
        }
    for(int i = 0; i < number; i++)
        files[i].close();
    }
    return 0;
}