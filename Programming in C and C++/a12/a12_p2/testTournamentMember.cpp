/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a12_p02.c
*/

#include <iostream>
#include "TournamentMember.h"
#include <string>
#include <cstring>

using namespace std;

int main(){
    char firstname[36];
    char lastname[36];
    char DOB[11];
    Tournamentmember a;
    a.setlocation("London");
    cout << "First Name?" << endl;
    fgets(firstname, sizeof(firstname), stdin);
    cout << "Second Name?" << endl;
    fgets(lastname, sizeof(lastname), stdin);
    cout << "Date of Birth" << endl;
    fgets(DOB, sizeof(DOB), stdin);
    Tournamentmember b(firstname, lastname, DOB);
    Tournamentmember c(a);
    cout << "Another first name ?" << endl;
    fgets(firstname, sizeof(firstname), stdin);
    cout << "Another second name" << endl;
    fgets(lastname, sizeof(lastname), stdin);
    c.setfirstname(firstname);
    c.setlastname(lastname);
    c.setDOB(DOB);
    a.printfinfo();
    cout << endl;
    b.printfinfo();
    cout << endl;
    c.printfinfo();
    cout << endl;
    c.setlocation("Hamburg");
    cout << "Location: " << b.getlocation() << endl;
    return 0;
}