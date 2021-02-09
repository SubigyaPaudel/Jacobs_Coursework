#include <iostream>
#include "Person.h"

using namespace std;

int main(){
    person *some = new person[3];
    double height;
    int age;
    string name;
    cout << "Enter the information about people who are related to eachother" << endl;
    for(int i = 0; i < 3; i++){
        cout << "Enter a person's name" << endl;
        cin >> name;
        some[i].setname(name);
        cout << "Enter " << some[i].getname() << "'s age" << endl;
        cin >> age;
        some[i].setage(age);
        cout << "Enter " << some[i].getname() << "'s height" << endl;
        cin >> height;
        some[i].setheight(height);
    }
    for(int i = 0; i < 3 ; i++){
        switch(i){
            case 0:
                some[0].setrelative(&some[1]);
                break;
            case 1:
                some[1].setrelative(&some[2]);
                break;
            case 2:
                some[2].setrelative(&some[0]);
                break;
        }
    }
    for(int i = 0; i < 3; i++){
        cout << some[i].getname() << "'s info:" << endl;
        cout << "age= " << some[i].getage() << endl;
        cout << "height= " << some[i].getheight() << endl;
        cout << "a relative= " << some[i].getrelative().getname() << endl;
    }
    delete [] some;
    return 0;
}