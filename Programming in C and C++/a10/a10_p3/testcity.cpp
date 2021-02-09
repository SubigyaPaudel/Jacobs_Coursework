/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p03.cpp
*/

#include <iostream>
#include "City.h"

using namespace std;

int main(){
    city some[3];     // creating an array of cities to make the code shorter
    string newname, newmayor;
    double newarea;
    int population;
    for(int i = 0; i <= 2; i++){
        cout << "Name of the city?" << endl;
        cin >> newname;
        some[i].setname(newname);
        cout << "Population?" << endl;
        cin >> population;
        some[i].setpopulation(population);
        cout << "Area?" << endl;
        cin >> newarea;
        some[i].setarea(newarea);
        cout << "Who is the mayor?" << endl;
        cin >> newmayor;
        some[i].setmayor(newmayor);
    }
    for(int i = 0; i <= 2; i++){
        cout << "The name of the city is " << some[i].getname() << endl;
        cout << "It has the population of " << some[i].getpopulation() << endl;
        cout << "It has the area of " << some[i].getarea() << endl;
        cout << some[i].getmayor() << " is the mayor of the city" << endl;
    }
    return 0;
}