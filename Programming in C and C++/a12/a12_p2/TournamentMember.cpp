/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a12_p02.c
*/

#include "TournamentMember.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string Tournamentmember::location = "London";

Tournamentmember::Tournamentmember(){
    cout << "This is the empty constructor" << endl;
    string firstcopy = "John";
    string lastcopy = "Doe";
    string DOBcopy = "01-01-1997";
    for(int i = 0; i < 4; i++)
        firstname[i] = firstcopy[i];
    for(int i = 0; i < 3; i++)
        lastname[i] = lastcopy[i];
    for(int i = 0; i < 11; i++)
        DOB[i] = DOBcopy[i];
    
}

Tournamentmember::Tournamentmember(char* newfirstname, char* newlastname, char* newDOB){
    cout << "This is a parametric constructor" << endl;
    strcpy(this->firstname, newfirstname);
    strcpy(this->lastname, newlastname);
    strcpy(this->DOB, newDOB);
}

Tournamentmember::Tournamentmember(const Tournamentmember& copy){
    cout << "This is a copy constructor" << endl;
    strcpy(this->firstname,copy.firstname);
    strcpy(this->lastname, copy.firstname);
    strcpy(this->DOB, copy.firstname);
}

Tournamentmember::~Tournamentmember(){
    cout << "This is the destructor" << endl;
}

void Tournamentmember::printfinfo(){
    printf("First Name: %s \n",this->getfirstname());
    printf("Last Name: %s \n", this->getlastname());
    printf("Date of Birth: %s", this->getDOB());
}

