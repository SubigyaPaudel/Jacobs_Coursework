/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p05.c
*/
#include <iostream>
#include "Creature.h"
#include <cstring>

using namespace std;

int main(){
    string response;
    do{
        cout << "Enter a object name" << endl;
        cout << "Available objects: creature, wizard, golem, giant" << endl;
        getline(cin, response);
        if(response == "creature"){
            Creature* p = new Creature;
            *p = Creature();
            p->run();
            delete p;
        }else if(response == "wizard"){
            Wizard* p = new Wizard;
            *p = Wizard();
            p->hover();
            delete p;
        }else if(response == "golem"){
            Golem* p = new Golem;
            *p = Golem();
            p->roll();
            delete p;
        }else if(response == "giant"){
            Giant* p = new Giant;
            *p = Giant();
            p->leap();
            delete p;
        }else{
            if(response != "quit")
                cout << "Invalid input, enter the class again" << endl;
        }
    }while(response != "quit");
    return 0;
}