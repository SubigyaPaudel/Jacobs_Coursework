/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a12_p02.c
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
        Tournamentmember(char* firstname, char* lastname, char* DOB);
        Tournamentmember(const Tournamentmember& copy);
        ~Tournamentmember();
        char* getfirstname();
        char* getlastname();
        char* getDOB();
        void setlocation(string& location);
        void setfirstname(const char* firstname);
        void setlastname(const char* lastname);
        void setDOB(const char* DOB);
        void printfinfo();
        static void setlocation(const string newlocation) {location = newlocation;}
        static string getlocation() {return location;}
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

inline char* Tournamentmember::getfirstname(){
    return firstname;
}

inline char* Tournamentmember::getlastname(){
    return lastname;
}

inline char* Tournamentmember::getDOB(){
    return DOB;
}
