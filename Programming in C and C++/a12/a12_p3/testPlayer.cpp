/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a12_p03.c
*/


#include <iostream>
#include "TournamentMember.h"

using namespace std;


int main(){ 
    Player a;
    char firstname[36];
    char secondname[36];
    char DOB[11];
    int number, goals;
    string position, footedness;
    cout << "Enter a Player's first name" << endl;
    gets(firstname);
    cout << "Enter the Player's second name" << endl;
    gets(secondname);
    cout << "Enter the Player's Date of Birth" << endl;
    gets(DOB);
    cout << "Enter the Player's number" << endl;
    cin >> number;
    getchar();
    cout << "Enter the goals that the number has made" << endl;
    cin >> goals;
    getchar();
    cout << "Enter the player's position" << endl;
    getline(cin, position);
    cout << "Enter the player's footedness" << endl;
    getline(cin,footedness);
    Player b(firstname, secondname, DOB, number, goals, position, footedness);
    Player c(a);
    a.setlocation("Hamburg");
    a.goalsplusplus();
    b.goalsplusplus();
    c.goalsplusplus();
    a.setfirstname(firstname);
    a.setlastname(secondname);
    a.printinfo();
    b.printinfo();
    c.printinfo();
    cout << "Location: " << a.getlocation() << endl;
    return 0;
}