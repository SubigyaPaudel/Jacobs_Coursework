/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a12_p03.c
*/

#include <string>
#include <cstring>

using namespace std;

class Tournamentmember{
    private:
        char firstname[36];
        char lastname[36];
        char DOB[11]; //DOB is an acronym for date of birth
        static string location;
    public:
        Tournamentmember();
        Tournamentmember(const char* firstname, const char* lastname, const char* DOB);
        Tournamentmember(const Tournamentmember& copy);
        ~Tournamentmember();
        char* getfirstname() {return firstname;}
        char* getlastname() {return lastname;}
        char* getDOB() {return DOB;}
        void setfirstname(const char* firstname);
        void setlastname(const char* lastname);
        void setDOB(const char* DOB);
        void printfinfo();
        static void setlocation(const string newlocation) {location = newlocation;}
        string getlocation() {return location;}       
};

inline void Tournamentmember::setfirstname(const char* newfirstname){
    strcpy(firstname,newfirstname);
}

inline void Tournamentmember::setlastname(const char* newlastname){
    strcpy(lastname,newlastname);
}

inline void Tournamentmember::setDOB(const char* newDOB){
    strcpy(DOB,newDOB);
}

class Player: public Tournamentmember{
    private:
        int number;
        string position;
        int goals;
        string footedness;
    public:
        Player();
        Player(char* firstname, char* secondname, char* DOB, int number, int goals, string position, string footedness);
        Player(const Player& copy);
        ~Player();
        void setnumber(int num);
        void setposition(const string& position);
        void setfootedness(const string& foot);
        int getnumber() const;
        string getposition() const;
        string getfootedness() const;
        int getgoals() const;
        void goalsplusplus();
        void printinfo();
};

inline void Player::setnumber(int num){
    number = num;
}

inline void Player::setposition(const string& position){
    this->position = position;
}

inline void Player::setfootedness(const string& footedness){
    this->footedness = footedness;
}

inline int Player::getnumber() const{
    return number;
}

inline int Player::getgoals() const{
    return goals;
}

inline string Player::getfootedness() const{
    return footedness;
}

inline string Player::getposition() const{
    return position;
}

