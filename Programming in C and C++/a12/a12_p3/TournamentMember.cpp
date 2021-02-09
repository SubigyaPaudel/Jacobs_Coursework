/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a12_p03.c
*/

#include "TournamentMember.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string Tournamentmember::location = "London";

Tournamentmember::Tournamentmember(){
    cout << "This is the Tournamentmember empty constructor" << endl;
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

Tournamentmember::Tournamentmember(const char* newfirstname, const char* newlastname, const char* newDOB){
    cout << "This is a Tournamentmember parametric constructor" << endl;
    strcpy(this->firstname, newfirstname);
    strcpy(this->lastname, newlastname);
    strcpy(this->DOB, newDOB);
}

Tournamentmember::Tournamentmember(const Tournamentmember& copy){
    cout << "This is a Tournamentmember copy constructor" << endl;
    strcpy(this->firstname,copy.firstname);
    strcpy(this->lastname, copy.lastname);
    strcpy(this->DOB, copy.DOB);
}

Tournamentmember::~Tournamentmember(){
    cout << "This is the Tournamentmember destructor" << endl;
}

void Tournamentmember::printfinfo(){
    printf("First Name: %s \n",this->getfirstname());
    printf("Last Name: %s \n", this->getlastname());
    printf("Date of Birth: %s \n", this->getDOB());
}

Player::Player(): Tournamentmember(){
    cout << "This is the Player empty constructor" << endl;
    position = "Unknown";
    number = 0;
    goals = 0;
    footedness = "Unknown";
}

Player::Player(char* firstname, char* secondname, char* DOB, int number,int goals,
string position, string footedness) : Tournamentmember(firstname, secondname, DOB){
    cout << "This is the Player parametric constructor" << endl;
    this->number = number;
    this->goals = goals;
    this->position = position;
    this->footedness = footedness;
}

Player::Player(const Player& copy) : Tournamentmember(copy){
    cout << "This is the Player copy constructor" << endl;
    this->number = copy.number;
    this->position = copy.position;
    this->goals = copy.goals;
    this->footedness = copy.footedness;
}

Player::~Player(){
    cout << "This is the Player destructor" << endl;
}

void Player::goalsplusplus(){
    goals++;
}

void Player::printinfo(){
    this->printfinfo();
    cout << "Number: " << number << endl;
    cout << "Goals: " << goals << endl;
    cout << "Position: "<< position << endl;
    cout << "Footedness: " << footedness << endl;
}