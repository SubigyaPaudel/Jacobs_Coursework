#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, string> name_birthday;
    map<string,string>::iterator pos;
    string name, fname, lname, birthday, enter;
    ifstream readfile("data.txt");
    if(readfile.bad()){
        cerr << "Error opening the file" << endl;
        exit(1);
    }
    readfile.seekg(ios::beg);
    while(!readfile.eof()){
        readfile >> fname >> lname >> birthday;
        name = fname + " " + lname;
        cout << name << ":" << birthday << endl;
        name_birthday[name] = birthday;
    }
    while(true){
        cout << "Enter the name of the person whose birthday you want to find out" << endl;
        cout << "Type 'END' to exit this session" << endl;
        getline(cin, enter);
        if(enter == "END"){
            break;
        }else{
            pos = name_birthday.find(enter);
            if(pos == name_birthday.end())
                cout << "The person that you are searching for is not in the database" << endl;
            else{
                cout << enter << "'s birthday is on " << pos->second << endl;
            }
        }
    }
    return 0;
}